#ifndef MENU_H
#define MENU_H

#include "bibliotecas.h"
#include "bingo.h" // Incluímos o cabeçalho do Bingo para usar a classe Bingo
using namespace std;

void exibirMenu();
void processarOpcao(Bingo& jogo, int opcao);

#endif