#include <iostream> //declara objetos que controlam a leitura e a gravação nos fluxos padrão. Essa inclusão é geralmente o único cabeçalho necessário para executar a entrada e a saída de um programa C++
using namespace std; //usado para o compilador perceber que sempre que utilizarmos funcoes e objetos da biblioteca padrao em c++ como outputs e inputs e a delcaracao de variaveis do tipo string, nao seja preciso usar ::std

const int prodMax = 80; //é uma constante que define a quantidade máxima de produtos que o programa pode gerenciar, nao pode ser alterado tambem

struct Produto{ //struct com atributos id, nome, preco, quantidade e status

    string nome;
    float preco;
    int quantidade;
};

//funcao que permite adicionar produtos
void addProduto(Produto produtos[], int& quantidadeAtual){

    if(quantidadeAtual >= prodMax){

        cout << "-----------------------------------------------" << endl;
        cout << "Atingiu o limite máximo de produtos." << "\nNão é possível adicionar mais produtos." << endl;
        return;

    } else{

        Produto newProduct; //cria uma nova variavel newProduct do tipo Produto     

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

        system("clear");

        cout << "-----------------------------------------------" << endl;
        cout << "O produto foi adicionado." << endl;
    }
}

//funcao para consultar os produtos
void exibirProd(const Produto produtos[], int quantidadeAtual){

    if(quantidadeAtual == 0){
        cout << "-----------------------------------------------" << endl;
        cout << "Sem produtos adicionados." << "\nVoltando ao menu..." << endl;
        return;

    } else{

        cout << "-----------------------------------------------" << endl;
        cout << "          Lista de todos os produtos" << endl; 
        for(int t=0; t<quantidadeAtual; t++){
            cout << "-----------------------------------------------" << endl;
            cout << "Nome: " << produtos[t].nome << endl;
            cout << "Preço: " << produtos[t].preco << "€" << endl;
            cout << "Quantidade: " << produtos[t].quantidade << endl;                                                                     
        }
    }
}

//funcao que calcula o valor do preco total dos produtos
float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {

    float total = 0.0;

    for (int i = 0; i < quantidadeAtual; i++) {

        total += produtos[i].preco * produtos[i].quantidade;

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
    cout << "3 - Exibir Produtos " << endl;
    cout << "0 - Sair " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Digite a sua opção: ";
   
}

//funcao para executar a opcao
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
            cout << "-----------------------------------------------" << endl;
            cout << "O valor total em stock é: " << calcularValorTotal(produtos, quantidadeAtual) << "€" << endl;
            break;
        case 3:
            exibirProd(produtos, quantidadeAtual);
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
    executaOpcao();

    return 0;
}