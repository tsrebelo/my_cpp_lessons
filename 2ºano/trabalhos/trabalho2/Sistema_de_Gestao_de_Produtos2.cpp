#include <iostream> //importa a biblioteca para manipulacao de entrada e saida no terminal, como cin e cout(inputs e outputs)
#include <fstream>//permite a manipulacao de ficheiros externos(como a leitura e escrita no ficheiro)
#include <sstream>//para manipulacao de fluxos de strings, convertendo string em dados estruturados(util para ler ficheiros)
using namespace std; //evita a necessidade de prefixar objetos da biblioteca padrao com std:: como cout, cin e strings

const string DBfile = "lista.txt"; //define o nome do arquivo onde os produtos serao armazenados
const int prodMax = 80; //limita o numero max de produtos que o programa pode ter

//define uma estrutura com atributos id, nome, preco, quantidade e status
struct Produto{
    int id;
    string nome;
    float preco;
    int quantidade;
    char status;
};

//função para verificar e criar o ficheiro de base de dados
bool fileDB() {

    ifstream file(DBfile); //abre o ficheiro se houver um

    if (!file) {
     
        char opcao;

        cout << "---------------------------------------------------------" << endl;
        cout << "O ficheiro de base de dados não foi encontrado." << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Deseja criar um novo ficheiro de base de dados? (S/N): ";
        cin >> opcao;

        if (opcao == 'S' || opcao == 's') {
    
            ofstream newFile(DBfile); //cria um novo ficheiro

            newFile.close(); //fecha o ficheiro
            system("clear");

            cout << "-----------------------------------------------" << endl;
            cout << "Ficheiro de base de dados criado com sucesso!" << endl;

            return false; //indica que o ficheiro foi criado

        } else {
            //sai do programa
            system("clear");

            cout << "-----------------------------------------------" << endl;
            cout << "A sair do programa..." << endl;
            cout << "-----------------------------------------------" << endl;

            return false; //termina o programa
        }
    }

    return true; //o arquivo já existe
}

//funcao para carregar produtos no ficheiro
void loadProd(Produto produtos[], int& quantidadeAtual){

    ifstream file(DBfile); //abre o ficheiro (leitura)
    if (!file) return; //se o ficheiro não puder ser aberto, sai da função

    quantidadeAtual = 0; 

    //enquanto houver dados no ficheiro e a quantidade atual for menor que prodMax
    while (file.good() && quantidadeAtual < prodMax) {

        Produto p;
        string line;

        if (getline(file, line)) { //le uma linha do ficheiro

            stringstream ss(line); //converte a linha para um fluxo de string
            string status; 

            getline(ss, status, ','); //le o status
            p.status = status[0]; //armazena o status como um caractere

            ss >> p.id; //le o id 
            ss.ignore(); //ignora a virgula

            getline(ss, p.nome, ','); //le o nome 

            ss >> p.preco; //le o preco
            ss.ignore();

            ss >> p.quantidade; //le a quantidade

            produtos[quantidadeAtual] = p; //armazena o produto no array
            quantidadeAtual++; //incrementa
        }
    }

    file.close(); //fecha o ficheiro
}

//funcao para salvar produtos no ficheiro
void saveProd(const Produto produtos[], int quantidadeAtual){

    ofstream file(DBfile); //abre o ficheiro (escrita) 

    for(int x = 0; x < quantidadeAtual; x++){ 
        
        file << produtos[x].status << "," 
        << produtos[x].id << "," 
        << produtos[x].nome << "," 
        << produtos[x].preco << ","
        << produtos[x].quantidade << endl;
    }

    file.close();

    cout << "-----------------------------------------------" << endl;
    cout << "Produtos salvos com sucesso!" << endl;
}

//funcao para consultar os produtos
void consultProd(const Produto produtos[], int quantidadeAtual){

    char opcao;

    if(quantidadeAtual == 0){

        cout << "-----------------------------------------------" << endl;
        cout << "Sem produtos adicionados." << "\nVoltando ao menu..." << endl;

        return;

    } else{

        cout << "------------------------------------------------------------------" << endl;
        cout << "Quer consultar os produtos ativos(A), eliminados(E) ou todos(T)? ";
        cin >> opcao;

        system("clear");

        if(opcao == 'A' || opcao == 'a'){

            cout << "-----------------------------------------------" << endl;
            cout << "           Lista de produtos ativos" << endl; 

            for(int a = 0; a < quantidadeAtual; a++){

                if(produtos[a].status == 'A'){ 

                    cout << "-----------------------------------------------" << endl;
                    cout << "ID: " << produtos[a].id << endl;
                    cout << "Nome: " << produtos[a].nome << endl;
                    cout << "Preço: " << produtos[a].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[a].quantidade << endl;
                    cout << "Status: " << produtos[a].status << endl;

                }
            }
        }

        if(opcao == 'E' || opcao == 'e'){

            cout << "-----------------------------------------------" << endl;
            cout << "         Lista de produtos eliminados" << endl; 

            for(int e = 0; e < quantidadeAtual; e++){

                if(produtos[e].status == 'E'){ 

                    cout << "-----------------------------------------------" << endl;
                    cout << "ID: " << produtos[e].id << endl;
                    cout << "Nome: " << produtos[e].nome << endl;
                    cout << "Preço: " << produtos[e].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[e].quantidade << endl;
                    cout << "Status: " << produtos[e].status << endl;

                }
            }
        }

        if(opcao == 'T' || opcao == 't'){ 

            cout << "-----------------------------------------------" << endl;
            cout << "          Lista de todos os produtos" << endl; 

            for(int t=0; t<quantidadeAtual; t++){
                cout << "-----------------------------------------------" << endl;
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

    int id; 

    cout << "-----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja alterar: "; 
    cin >> id; 

    system("clear");

    for(int y = 0; y < quantidadeAtual; y++){ 

        //verifica se o produto existe e ativo
        if(produtos[y].id == id && produtos[y].status == 'A'){ 

            cout << "-----------------------------------------------" << endl;
            cout << "Insira o novo preço do produto: ";
            cin >> produtos[y].preco;

            cout << "-----------------------------------------------" << endl;
            cout << "Insira a nova quantidade do produto: ";
            cin >> produtos[y].quantidade;

            saveProd(produtos, quantidadeAtual); 
            system("clear");

            cout << "-----------------------------------------------" << endl;
            cout << "Produto alterado com sucesso." << endl;

            return; //fecha a funcao
        }
    }

    cout << "-----------------------------------------------" << endl;
    cout << "Produto nao foi encontrado ou ja foi eliminado." << endl;
}

//funcao para eliminar produtos
void eliminateProd(Produto produtos[], int quantidadeAtual){

    int id;

    cout << "-----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja eliminar: ";
    cin >> id;

    for(int w = 0; w < quantidadeAtual; w++){

        if(produtos[w].id == id){

            produtos[w].status = 'E'; 
            saveProd(produtos, quantidadeAtual);

            system("clear");

            cout << "-----------------------------------------------" << endl;
            cout << "Produto eliminado com sucesso!" << endl;

            return;
        }
    }

    system("clear");

    cout << "-----------------------------------------------" << endl;
    cout << "Produto nao encontrado." << endl;
}

//funcao que permite adicionar produtos
void addProduto(Produto produtos[], int& quantidadeAtual){

    if(quantidadeAtual >= prodMax){

        cout << "-----------------------------------------------" << endl;
        cout << "Atingiu o limite máximo de produtos." << "\nNão é possível adicionar mais produtos." << endl;

        return;

    } else{

        Produto newProduct; 
        newProduct.status = 'A'; 

        if(quantidadeAtual == 0){ 

            newProduct.id = 1; //se for o primeiro tem id 1

        } else{ 

            newProduct.id = produtos[quantidadeAtual - 1].id + 1; //atribui o proximo id

        }       

        cout << "-----------------------------------------------" << endl;
        cout << "Insira o nome do produto: ";
        cin.ignore(); //limpa o buffer(espaco da memora temporario) para evitar erros com a leitura das strings
        getline(cin, newProduct.nome);

        cout << "-----------------------------------------------" << endl;
        cout << "Insira o preço do produto: ";
        cin >> newProduct.preco;

        cout << "-----------------------------------------------" << endl;
        cout << "Insira a quantidade do produto: ";
        cin >> newProduct.quantidade;

        produtos[quantidadeAtual] = newProduct; 
        quantidadeAtual++; //incrementa a quantidade de prod atuais

        saveProd(produtos, quantidadeAtual);
        system("clear");

        cout << "-----------------------------------------------" << endl;
        cout << "O produto foi adicionado." << endl;
    }
}

//funcao que calcula o valor do preco total dos produtos
float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {

    float total = 0;

    for (int i = 0; i < quantidadeAtual; i++) {

        if (produtos[i].status == 'A') { 

            total += produtos[i].preco * produtos[i].quantidade;
        }
    }

    return total;
}

//funcao que mostra o menu
void showMenu(){

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

//funcao para executar a opcao
void executaOpcao(){

Produto produtos[prodMax];
int quantidadeAtual = 0;
int escolha;
loadProd(produtos, quantidadeAtual); 

    do{

        showMenu();
        cin >> escolha;

        system("clear");

        switch (escolha) {

        case 1:

            addProduto(produtos, quantidadeAtual); 
            break;

        case 2:

            cout << "-----------------------------------------------" << endl;
            cout << "O valor total em stock é: " << calcularValorTotal(produtos, quantidadeAtual) << "€" << endl;
            break;

        case 3:

            consultProd(produtos, quantidadeAtual); 
            break;

        case 4:

            changeProd(produtos, quantidadeAtual); 
            break;

        case 5:

            eliminateProd(produtos, quantidadeAtual); 
            break;

        case 0: 

            cout << "-----------------------------------------------" << endl;
            cout << "A sair do programa..." << endl; 
            cout << "-----------------------------------------------" << endl;
            break;

        default:

            cout << "-----------------------------------------------" << endl;
            cout << "Opção inválida! Voltando ao menu..." << endl;
        }

    } while(escolha != 0);
}

int main(){

    system("clear");
    fileDB();
    executaOpcao();

    return 0;
}
