#include "carro.h"

Carro::Carro(string nome, int portas, float cc) : Veiculo(nome), portas(portas), cc(cc){

}

void Carro::overWrite(){
    cout << "------------------------------------" << endl;
    cout << "Nome do carro: " << nome << "\nQuantidade de portas: " << portas << "\nCilindrada: " << cc << " cm³" << endl;
    cout << "------------------------------------" << endl;
}
