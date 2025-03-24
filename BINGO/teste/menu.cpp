#include "bibliotecas.h"
#include "menu.h"

void exibirMenu() {
    cout << "Bem-Vindo/a ao Jogo do Bingo!\n";
    cout << "1 - Criar carta\n";
    cout << "2 - Sair\n";
    cout << "\nEscolha uma opção: ";
}

void processarOpcao(Bingo& jogo, int opcao) {
    switch (opcao) {
        case 1:
            jogo.criarNovaCarta();
            // Sorteia números automaticamente
            while (!jogo.verificarVencedor()) {
                system("clear");
                jogo.exibirCarta();
                jogo.sortearNumero();
                this_thread::sleep_for(chrono::seconds(2)); // Delay de 2 segundos
            }
            system("clear");
            cout << "\t\tBingo!\n\n";
            jogo.exibirCartaBingo(); // Exibe a cartela com os números do bingo em negrito
            cout << "\nA voltar para o menu em 20 segundos..." << endl;
            this_thread::sleep_for(chrono::seconds(20)); // Delay de 20 segundos
            break;
        case 2:
            system("clear");
            cout << "A sair...\n";
            break;
        default:
            cout << "Opção inválida. Tente novamente.\n";
            break;
    }
}