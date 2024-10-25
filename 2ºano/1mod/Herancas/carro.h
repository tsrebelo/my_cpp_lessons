#include <iostream>
#include "acoes.h"
using namespace std;

class Carro : public Acoes{
    private:
        string marca;
        string modelo;

    public:
        Carro(string marca, string modelo);
};