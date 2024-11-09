#include "veiculo.h"

Veiculo::Veiculo(string nome) : nome(nome){

}

void Veiculo::mostraDetalhes(){
    cout << "Nome do veiculo: " << nome << endl;
}
