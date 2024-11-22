#ifndef CARRO_H // verifica se não foi definida
#define CARRO_H // define para evitar múltiplas inclusões no ficheiro

#include "veiculo.h" // inclui o ficheiro que define a classe base Veiculo

class Carro : public Veiculo { // declara a classe Carro, que herda da classe base Veiculo

    private:   
        int portas; // declara o atributo "portas" que armazena o número de portas do carro
        
    public:
        Carro(string nome, int portas); // declaração do construtor da classe Carro

        virtual void mostraDetalhes() override; // declaração do método mostraDetalhes() que sobrescreve o método da classe base.
};

#endif // fecha e guarda a inclusão iniciada no #ifndef