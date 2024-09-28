#include <iostream>
#include <fstream>
using namespace std;


const string DB_FILENAME = "produto.txt";
const int prodMax = 80; // Número máximo de produtos

// Estrutura para armazenar informações do produto
struct Produto {
    int id;
    string nome;
    int quantidade;
    float preco;
    char status; // 'A' para ativo, 'D' para eliminado
};

// Função para carregar produtos do arquivo
void loadProdutos(Produto produtos[], int& quantidadeAtual, const string& filename) {
    ifstream file(DB_FILENAME);
    if (!file) return; // Se o arquivo não existir, sai da função

    while (file >> produtos[quantidadeAtual].id >> ws) {
        getline(file, produtos[quantidadeAtual].nome, ',');
        file >> produtos[quantidadeAtual].quantidade >> produtos[quantidadeAtual].preco >> produtos[quantidadeAtual].status;
        quantidadeAtual++;
    }
    file.close(); // Fecha o arquivo
}

// Função para salvar produtos no arquivo
void saveProdutos(const Produto produtos[], int quantidadeAtual, const string& filename) {
    ofstream file(DB_FILENAME);
    for (int i = 0; i < quantidadeAtual; i++) {
        file << produtos[i].id << "," << produtos[i].nome << "," << produtos[i].quantidade << "," 
             << produtos[i].preco << "," << produtos[i].status << endl;
    }
    file.close(); // Fecha o arquivo
}

// Função para adicionar um novo produto
void addProduto(Produto produtos[], int& quantidadeAtual) {
    if (quantidadeAtual >= prodMax) {
        cout << "----------------------------------------" << endl;
        cout << "Atingiu o limite máximo de produtos." << endl;
        return;
    }

    Produto newProduct;
    newProduct.status = 'A'; // Define status como ativo

    // Gera um novo ID
    newProduct.id = (quantidadeAtual == 0) ? 1 : produtos[quantidadeAtual - 1].id + 1;

    cout << "----------------------------------------" << endl;
    cout << "Insira o nome do produto: ";
    cin.ignore(); // Limpa o buffer
    getline(cin, newProduct.nome);
    cout << "----------------------------------------" << endl;
    cout << "Insira o preço do produto: ";
    cin >> newProduct.quantidade;
    cout << "----------------------------------------" << endl;
    cout << "Insira a quantidade do produto: ";
    cin >> newProduct.preco;

    produtos[quantidadeAtual] = newProduct; // Adiciona o novo produto à lista
    quantidadeAtual++;
    saveProdutos(produtos, quantidadeAtual, "produtos.txt"); // Salva os produtos no arquivo
    system("clear");
    cout << "----------------------------------------" << endl;
    cout << "Produto adicionado com sucesso." << endl;
}

float calcularValorTotal(const Produto produtos[], int quantidadeAtual){

    float valorTotal = 0.0;

    for(int x=0; x<quantidadeAtual; x++){
        valorTotal += produtos[x].preco * produtos[x].quantidade;
    }

    return valorTotal;
}


// Função para consultar produtos
void consultarProdutos(const Produto produtos[], int quantidadeAtual){

    char opcao;
    if(quantidadeAtual == 0){
        cout << "----------------------------------------" << endl;
        cout << "Sem produtos adicionados." << "\nVoltando ao menu..." << endl;
        return;

    } else{

        cout << "------------------------------------------------------------------" << endl;
        cout << "Quer consultar os produtos ativos(A), deletados(D) ou todos(T)? ";
        cin >> opcao;
        system("clear");

        if(opcao == 'A'){

            cout << "-----------------------------------------" << endl;
            cout << "       Lista de produtos ativos" << endl; 
            for(int a = 0; a < quantidadeAtual; a++){

                if(produtos[a].status == 'A'){ // o if verifica se o status do produto indice a for A, indica que esta ativo

                    cout << "-----------------------------------------" << endl;
                    cout << "ID: " << produtos[a].id << endl;
                    cout << "Nome: " << produtos[a].nome << endl;
                    cout << "Preço: " << produtos[a].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[a].quantidade << endl;
                    cout << "Status: " << produtos[a].status << endl;

                }
            }
        }

        if(opcao == 'D'){

            cout << "----------------------------------------" << endl;
            cout << "      Lista de produtos deletados" << endl; 
            for(int d = 0; d < quantidadeAtual; d++){

                if(produtos[d].status == 'D'){ // o if verifica se o status do produto indice d for D, indica que esta deletado

                    cout << "----------------------------------------" << endl;
                    cout << "ID: " << produtos[d].id << endl;
                    cout << "Nome: " << produtos[d].nome << endl;
                    cout << "Preço: " << produtos[d].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[d].quantidade << endl;
                    cout << "Status: " << produtos[d].status << endl;

                }
            }
        }

        if(opcao == 'T'){

            cout << "---------------------------------------" << endl;
            cout << "      Lista de todos os produtos" << endl; 
            for(int t=0; t<quantidadeAtual; t++){
                cout << "---------------------------------------" << endl;
                cout << "ID: " << produtos[t].id << endl;
                cout << "Nome: " << produtos[t].nome << endl;
                cout << "Preço: " << produtos[t].preco << "€" << endl;
                cout << "Quantidade: " << produtos[t].quantidade << endl;
                cout << "Status: " << produtos[t].status << endl;                                                                                         

            }
        }
    }
}

// Função para alterar um produto
void alterarProduto(Produto produtos[], int quantidadeAtual) {
    int id;
    cout << "----------------------------------------" << endl;
    cout << "Insira o ID do produto a alterar: ";
    cin >> id;
    system("clear");

    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].id == id && produtos[i].status == 'A') {
            cout << "----------------------------------------" << endl;
            cout << "Insira o novo nome do produto: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, produtos[i].nome);
            cout << "----------------------------------------" << endl;
            cout << "Insira a nova quantidade do produto: ";
            cin >> produtos[i].quantidade;
            cout << "----------------------------------------" << endl;
            cout << "Insira o novo preço do produto: ";
            cin >> produtos[i].preco;
            saveProdutos(produtos, quantidadeAtual, "produtos.txt"); // Salva as alterações no arquivo
            system("clear");
            cout << "----------------------------------------" << endl;
            cout << "Produto alterado com sucesso." << endl;
            return;
        }
    }
    cout << "Produto não encontrado ou já eliminado." << endl;
}

// Função para eliminar um produto
void eliminarProduto(Produto produtos[], int quantidadeAtual) {
    int id;
    cout << "Insira o ID do produto a eliminar: ";
    cin >> id;

    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].id == id) {
            produtos[i].status = 'D'; // Define o status como eliminado
            saveProdutos(produtos, quantidadeAtual, "produtos.txt"); // Salva as alterações no arquivo
            cout << "Produto eliminado com sucesso." << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

// Função para exibir o menu
void showMenu() {

    cout << "----------------------------------------" << endl;
    cout << "                  MENU" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1 - Adicionar Produto " << endl;
    cout << "2 - Calcular Valor Total do Stock " << endl;
    cout << "3 - Consultar Produtos " << endl;
    cout << "4 - Alterar Produto " << endl;
    cout << "5 - Eliminar Produto " << endl;
    cout << "6 - Salvar Produto " << endl;
    cout << "0 - Sair " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Digite a sua opção: ";
}

void executaOpcao(){

Produto produtos[prodMax];
int quantidadeAtual = 0;
int escolha;
loadProdutos(produtos, quantidadeAtual, "produtos.txt"); // Carrega produtos do arquivo

    do {
        showMenu(); // Mostra o menu
        cin >> escolha; // Lê a escolha do usuário

        system("clear");

        switch (escolha) {
        case 1:
            addProduto(produtos, quantidadeAtual); // Adiciona um produto
            break;
        case 2:
            cout << "----------------------------------------" << endl;
            cout << "O valor total em stock é: " << calcularValorTotal(produtos, quantidadeAtual) << "€" << endl;
            break;
        case 3:
            consultarProdutos(produtos, quantidadeAtual); // Consulta produtos
            break;
        case 4:
            alterarProduto(produtos, quantidadeAtual); // Altera um produto
            break;
        case 5:
            eliminarProduto(produtos, quantidadeAtual); // Elimina um produto
            break;
        case 6:
            saveProdutos(produtos, quantidadeAtual, "listaProdutos.txt");
            break;
        case 0:
            cout << "A sair do programa..." << endl; // Mensagem de saída
            break;
        default:
            cout << "Opção inválida! Voltando ao menu..." << endl; // Mensagem de erro
        }

    } while (escolha != 0); // Repete até que o usuário escolha sair
}

// Função principal que executa o programa
int main() {

    system("clear");
    executaOpcao();

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
