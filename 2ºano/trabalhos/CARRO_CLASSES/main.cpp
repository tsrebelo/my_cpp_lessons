#include "carro.h" 
#include "moto.h" 

int main(){

    system("clear");

    Carro carro1("BMW M4 Competition", 2); 
    Moto moto1("HONDA CBR 650R", "desportivo"); 

    carro1.mostraDetalhes(); 
    moto1.mostraDetalhes(); 

    return 0;
}