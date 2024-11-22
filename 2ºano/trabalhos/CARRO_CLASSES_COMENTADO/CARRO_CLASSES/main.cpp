#include "carro.h" // inclui o ficheiro que define a class carro
#include "moto.h" // inclui o ficheiro que define a class moto

int main(){

    system("clear");

    Carro carro1("BMW M4 Competition", 2); // estância um objeto carro1 da classe carro
    Moto moto1("HONDA CBR 650R", "desportivo"); // estância um objeto  moto1 da classe moto

    carro1.mostraDetalhes(); // chama o método mostraDetalhes() para exibir as informações do carro
    moto1.mostraDetalhes(); // chama o método mostraDetalhes() para exibir as informações da moto

    return 0; // finaliza a execução do programa e retorna 0, indicando fecho com sucesso
}