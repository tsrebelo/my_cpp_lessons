/**
 * @brief Ficheiro de declaração dos protótipos das funções relacionadas à lógica do bingo
 */
#ifndef BINGO_H
#define BINGO_H

#include "bibliotecas.h"

/**
 * @brief Estrutura que representa uma carta de bingo com uma matriz 5x5 de números
 * 
 */
struct CartaBingo{
    vector<vector<int>> numeros;
};

/**
 * @brief Cria uma carta de bingo aleatória
 */
CartaBingo gerarCarta();

/**
 * @brief Salva as cartas em arquivos
 * 
 */
void salvarCarta(const CartaBingo& carta, const string& arquivo);

/**
 * @brief Mostra a tabela de números a ser sorteados
 * 
 */
void exibirTabela(const vector<int>& numerosSorteados);

/**
 * @brief Controla o fluxo do jogo
 * 
 */
void iniciarJogo(bool automatico);

#endif