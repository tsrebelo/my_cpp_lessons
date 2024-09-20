#include <iostream>
using namespace std;

struct Produto{
    string nome;
    float preco;
    int quantidade;
};

void adicionarProduto(Produto produtos[], int& quantidadeAtual){

    cout << "Insira o nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;

    cout << "Insira o preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;

    cout << "Insira a quantidade do produto: ";
    cin >> produtos[quantidadeAtual].quantidade;

}

void exibirProdutos(const Produto produtos[], int quantidadeAtual){
    
    if(quantidadeAtual == 0){
        cout << "Erro!" << endl << "Este campo está vazio." << endl;
    } else{
        for(int n=0; n+1; n++){

    cout << "O nome do produto é: " << produtos[n].nome << endl;

    cout << "O preço do produto é: " << produtos[n].preco << endl;

    cout << "A quantidade do produto é: " << produtos[n].quantidade << endl;

        }
    }
    
}

float calcularValorTotal(const Produto produtos[], int quantidadeAtual){
    
}

void menu(){

    system("clear");
    cout << "         MENU" << endl;
    cout << "----------------------" << endl;
    cout << "1 - Adicionar Produto " << endl;
    cout << "2 - Exibir Produtos " << endl;
    cout << "3 - Calcular Valor Total do Stock " << endl;
    cout << "0 - Sair " << endl;
}

int getOpcao(){

    int escolha;
    cout << "Digite a sua opção: ";
    cin >> escolha;

    return escolha;
}

void executaOpcao(int escolha, Produto produtos[], int quantidadeAtual){

do{

    switch(escolha){
        case 1:
            adicionarProduto(produtos, quantidadeAtual);
            break;

        case 2:

            break;

        case 3:

            break;

        case 0:
            cout << "A sair..." << endl;
            break;

        default:
        cout << "Opção inválida!" << endl;
            break;

    }

} while(escolha != 0);
}

int main(){

    Produto produtos[100];
    int quantidadeAtual = 0;
    int escolha;
    menu();
    escolha = getOpcao();
    system("clear");
    executaOpcao(escolha, produtos, quantidadeAtual);

    return 0;
}