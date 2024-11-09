#ifndef MOTO_H
#define MOTO_H

#include "veiculo.h"

class Moto : public Veiculo{

    private:
        int potencia;
        int cilindros;

    public:
        Moto(string nome, int cv, int cilindros);
        
        virtual void overWrite();

};

#endif