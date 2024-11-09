#include "carro.h" // chama o arquivo
#include "moto.h" 

int main(){

    system("clear");

    Carro carro1("BMW M4 Competition", 2); // cria um objeto "carro1" do tipo Carro
    Moto moto1("HONDA CBR 650R", "desportivo");

    carro1.mostraDetalhes(); //chama o metodo para exibir os detalhes do carro
    moto1.mostraDetalhes(); 

    return 0;
}