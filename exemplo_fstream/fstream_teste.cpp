#include <iostream>
#include <fstream> 
using namespace std;

const string DBfile = "lista.txt"; // Ficheiro de persistência
const int prodMax = 80; // Número máximo de produtos

struct Produto { // Struct Produto
    int id;
    string nome;
    float preco;
    int quantidade;
    char status;
};

// Função para carregar produtos do ficheiro
void loadProd(Produto produtos[], int& quantidadeAtual, const string& DBfile) {
    ifstream file(DBfile); // Abre o ficheiro para leitura
    if (!file) return; // Se não conseguir abrir, retorna sem fazer nada

    while(file >> produtos[quantidadeAtual].id) { 
        file.ignore(); // Ignora o caractere de nova linha após o ID
        getline(file, produtos[quantidadeAtual].nome, ','); // Lê o nome até a vírgula
        file >> produtos[quantidadeAtual].preco >> produtos[quantidadeAtual].quantidade >> produtos[quantidadeAtual].status;
        quantidadeAtual++; // Incrementa o contador de produtos
    }
    file.close(); // Fecha o ficheiro
}

// Função para salvar produtos no ficheiro
void saveProd(const Produto produtos[], int quantidadeAtual, const string& DBfile) {
    ofstream file(DBfile); // Abre o ficheiro para escrita
    for(int x = 0; x < quantidadeAtual; x++) { // Escreve todos os produtos
        file << produtos[x].id << "," << produtos[x].nome << "," << produtos[x].preco << ","
             << produtos[x].quantidade << "," << produtos[x].status << endl;
    }
    file.close(); // Fecha o ficheiro
}

// Função para consultar produtos
void consultProd(const Produto produtos[], int quantidadeAtual) {
    char opcao;
    if(quantidadeAtual == 0) {
        cout << "-----------------------------------------------" << endl;
        cout << "Sem produtos adicionados." << "\nVoltando ao menu..." << endl;
        return;
    } else {
        cout << "Quer consultar os produtos ativos(A), eliminados(E) ou todos(T)? ";
        cin >> opcao;
        system("clear");
        if(opcao == 'A') {
            cout << "Lista de produtos ativos" << endl;
            for(int a = 0; a < quantidadeAtual; a++) {
                if(produtos[a].status == 'A') {
                    cout << "ID: " << produtos[a].id << endl;
                    cout << "Nome: " << produtos[a].nome << endl;
                    cout << "Preço: " << produtos[a].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[a].quantidade << endl;
                }
            }
        } else if(opcao == 'E') {
            cout << "Lista de produtos eliminados" << endl;
            for(int e = 0; e < quantidadeAtual; e++) {
                if(produtos[e].status == 'E') {
                    cout << "ID: " << produtos[e].id << endl;
                    cout << "Nome: " << produtos[e].nome << endl;
                    cout << "Preço: " << produtos[e].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[e].quantidade << endl;
                }
            }
        } else if(opcao == 'T') {
            cout << "Lista de todos os produtos" << endl;
            for(int t = 0; t < quantidadeAtual; t++) {
                cout << "ID: " << produtos[t].id << endl;
                cout << "Nome: " << produtos[t].nome << endl;
                cout << "Preço: " << produtos[t].preco << "€" << endl;
                cout << "Quantidade: " << produtos[t].quantidade << endl;
                cout << "Status: " << produtos[t].status << endl;
            }
        }
    }
}

// Função para adicionar um novo produto
void addProduto(Produto produtos[], int& quantidadeAtual) {
    if(quantidadeAtual >= prodMax) {
        cout << "Atingiu o limite máximo de produtos." << endl;
        return;
    } else {
        Produto newProduct; // Cria um novo produto
        newProduct.status = 'A'; // Define como ativo

        if(quantidadeAtual == 0) { // Se for o primeiro produto
            newProduct.id = 1;
        } else {
            newProduct.id = produtos[quantidadeAtual - 1].id + 1;
        }

        cout << "Insira o nome do produto: ";
        cin.ignore();
        getline(cin, newProduct.nome);

        cout << "Insira o preço do produto: ";
        cin >> newProduct.preco;

        cout << "Insira a quantidade do produto: ";
        cin >> newProduct.quantidade;

        produtos[quantidadeAtual] = newProduct; // Adiciona o novo produto ao array
        quantidadeAtual++;

        saveProd(produtos, quantidadeAtual, DBfile); // Salva o produto automaticamente
        system("clear");
        cout << "O produto foi adicionado." << endl;
    }
}

// Função para mudar os produtos
void changeProd(Produto produtos[], int quantidadeAtual) {
    int id; // Declaração de uma variável inteira id
    cout << "Insira o ID do produto que deseja alterar: "; 
    cin >> id; // Solicita ao usuário que insira o id para alterar e o valor vai ser armazenado na variável id
    system("clear");

    for(int y = 0; y < quantidadeAtual; y++) { // Percorre todos os produtos do array
        if(produtos[y].id == id && produtos[y].status == 'A') { // Verifica o id e se o status é A
            cout << "Insira o novo nome do produto: ";
            cin.ignore(); // Limpa o buffer de entrada
            getline(cin, produtos[y].nome); // Permite ler o nome completo do produto
            cout << "Insira o novo preço do produto: ";
            cin >> produtos[y].preco;
            cout << "Insira a nova quantidade do produto: ";
            cin >> produtos[y].quantidade;

            saveProd(produtos, quantidadeAtual, DBfile); // Salva as alterações no ficheiro
            system("clear");
            cout << "Produto alterado com sucesso." << endl;
            return;
        }
    }
    cout << "Produto não foi encontrado ou já foi eliminado." << endl;
}

// Função para eliminar produtos
void eliminateProd(Produto produtos[], int quantidadeAtual) {
    int id;
    cout << "Insira o ID do produto que deseja eliminar: ";
    cin >> id;

    for(int w = 0; w < quantidadeAtual; w++) {
        if(produtos[w].id == id) {
            produtos[w].status = 'E'; // Define o status como eliminado
            saveProd(produtos, quantidadeAtual, DBfile); // Salva as alterações no ficheiro
            cout << "Produto eliminado com sucesso!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

// Função que calcula o valor do preço total dos produtos
float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {
    float valorTotal = 0.0;

    for(int x = 0; x < quantidadeAtual; x++) {
        valorTotal += produtos[x].preco * produtos[x].quantidade;
    }

    return valorTotal;
}

// Função que mostra o menu
void showMenu() {
    cout << "-----------------------------------------------" << endl;
    cout << "                     MENU" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1 - Adicionar Produtos " << endl;
    cout << "2 - Calcular Valor Total do Stock " << endl;
    cout << "3 - Consultar Produtos " << endl;
    cout << "4 - Alterar Produto " << endl;
    cout << "5 - Eliminar Produto " << endl;
    cout << "0 - Sair " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Digite a sua opção: ";
}

// Função para executar as opções do menu
void executaOpcao() {
    Produto produtos[prodMax];
    int quantidadeAtual = 0;
    int escolha;

    // Carrega produtos do ficheiro ao iniciar o programa
    loadProd(produtos, quantidadeAtual, DBfile); 

    do {
        showMenu(); // Exibe o menu
        cin >> escolha;
        system("clear");

        switch (escolha) {
        case 1:
            addProduto(produtos, quantidadeAtual); // Adiciona um produto
            break;
        case 2:
            cout << "O valor total em stock é: " << calcularValorTotal(produtos, quantidadeAtual) << "€" << endl;
            break;
        case 3:
            consultProd(produtos, quantidadeAtual); // Consulta produtos
            break;
        case 4:
            changeProd(produtos, quantidadeAtual); // Altera um produto
            break;
        case 5:
            eliminateProd(produtos, quantidadeAtual); // Elimina um produto
            break;
        case 0:
            // Salva automaticamente ao sair
            saveProd(produtos, quantidadeAtual, DBfile);
            cout << "A sair do programa..." << endl;
            break;
        default:
            cout << "Opção inválida! Voltando ao menu..." << endl;
        }
    } while (escolha != 0); // Continua até o usuário escolher sair
}

int main() {
    system("clear");
    executaOpcao(); // Executa o menu de opções
    return 0;
}
