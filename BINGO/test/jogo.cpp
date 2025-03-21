#include "bibliotecas.h"
#include "menu.h"
#include "bingo.h"
#include "jogo.h"

void executarJogo() {
    srand(time(0)); // Inicializa a semente para números aleatórios

    int opcao;
    vector<CartaBingo> cartas;

    while (true) {
        limparTela();
        exibirMenuPrincipal();
        cin >> opcao;

        if (opcao == 1) {
            limparTela();
            exibirMenuCriarCartas();
            int quantidade;
            cin >> quantidade;

            cartas.clear();
            for (int i = 0; i < quantidade; i++) {
                CartaBingo carta = gerarCarta();
                cartas.push_back(carta);
                salvarCarta(carta, "carta" + to_string(i + 1) + ".txt");
            }

            cout << "Cartas salvas em arquivos separados!\n";
            cin.ignore();
            cin.get();
        } else if (opcao == 2) {
            limparTela();
            exibirMenuJogo();
            cin >> opcao;

            if (opcao == 1) {
                iniciarJogo(true); // Modo automático
            } else if (opcao == 2) {
                iniciarJogo(false); // Modo manual
            } else {
                cout << "Opção inválida!\n";
            }
        } else if (opcao == 3) {
            break;
        } else {
            cout << "Opção inválida! Tente novamente.\n";
            cin.ignore();
            cin.get();
        }
    }
}