#ifndef VEICULO_H
#define VEICULO_H

#include "biblioteca.h" // chama o arquivo 

class Veiculo {

    protected:
        string nome;

    public:
        Veiculo(string nome);

        virtual void mostraDetalhes(); // pode ser sobrescrito em classes derivadas de Veiculo

};

#endif