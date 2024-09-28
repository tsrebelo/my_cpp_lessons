/**
 * @file bingo_prof.cpp
 * @author Paulo Leite
 * @brief Jogo do bingo, passagem de conhecimento para os alunos
 * @version 0.1
 * @date 2024-01-17
 * 
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

const int numLinhasCartao       = 5;
const int numColunasCartao      = 5;
const int numColunasPainel      = 20;
const int intervlaoEntreBolas   = 500000;
const int msgPause              = 2000000;

int sorteados       = 0;
int numSorteado     = 0;
int anterior        = 0;

int numDeBolas, tipoSorteio, numDeCartoes;

string red          = "\u001b[31m";
string blue         = "\u001b[34m";
string green        = "\u001b[32m";
string reset        = "\u001b[0m";
string bold         = "\u001b[1m";
string blink        = "\u001b[5m";

string figletFont   = "big"; //big, slant, small, mini, script, smslant

typedef struct{
    int numero;
    bool sorteado;
} bingoBool;

bingoBool bingo[] = {};

/**
 * @brief Função para centrar uma string no ecrã
 * 
 * @param mensagem
*/

void centerString(string mensagem){
    int pos = (int)((numColunasPainel*3 - (mensagem.length())) /2);
    for(int i= 0; i < pos; i++){
        cout << " ";
    }
    cout << blue;
    cout << mensagem << reset;
    cout << blue << endl;
}

/**
 * @brief Função para inializar o array de estruturas de dados
 * 
*/
void initArray(){
    for(int i = 0; i <= numDeBolas; i++){
        bingo[i].numero = i+1;
        bingo[i].sorteado = false;
    }
}

/**
 * @brief Função de apresentação dos cartões
 * 
*/
void opcoes(){

    tipoSorteio = 0;

    while(tipoSorteio < 1 || tipoSorteio > 4){

        system("clear || cls");
        cout << blue
        << "--------------------------------\n"
        << blue << bold << blink
        << "M E N U      P R I N C I P A L\n" << reset << blue
        << "--------------------------------" << endl
        << "1 - Sorteio Manual\n"
        << "2 - Sorteio Automático\n"
        << "3 - Gerar Cartões\n"
        << "4 - Sair\n"
        << "--------------------------------" << endl
        << bold << "Opção: " << reset << blue;
    cin >> tipoSorteio;
    }

}

