#include "veiculo.h"

Veiculo::Veiculo(string nome) : nome(nome){ 
    //Veiculo::Veiculo(string nome) indica que estamos definindo
    //o construtor da classe Veiculo, que recebe um parâmetro nome do tipo string.
    //: nome(nome) é uma lista de inicialização, usada para inicializar o atributo nome com o 
    //valor passado como argumento nome. Isso significa que o atributo nome da classe será definido pelo 
    //valor passado no momento da criação do objeto Veiculo.

}

void Veiculo::mostraDetalhes(){
    cout << "Nome do veiculo: " << nome << endl;
    //void Veiculo::mostraDetalhes() indica que estamos definindo o método mostraDetalhes da classe Veiculo, que não retorna nada (void).
}
