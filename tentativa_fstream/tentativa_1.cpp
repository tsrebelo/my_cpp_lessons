#include <iostream> //Declara objetos que controlam a leitura e a gravação nos fluxos padrão. Essa inclusão é geralmente o único cabeçalho necessário para executar a entrada e a saída de um programa C++
#include <fstream> //Define várias classes que dão suporte a operações de iostreams em sequências armazenadas em arquivos externos
using namespace std; //uasdo para o compilador perceber que sempre que utilizarmos funcoes e objetos da biblioteca padrao em c++ como outputs e inputs e a delcaracao de variaveis do tipo string, nao seja preciso usar ::std

const string DBfile = "tentativa_1"; //é uma constante que armazena o nome de um arquivo, e esse valor não pode ser alterado durante a execução do programa
const int prodMax = 80; //é uma constante que define a quantidade máxima de produtos que o programa pode gerenciar, nao pode ser alterado tambem

struct Produto{
    int id;
    string nome;
    float preco;
    int quantidade;
    char status;
};

void loadProd(Produto produtos[], int& quantidadeAtual, const string& tentativa_1){

    ifstream file(DBfile); //cria um objeto ifstream para abrir o arquivo 
    if (!file) return; //verifica se o arquivo foi aberto com sucesso. Se o arquivo nao existir ou houver erro na abertura volta sem fazer nada

    while(file >> produtos[quantidadeAtual].id){
        getline(file, produtos[quantidadeAtual].nome, ','); //vai ler o nome do produto ate achar uma virgula
        file >> produtos[quantidadeAtual].preco >> produtos[quantidadeAtual].quantidade >> produtos[quantidadeAtual].status;
        //vai ler o preco, a quantidade em sotck e o status do protudo
        quantidadeAtual++; //apos ler os dados de um produto, incrementa-se quantidadeAtual para passar para o proximo produto no array
    }
    file.close(); //fecha o arquivo
}

void saveProd(const Produto produtos[], int quantidadeAtual, const string& tentativa_1){

    ofstream file(DBfile); //cria um objeto ofstream para abrir o arquivo. Esse objeto abre o arquivo para gravacao. Se ja existir o arquivo ele vai ser sobrescrito
    for(int x = 0; x < quantidadeAtual; x++){ //ciclo for que percorre o array de produtos desdo indice 0 ate quantidadeAtual, salva todos os produtos existentes no array
        file << produtos[x].id << "," << produtos[x].nome << "," << produtos[x].quantidade << "," //para cada produto no array,a funcao escreve os dados
        << produtos[x].preco << "," << produtos[x].status << endl; // << serve para gravar dados no arquivo
    }
    file.close(); //fecha o arquivo
}

void addProduto(Produto produtos[], int& quantidadeAtual){

    if(quantidadeAtual >= prodMax){

        cout << "----------------------------------------" << endl;
        cout << "Atingiu o limite máximo de produtos." << "\nNão é possível adicionar mais produtos." << endl;
        return;

    } else{

        Produto newProduct;
        cout << "----------------------------------------" << endl;
        cout << "Insira o nome do produto: ";
        cin >> newProduct.nome;
        cout << "----------------------------------------" << endl;
        cout << "Insira o preço do produto: ";
        cin >> newProduct.preco;
        cout << "----------------------------------------" << endl;
        cout << "Insira a quantidade do produto: ";
        cin >> newProduct.quantidade;

        produtos[quantidadeAtual] = newProduct;
        quantidadeAtual++;

        system("clear");
        cout << "----------------------------------------" << endl;
        cout << "O produto foi adicionado." << endl;
    }

}

void exibirProdutos(const Produto produtos[], int quantidadeAtual){
    
    if(quantidadeAtual == 0){

        cout << "----------------------------------------" << endl;
        cout << "Sem produtos adicionados." << "\nVoltando ao menu..." << endl;

    } else{

        for(int n=0; n<quantidadeAtual; n++){
            cout << "----------------------------------------" << endl;
            cout << "O nome do produto " << n+1 << " é: " << produtos[n].nome << endl;
            cout << "O preço do produto " << n+1 << " é: " << produtos[n].preco << "€" << endl;
            cout << "A quantidade do produto " << n+1 << " é: " << produtos[n].quantidade << endl;                                                                                         

        }
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
    cout << "2 - Exibir Produtos " << endl;
    cout << "3 - Calcular Valor Total do Stock " << endl;
    cout << "4 - Alterar Produtos " << endl;
    cout << "5 - Eliminar Produtos " << endl;
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

        switch(escolha){
            case 1:
                addProduto(produtos, quantidadeAtual);
                break;

            case 2:
                exibirProdutos(produtos, quantidadeAtual);
                break;

            case 3:
                cout << "----------------------------------------" << endl;
                cout << "O valor total em stock é: " << calcularValorTotal(produtos, quantidadeAtual) << "€" << endl;
                break;

            case 0:
                cout << "----------------------------------------" << endl;
                cout << "A sair do programa..." << endl;
                cout << "----------------------------------------" << endl;
                break;

            default:
                cout << "----------------------------------------" << endl;
                cout << "Opção inválida! Voltando ao menu..." << endl;
        }

    } while(escolha != 0);
}

int main(){

    system("clear");
    executaOpcao();

    return 0;
}
