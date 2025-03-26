#ifndef BINGO_H
#define BINGO_H

#include "bibliotecas.h"

class Bingo {
private:
    vector<vector<int>> cartela; // Cartela de Bingo
    vector<int> numerosSorteados;     // Números já sorteados
    int numeroAnterior;                    // Número anterior sorteado

    void gerarCarta();                   // Gera a cartela de Bingo
    bool numeroJaSorteado(int numero);     // Verifica se o número já foi sorteado
    void limparCarta();                  // Limpa a cartela e os números sorteados
    int linhaVencedora();                  // Retorna a linha que fez bingo (-1 se não houver)
    int colunaVencedora();                 // Retorna a coluna que fez bingo (-1 se não houver)

public:
    Bingo();
    void exibirCarta();                  // Exibe a cartela no terminal
    void exibirCartaBingo();             // Exibe a cartela com a linha/coluna do bingo em negrito
    void sortearNumero();                  // Sorteia um número
    bool verificarVencedor();              // Verifica se há um vencedor
    void criarNovaCarta();               // Cria uma nova cartela
    int getNumeroAnterior() const;         // Retorna o número anterior sorteado
};

#endif