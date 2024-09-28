#include <iostream> //Declara objetos que controlam a leitura e a gravação nos fluxos padrão. Essa inclusão é geralmente o único cabeçalho necessário para executar a entrada e a saída de um programa C++
#include <fstream> //Define várias classes que dão suporte a operações de iostreams em sequências armazenadas em focheiros externos
using namespace std; //usado para o compilador perceber que sempre que utilizarmos funcoes e objetos da biblioteca padrao em c++ como outputs e inputs e a delcaracao de variaveis do tipo string, nao seja preciso usar ::std

const string DBfile = "lista.txt"; //é uma constante que armazena o nome de um ficheiro, e esse valor não pode ser alterado durante a execução do programa
const int prodMax = 80; //é uma constante que define a quantidade máxima de produtos que o programa pode gerenciar, nao pode ser alterado tambem

struct Produto{ //struct com atributos id, nome, preco, quantidade e status
    int id;
    string nome;
    float preco;
    int quantidade;
    char status;
};


//funcao para carregar produtos no ficheiro
void loadProd(Produto produtos[], int& quantidadeAtual, const string& DBfile){

    ifstream file(DBfile); //cria um objeto ifstream para abrir o ficheiro 
    if (!file) return; //verifica se o ficheiro foi aberto com sucesso. Se o ficheiro nao existir ou houver erro na abertura volta sem fazer nada

    while(file >> produtos[quantidadeAtual].id){
        getline(file, produtos[quantidadeAtual].nome, ','); //vai ler o nome do produto ate achar uma virgula
        file >> produtos[quantidadeAtual].preco >> produtos[quantidadeAtual].quantidade >> produtos[quantidadeAtual].status;
        //vai ler o preco, a quantidade em sotck e o status do protudo
        quantidadeAtual++; //apos ler os dados de um produto, incrementa-se quantidadeAtual para passar para o proximo produto no array
    }
    file.close(); //fecha o ficheiro
}

//funcao para salvar produtos no ficheiro
void saveProd(const Produto produtos[], int quantidadeAtual, const string& DBfile){

    ofstream file(DBfile); //cria um objeto ofstream para abrir o focheiro. Esse objeto abre o ficheiro para gravacao. Se ja existir o ficheiro ele vai ser sobrescrito
    for(int x = 0; x < quantidadeAtual; x++){ //ciclo for que percorre o array de produtos desdo indice 0 ate quantidadeAtual, salva todos os produtos existentes no array
        file << produtos[x].id << "," << produtos[x].nome << "," << produtos[x].quantidade << "," //para cada produto no array,a funcao escreve os dados
        << produtos[x].preco << "," << produtos[x].status << endl; // << serve para gravar dados no ficheiro
    }
    file.close(); //fecha o ficheiro
}

//funcao para consultar os produtos
void consultProd(const Produto produtos[], int quantidadeAtual){

    char opcao;
    if(quantidadeAtual == 0){
        cout << "----------------------------------------" << endl;
        cout << "Sem produtos adicionados." << "\nVoltando ao menu..." << endl;
        return;

    } else{

        cout << "------------------------------------------------------------------" << endl;
        cout << "Quer consultar os produtos ativos(A), eliminados(E) ou todos(T)? ";
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

        if(opcao == 'E'){

            cout << "----------------------------------------" << endl;
            cout << "      Lista de produtos eliminados" << endl; 
            for(int e = 0; e < quantidadeAtual; e++){

                if(produtos[e].status == 'E'){ // o if verifica se o status do produto indice e for E, indica que esta eliminado

                    cout << "----------------------------------------" << endl;
                    cout << "ID: " << produtos[e].id << endl;
                    cout << "Nome: " << produtos[e].nome << endl;
                    cout << "Preço: " << produtos[e].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[e].quantidade << endl;
                    cout << "Status: " << produtos[e].status << endl;

                }
            }
        }

        if(opcao == 'T'){ // se a opcao for T vai mostrar todos os produtos dos A e os D

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

//funcao para mudar os produtos
void changeProd(Produto produtos[], int quantidadeAtual){

    int id; //declaracao de uma variavel inteira id
    cout << "----------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja alterar: "; 
    cin >> id; //solicita ao usuario que insira o id para alterar e o valor vai ser armazenado na variavel id
    system("clear");

    for(int y = 0; y < quantidadeAtual; y++){ //vai percorrer todos os produtos do array, procurando um produto com id igual ao valor de id inserido

        if(produtos[y].id == id && produtos[y].status == 'A'){ //verifica o id o que garante que tenha status A. Impedindo que produtos D sejam alterados

            cout << "----------------------------------------" << endl;
            cout << "Insira o novo nome do produto: ";
            cin.ignore(); // limpa o buffer de entrada para evitar que os restos de entradas anteriores interfiram no uso do getline
            getline(cin, produtos[y].nome); //permite ler o nome completo do produto, incluindo espacos
            cout << "----------------------------------------" << endl;
            cout << "Insira o novo preço do produto: ";
            cin >> produtos[y].preco;
            cout << "----------------------------------------" << endl;
            cout << "Insira a nova quantidade do produto: ";
            cin >> produtos[y].quantidade;

            saveProd(produtos, quantidadeAtual, "lista.txt"); // salva as alterações no ficheiro
            system("clear");
            cout << "----------------------------------------" << endl;
            cout << "Produto alterado com sucesso." << endl;
            return;

        } else{

            cout << "-----------------------------------------------" << endl;
            cout << "Produto nao foi encontrado ou ja foi eliminado." << endl;

        }
    }
}

//funcao para eliminar produtos
void eliminateProd(Produto produtos[], int quantidadeAtual){

    int id;
    cout << "----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja eliminar: ";
    cin >> id;

    for(int w = 0; w < quantidadeAtual; w++){

        if(produtos[w].id == id){

            produtos[w].status = 'E'; // define o status como eliminado
            saveProd(produtos, quantidadeAtual, "lista.txt");

            cout << "----------------------------------------" << endl;
            cout << "Produto eliminado com sucesso!" << endl;
            return;

        } else{

            system("clear");
            cout << "----------------------------------------" << endl;
            cout << "Produto nao encontrado." << endl;

        }
    }
}

void addProduto(Produto produtos[], int& quantidadeAtual){

    if(quantidadeAtual >= prodMax){

        cout << "----------------------------------------" << endl;
        cout << "Atingiu o limite máximo de produtos." << "\nNão é possível adicionar mais produtos." << endl;
        return;

    } else{

        Produto newProduct; //cria uma nova variavel newProduct do tipo Produto
        newProduct.status = 'A'; // define como A o status do novo produto

        if(quantidadeAtual == 0){ //verifica se nao tem nenhum numero registado
            newProduct.id = 1; //se for verdade define o novo produto com id 1

        } else{ //se for mentira
            newProduct.id = produtos[quantidadeAtual - 1].id + 1; //atribui um id sequencial ao novo produto com base no id do ultimo produto registado
            // [quantidadeAtual - 1] acessa o ultimo produto do array produtos
            // +1 incrementa o id e garante que o novo produto tenha um id unico e sequencial
        }       

        cout << "----------------------------------------" << endl;
        cout << "Insira o nome do produto: ";
        cin.ignore();
        getline(cin, newProduct.nome);

        cout << "----------------------------------------" << endl;
        cout << "Insira o preço do produto: ";
        cin >> newProduct.preco;

        cout << "----------------------------------------" << endl;
        cout << "Insira a quantidade do produto: ";
        cin >> newProduct.quantidade;

        produtos[quantidadeAtual] = newProduct;
        quantidadeAtual++;

        saveProd(produtos, quantidadeAtual, "lista.txt");
        system("clear");

        cout << "----------------------------------------" << endl;
        cout << "O produto foi adicionado." << endl;
    }
}

float calcularValorTotal(const Produto produtos[], int quantidadeAtual){

    float valorTotal = 0.0;

    for(int x = 0; x < quantidadeAtual; x++){
        valorTotal += produtos[x].preco * produtos[x].quantidade;
    }

    return valorTotal;
}

void showMenu(){

    cout << "----------------------------------------" << endl;
    cout << "                  MENU" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1 - Adicionar Produtos " << endl;
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

    do{

        showMenu();
        cin >> escolha;

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
            consultProd(produtos, quantidadeAtual); // Consulta produtos
            break;
        case 4:
            changeProd(produtos, quantidadeAtual); // Altera um produto
            break;
        case 5:
            eliminateProd(produtos, quantidadeAtual); // Elimina um produto
            break;
        case 6:
            saveProd(produtos, quantidadeAtual, "listaProdutos.txt");
            break;
        case 0:
            cout << "A sair do programa..." << endl; // Mensagem de saída
            break;
        default:
            cout << "Opção inválida! Voltando ao menu..." << endl; // Mensagem de erro
        }

    } while(escolha != 0);
}

int main(){

    system("clear");
    executaOpcao();

    return 0;
}
