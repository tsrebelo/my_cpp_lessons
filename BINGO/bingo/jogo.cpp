/**
 * @brief Ficheiro de implementação da função declarada no jogo.h
 * 
 */

#include "bibliotecas.h"
#include "menu.h"
#include "bingo.h"
#include "jogo.h"

/**
 * @brief Função principal que administra o fluxo do programa e a interação com o utilizador
 * 
 */
void executarJogo(){
    srand(time(0));
    int opcao;
    vector<CartaBingo> cartas;

    while (true) {
        system("clear");
        exibirMenuPrincipal();
        cin >> opcao;

        if (opcao == 1){
            system("clear");
            exibirMenuCriarCartas();
            int quantidade;
            cin >> quantidade;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            for(int i = 0; i < quantidade; i++){
                CartaBingo carta = gerarCarta();
                string nomeArquivo = "carta_" + to_string(i+1) + ".txt";
                salvarCarta(carta, nomeArquivo);
                cout << "Carta criada: " << nomeArquivo << endl;
            }

            cout << "\nClique ENTER para voltar ao menu...";
            cin.get();

        } else if (opcao == 2) {
            system("clear");
            exibirMenuJogo();
            cin >> opcao;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (opcao == 1){
                iniciarJogo(true);
            }else if (opcao == 2){
                iniciarJogo(false);
            }else{
                cout << "Opção inválida!";
                cin.get();
            }

        }else if(opcao == 3){
            break;
        }else{
            cout << "Opção inválida!";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }
}