#include "bibliotecas.h"
#include "cores.h"
#include "bingo.h"

CartaBingo gerarCarta() {
    CartaBingo carta;
    carta.numeros.resize(5, vector<int>(5));

    for (int col = 0; col < 5; col++) {
        vector<int> numerosColuna;
        int inicio = 1 + col * 15;
        int fim = inicio + 15;

        for (int i = inicio; i < fim; i++) {
            numerosColuna.push_back(i);
        }

        random_shuffle(numerosColuna.begin(), numerosColuna.end());
        for (int linha = 0; linha < 5; linha++) {
            carta.numeros[linha][col] = numerosColuna[linha];
        }
    }

    carta.numeros[2][2] = 0;
    return carta;
}

void salvarCarta(const CartaBingo& carta, const string& arquivo) {
    ofstream arquivoSaida(arquivo);
    arquivoSaida << "B\tI\tN\tG\tO\n";
    for (const auto& linha : carta.numeros) {
        for (int num : linha) {
            if (num == 0) {
                arquivoSaida << "X\t";
            } else {
                arquivoSaida << num << "\t";
            }
        }
        arquivoSaida << "\n";
    }
    arquivoSaida.close();
}

void exibirTabela(const vector<int>& numerosSorteados) {
    cout << BOLD << CYAN << "Tabela de Números (1 a 75):\n" << RESET;
    for (int i = 1; i <= 75; i++) {
        if (find(numerosSorteados.begin(), numerosSorteados.end(), i) != numerosSorteados.end()) {
            cout << BOLD << i << RESET << "\t";
        } else {
            cout << i << "\t";
        }

        if (i % 15 == 0) {
            cout << "\n";
        }
    }
    cout << "\n";
}

void iniciarJogo(bool automatico) {
    vector<int> numerosSorteados;
    vector<int> todosNumeros;

    for (int i = 1; i <= 75; i++) {
        todosNumeros.push_back(i);
    }
    random_shuffle(todosNumeros.begin(), todosNumeros.end());

    while (!todosNumeros.empty()) {
        system("clear");

        int numeroAtual = todosNumeros.back();
        todosNumeros.pop_back();
        numerosSorteados.push_back(numeroAtual);

        cout << BOLD << BLUE << "Últimos cinco números sorteados: ";
        int inicio = (numerosSorteados.size() > 5) ? numerosSorteados.size() - 5 : 0;
        for (int i = numerosSorteados.size() - 1; i >= inicio; i--) {
            cout << numerosSorteados[i] << " ";
        }
        cout << RESET << "\n";

        cout << BOLD << MAGENTA << "Número atual sorteado: " << numeroAtual << RESET << "\n\n";
        exibirTabela(numerosSorteados);

        if (automatico) {
            this_thread::sleep_for(chrono::seconds(2));
        } else {
            cout << "Pressione ENTER para sortear o próximo número...";
            cin.ignore();
        }
    }

    system("clear");
    cout << BOLD << GREEN << "\n\n\nTODOS OS NÚMEROS FORAM SORTEADOS!\n";
    cout << "\t  FIM DO JOGO!\n\n" << RESET;
    cout << "Pressione ENTER para voltar ao menu...";
    cin.ignore();
}
