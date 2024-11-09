#include "carro.h"
#include "moto.h"

int main(){

    system("clear");

    Carro carro1("BMW M4 Competition", 2, 2.993);
    Moto moto1("HONDA CBR 650R", 4, 95);

    carro1.overWrite();
    moto1.overWrite();

    return 0;
}