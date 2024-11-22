//DECLARA

#include "moto.h" // inclui o ficheiro onde a classe Moto é definida


Moto::Moto(string nome, string guidao) : Veiculo(nome), guidao(guidao){ // construtor da classe Moto, define o construtor e inicia o "nome" e "guidao"

}

void Moto::mostraDetalhes(){ // definição do método mostraDetalhes da classe Moto
    cout << "Nome da moto: " << nome << "\nTipo de guidão: " << guidao << endl;
    cout << "------------------------------------" << endl;
}
