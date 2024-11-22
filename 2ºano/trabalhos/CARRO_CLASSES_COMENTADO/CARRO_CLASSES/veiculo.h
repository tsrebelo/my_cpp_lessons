#ifndef VEICULO_H // verifica se não foi definida
#define VEICULO_H // define para evitar múltiplas inclusões no ficheiro

#include "biblioteca.h" // inclui o ficheiro 

class Veiculo{ // declaração da classe Veiculo

    protected:
        string nome; // declara um atributo protegido "nome" do tipo string

    public:
        Veiculo(string nome); // declaração do construtor da classe Veiculo, que recebe um parâmetro "nome"

        virtual void mostraDetalhes(); // declaração de um método virtual chamado mostraDetalhes.

};

#endif // fecha e guarda a inclusão iniciada no #ifndef
