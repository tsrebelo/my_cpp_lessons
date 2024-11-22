#ifndef VEICULO_H 
#define VEICULO_H 

#include "biblioteca.h" 

class Veiculo{ 

    protected:
        string nome; 

    public:
        Veiculo(string nome); 

        virtual void mostraDetalhes(); 

};

#endif
