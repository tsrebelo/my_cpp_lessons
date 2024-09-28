#include <iostream> //utilizada para dar entrada e saida de dados(como cin e cout)
#include <fstream> //trabalha com ficheiros, permitindo a leitura e a gravacao
#include <sstream> //facilita a manipulacao de strings e conversao entre tipos de dados
using namespace std; //evita a necessidade de prefixar funções e objetos da biblioteca padrão com std::, como cout, cin, e string.

const string DBfile = "lista_produtos.txt"; //constante global que armazena o nome do arquivo onde os produtos vao ser salvos e carregados
const int prodMax = 80; //constante global define o numero max de produtos que podem ser armazenados no array

struct Produto{ //struct que define um produto com os atributos id, nome, preco, quantidade e status
    int id;
    string nome;
    float preco;
    int quantidade;
    char status;
};

// Função para verificar e criar o ficheiro de base de dados
bool fileDB() {

    ifstream file(DBfile);
    if (!file) {
        // O ficheiro não existe
        char opcao;
        cout << "---------------------------------------------------------" << endl;
        cout << "O ficheiro de base de dados não foi encontrado." << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Deseja criar um novo ficheiro de base de dados? (S/N): ";
        cin >> opcao;

        if (opcao == 'S' || opcao == 's') {
            // Cria um novo ficheiro
            ofstream newFile(DBfile);
            newFile.close();
            cout << "-----------------------------------------------" << endl;
            cout << "Ficheiro de base de dados criado com sucesso!" << endl;
            return true; // O ficheiro foi criado
        } else {
            system("clear");
            // Sai do programa
            cout << "-----------------------------------------------" << endl;
            cout << "A sair do programa..." << endl;
            cout << "-----------------------------------------------" << endl;
            return false; // O utilizador optou por sair
        }
    }
    return true; // O ficheiro já existia
}


//funcao que carrega os produtos salvos no ficheiro para o array
void loadProd(Produto produtos[], int& quantidadeAtual){

    ifstream file(DBfile); //abre o ficheiro

    while (file.good() && quantidadeAtual < prodMax) {
        Produto p;
        string line;

        // lê linha inteira por linha inteira do arquivo
        if (getline(file, line)) {
            stringstream ss(line);
            string status; // para capturar o status
            getline(ss, status, ','); // lê o status
            p.status = status[0]; // define o status
            ss >> p.id; // lê o ID
            ss.ignore(); // ignora a vírgula
            getline(ss, p.nome, ','); // lê o nome até a vírgula
            ss >> p.preco; // lê o preço
            ss.ignore(); // ignora a vírgula
            ss >> p.quantidade; // lê a quantidade

            produtos[quantidadeAtual] = p; // armazena o produto
            quantidadeAtual++; // incrementa a quantidade atual
        }
    }
    file.close(); // fecha o arquivo
}

//funcao para salvar o conteudo do array no ficheiro
void saveProd(const Produto produtos[], int quantidadeAtual){

    ofstream file(DBfile); //abre o ficheiro em modo modo escrita
    for(int x = 0; x < quantidadeAtual; x++){ //ciclo for que percorre o array de produtos desdo indice 0 ate quantidadeAtual, salva todos os produtos existentes no array
        file << produtos[x].status << "," << produtos[x].id << ","  //para cada produto no array,a funcao escreve os dados
        << produtos[x].nome << "," << produtos[x].preco << "," // << serve para gravar dados no ficheiro
        << produtos[x].quantidade << endl;
    }
    file.close(); //fecha o ficheiro

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

                if(produtos[a].status == 'A'){ // o if verifica se o status do produto indice a for A, indica que esta ativo

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

                if(produtos[e].status == 'E'){ // o if verifica se o status do produto indice e for E, indica que esta eliminado

                    cout << "-----------------------------------------------" << endl;
                    cout << "ID: " << produtos[e].id << endl;
                    cout << "Nome: " << produtos[e].nome << endl;
                    cout << "Preço: " << produtos[e].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[e].quantidade << endl;
                    cout << "Status: " << produtos[e].status << endl;

                }
            }
        }

        if(opcao == 'T' || opcao == 't'){ // se a opcao for T vai mostrar todos os produtos dos A e os D

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

    int id; //declaracao de uma variavel inteira id
    cout << "-----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja alterar: "; 
    cin >> id; //solicita ao usuario que insira o id para alterar e o valor vai ser armazenado na variavel id
    system("clear");

    for(int y = 0; y < quantidadeAtual; y++){ //vai percorrer todos os produtos do array, procurando um produto com id igual ao valor de id inserido

        if(produtos[y].id == id && produtos[y].status == 'A'){ //verifica o id o que garante que tenha status A. Impedindo que produtos D sejam alterados

            cout << "-----------------------------------------------" << endl;
            cout << "Insira o novo nome do produto: ";
            cin.ignore(); // limpa o buffer de entrada para evitar que os restos de entradas anteriores interfiram no uso do getline
            getline(cin, produtos[y].nome); //permite ler o nome completo do produto, incluindo espacos
            cout << "-----------------------------------------------" << endl;
            cout << "Insira o novo preço do produto: ";
            cin >> produtos[y].preco;
            cout << "-----------------------------------------------" << endl;
            cout << "Insira a nova quantidade do produto: ";
            cin >> produtos[y].quantidade;

            saveProd(produtos, quantidadeAtual); // salva as alterações no ficheiro
            system("clear");
            cout << "-----------------------------------------------" << endl;
            cout << "Produto alterado com sucesso." << endl;
            return;

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

            produtos[w].status = 'E'; // define o status como eliminado
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

        Produto newProduct; //cria uma nova variavel newProduct do tipo Produto
        newProduct.status = 'A'; // define como A o status do novo produto

        if(quantidadeAtual == 0){ //verifica se nao tem nenhum numero registado
            newProduct.id = 1; //se for verdade define o novo produto com id 1

        } else{ //se for mentira
            newProduct.id = produtos[quantidadeAtual - 1].id + 1; //atribui um id sequencial ao novo produto com base no id do ultimo produto registado
            // [quantidadeAtual - 1] acessa o ultimo produto do array produtos
            // +1 incrementa o id e garante que o novo produto tenha um id unico e sequencial
        }       

        cout << "-----------------------------------------------" << endl;
        cout << "Insira o nome do produto: ";
        cin.ignore();
        getline(cin, newProduct.nome);

        cout << "-----------------------------------------------" << endl;
        cout << "Insira o preço do produto: ";
        cin >> newProduct.preco;

        cout << "-----------------------------------------------" << endl;
        cout << "Insira a quantidade do produto: ";
        cin >> newProduct.quantidade;

        produtos[quantidadeAtual] = newProduct; //o novo produto e adicionado no array produtos
        quantidadeAtual++; //vai incrementar para refletir o novo total de produtos

        saveProd(produtos, quantidadeAtual);
        system("clear");

        cout << "-----------------------------------------------" << endl;
        cout << "O produto foi adicionado." << endl;
    }
}

//funcao que calcula o valor do preco total dos produtos
float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {

    float total = 0.0;

    for (int i = 0; i < quantidadeAtual; i++) {

        if (produtos[i].status == 'A') { // Apenas soma os produtos ativos
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
loadProd(produtos, quantidadeAtual); // carrega os produtos do ficheiro

    do{

        showMenu();
        cin >> escolha;

        system("clear");

        switch (escolha) {
        case 1:
            addProduto(produtos, quantidadeAtual); // Adiciona um produto
            break;
        case 2:
            cout << "-----------------------------------------------" << endl;
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
            cout << "-----------------------------------------------" << endl;
            cout << "A sair do programa..." << endl; // Mensagem de saída
            cout << "-----------------------------------------------" << endl;
            break;
        default:
            cout << "-----------------------------------------------" << endl;
            cout << "Opção inválida! Voltando ao menu..." << endl; // Mensagem de erro
        }

    } while(escolha != 0);
}

int main(){

    system("clear");

    // Chama a função fileDB para verificar o ficheiro
    if (!fileDB()) {
        // Se o ficheiro não foi criado e o utilizador escolheu sair, termina o programa
        return 0;
    }

    // O ficheiro existe ou foi criado, entra no menu
    executaOpcao();

    return 0;
}