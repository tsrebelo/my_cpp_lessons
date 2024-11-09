#ifndef CARRO_H
#define CARRO_H

#include "veiculo.h"

class Carro : public Veiculo {

    private:   
        int portas;
        float cc;
        
    public:
        Carro(string nome, int portas, float cc);

        virtual void overWrite() override;
};

#endif