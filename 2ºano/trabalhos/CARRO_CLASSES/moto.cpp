#include "moto.h"

Moto::Moto(string nome, int cilindros, int cv) : Veiculo(nome), cilindros(cilindros), potencia(cv){

}

void Moto::overWrite(){
    cout << "Nome da moto: " << nome << "\nCilindros: " << cilindros << "\nPotência: " << potencia  << "cv" << endl;
    cout << "------------------------------------" << endl;
}
