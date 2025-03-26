/**
 * 
 * 
 */

#include "bibliotecas.h"
#include "cores.h"
#include "menu.h"

void exibirMenuPrincipal(){

    cout << BOLD << YELLOW << "Bem-vindo ao Jogo de Bingo!\n" << RESET;
    cout << "1. Criar Cartas\n";
    cout << "2. Iniciar Jogo\n";
    cout << "3. Sair\n";
    cout << "\nEscolha uma opção: ";
}

void exibirMenuCriarCartas(){

    cout << "Quantas cartas deseja criar? ";
}

void exibirMenuJogo(){

    cout << BOLD << CYAN << "Escolha o modo de jogo:\n" << RESET;
    cout << "1. Jogo Automático\n";
    cout << "2. Jogo Manual\n";
    cout << "\nEscolha uma opção: ";
}
