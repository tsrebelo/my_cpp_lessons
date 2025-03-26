#ifndef BINGO_H
#define BINGO_H

#include "bibliotecas.h"

struct CartaBingo{
    vector<vector<int>> numeros;
};

CartaBingo gerarCarta();
void salvarCarta(const CartaBingo& carta, const string& arquivo);
void exibirTabela(const vector<int>& numerosSorteados);
void iniciarJogo(bool automatico);

#endif