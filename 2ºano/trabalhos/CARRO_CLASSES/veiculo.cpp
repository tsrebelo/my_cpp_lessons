#include "veiculo.h"

Veiculo::Veiculo(string nome) : nome(nome){

}

void Veiculo::overWrite(){
    cout << "Nome do veiculo: " << nome << endl;
}
