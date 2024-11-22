#include "carro.h" 

Carro::Carro(string nome, int portas) : Veiculo(nome), portas(portas){ 

}

void Carro::mostraDetalhes(){ 
    cout << "------------------------------------" << endl;
    cout << "Nome do carro: " << nome << "\nQuantidade de portas: " << portas << endl;
    cout << "------------------------------------" << endl;
}
