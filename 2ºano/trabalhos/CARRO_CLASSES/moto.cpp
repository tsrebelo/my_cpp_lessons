#include "moto.h"

Moto::Moto(string nome, string guidao) : Veiculo(nome), guidao(guidao){

}

void Moto::mostraDetalhes(){
    cout << "Nome da moto: " << nome << "\nTipo de guidão: " << guidao << endl;
    cout << "------------------------------------" << endl;
}
