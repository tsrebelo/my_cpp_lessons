#include <iostream>
using namespace std;

const int prodMax = 5;

struct Produto{
    string nome;
    float preco;
    int quantidade;
};

void addProduto(Produto produtos[], int& quantidadeAtual){

    if(quantidadeAtual >= prodMax){
        cout << "Atingiu o limite máximo de produtos." << "\nNão é possível adicionar mais produtos." << endl;
        return;

    } else{

        Produto newProduct;
        cout << "Insira o nome do produto: ";
        cin >> newProduct.nome;
        cout << "Insira o preço do produto: ";
        cin >> newProduct.preco;
        cout << "Insira a quantidade do produto: ";
        cin >> newProduct.quantidade;

        produtos[quantidadeAtual] = newProduct;
        quantidadeAtual++;

        system("clear");
        cout << "O produto foi adicionado." << endl;
    }

}

void exibirProdutos(const Produto produtos[], int quantidadeAtual){
    
    if(quantidadeAtual == 0){
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

    for(int x=0; x<quantidadeAtual; x++){
        valorTotal += produtos[x].preco * produtos[x].quantidade;
    }

    return valorTotal;
}

void showMenu(){

    cout << "----------------------------------------" << endl;
    cout << "                  MENU" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1 - Adicionar Produto " << endl;
    cout << "2 - Exibir Produtos " << endl;
    cout << "3 - Calcular Valor Total do Stock " << endl;
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
                cout << "O valor total em stock é: " << calcularValorTotal(produtos, quantidadeAtual) << "€" << endl;
                break;

            case 0:
                cout << "A fechar o programa..." << endl;
                break;

            default:
            cout << "Opção inválida! Voltando ao menu..." << endl;

        }

    } while(escolha != 0);
}

int main(){

    system("clear");
    executaOpcao();

    return 0;
}
