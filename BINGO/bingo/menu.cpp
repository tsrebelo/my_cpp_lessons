/**
 * @brief Ficheiro de implementação das funções declaradas no menu.h
 * 
 */

#include "bibliotecas.h"
#include "cores.h"
#include "menu.h"

/**
 * @brief Função que exibe o menu principal com opções para criar cartas, jogar ou sair
 * 
 */
void exibirMenuPrincipal(){

    cout << BOLD << YELLOW << "Bem-vindo ao Jogo de Bingo!\n" << RESET;
    cout << "\n1. Criar Cartas\n";
    cout << "2. Iniciar Jogo\n";
    cout << "3. Sair\n";
    cout << "\nEscolha uma opção: ";
}

/**
 * @brief Função que exibe o prompt para o utilizador inserir quantas cartas deseja criar
 * 
 */
void exibirMenuCriarCartas(){

    cout << "Quantas cartas deseja criar? ";
}

/**
 * @brief Função que exibe o menu para seleção do modo de jogo (automático ou manual)
 * 
 */
void exibirMenuJogo(){

    cout << BOLD << CYAN << "Escolha o modo de jogo:\n" << RESET;
    cout << "1. Jogo Automático\n";
    cout << "2. Jogo Manual\n";
    cout << "\nEscolha uma opção: ";
}
