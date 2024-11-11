#ifndef MOTO_H
#define MOTO_H

#include "veiculo.h"

class Moto : public Veiculo{

    private:
        string guidao;

    public:
        Moto(string nome, string guidao);
        
        virtual void mostraDetalhes();

};

#endif