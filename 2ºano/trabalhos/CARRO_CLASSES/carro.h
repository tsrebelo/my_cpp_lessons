#ifndef CARRO_H
#define CARRO_H

#include "veiculo.h"

class Carro : public Veiculo {

    private:   
        int portas;
        
    public:
        Carro(string nome, int portas);

        virtual void mostraDetalhes() override;
};

#endif