#include "carro.h" // inclui o ficheiro onde a classe Carro é definida

Carro::Carro(string nome, int portas) : Veiculo(nome), portas(portas){ // construtor da classe Carro, define o contrutor e inicia o "nome" e "portas"

}

void Carro::mostraDetalhes(){ // definição do método mostraDetalhes da classe Carro
    cout << "------------------------------------" << endl;
    cout << "Nome do carro: " << nome << "\nQuantidade de portas: " << portas << endl;
    cout << "------------------------------------" << endl;
}
