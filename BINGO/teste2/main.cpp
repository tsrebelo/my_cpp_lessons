/**
 * @autor Telma Silva Rebelo e Martim Victória Valério
 * 
 *
*/ 

#include "bibliotecas.h"
#include "bingo.h"
#include "menu.h"

int main() {
    Bingo jogo;
    int opcao;

    do {
        system("clear");
        exibirMenu();
        cin >> opcao;
        processarOpcao(jogo, opcao); // Processa a opção escolhida
    } while (opcao != 2);

    return 0;
}