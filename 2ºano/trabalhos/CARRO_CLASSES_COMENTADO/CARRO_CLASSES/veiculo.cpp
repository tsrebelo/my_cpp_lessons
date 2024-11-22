//DECLARA

#include "veiculo.h" // inclui o ficheiro onde a classe Veiculo é definida

Veiculo::Veiculo(string nome) : nome(nome){ // construtor da classe Veiculo, define o construtor e inicializa o atributo "nome"

}

void Veiculo::mostraDetalhes(){ // definição do método mostraDetalhes da classe Veiculo
    cout << "Nome do veiculo: " << nome << endl; 
}
