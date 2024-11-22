#ifndef MOTO_H // verifica se não foi definida
#define MOTO_H // define para evitar múltiplas inclusões no ficheiro

#include "veiculo.h" // inclui o ficheiro onde a classe Veiculo é definida

class Moto : public Veiculo{ // declara a classe Moto, que herda da classe base Veiculo

    private:
        string guidao; // declara o atributo "guidao" que armazena o tipo de guidão da moto

    public:
        Moto(string nome, string guidao); // Ddclaração do construtor da classe Moto.
        
        virtual void mostraDetalhes(); // declaração do método mostraDetalhes que sobrescreve o método da classe base

};

#endif // fecha e guarda a inclusão iniciada no #ifndef