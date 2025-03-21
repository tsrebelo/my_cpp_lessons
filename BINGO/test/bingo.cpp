#include "bibliotecas.h"
#include "bingo.h"

CartaBingo gerarCarta() {
    CartaBingo carta;
    carta.numeros.resize(5, vector<int>(5));

    // Preenche cada coluna com números no intervalo correto
    for (int col = 0; col < 5; col++) {
        vector<int> numerosColuna;
        int inicio = 1 + col * 15;
        int fim = inicio + 15;

        // Gera todos os números possíveis para a coluna
        for (int i = inicio; i < fim; i++) {
            numerosColuna.push_back(i);
        }

        // Embaralha e seleciona os 5 primeiros
        random_shuffle(numerosColuna.begin(), numerosColuna.end());
        for (int linha = 0; linha < 5; linha++) {
            carta.numeros[linha][col] = numerosColuna[linha];
        }
    }

    // Espaço livre no centro (N)
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
            cout << BOLD << MAGENTA << i << RESET << "\t"; // Número sorteado em rosa
        } else {
            cout << i << "\t"; // Número não sorteado
        }

        if (i % 15 == 0) {
            cout << "\n"; // Nova linha a cada 15 números
        }
    }
    cout << "\n";
}

void iniciarJogo(bool automatico) {
    vector<int> numerosSorteados;
    vector<int> todosNumeros;

    // Gera todos os números possíveis (1 a 75)
    for (int i = 1; i <= 75; i++) {
        todosNumeros.push_back(i);
    }
    random_shuffle(todosNumeros.begin(), todosNumeros.end());

    while (!todosNumeros.empty()) {
        system("clear");

        // Sorteia um número
        int numeroAtual = todosNumeros.back();
        todosNumeros.pop_back();
        numerosSorteados.push_back(numeroAtual);

        // Exibe os últimos números sorteados
        cout << BOLD << BLUE << "Últimos cinco números sorteados: ";
        int inicio = (numerosSorteados.size() > 5) ? numerosSorteados.size() - 5 : 0;
        for (size_t i = inicio; i < numerosSorteados.size(); i++) {
            cout << numerosSorteados[i] << " ";
        }
        cout << RESET << "\n";

        // Exibe o número atual
        cout << BOLD << MAGENTA << "Número atual sorteado: " << numeroAtual << RESET << "\n\n";

        // Exibe a tabela de números
        exibirTabela(numerosSorteados);

        // Pausa ou espera pelo ENTER
        if (automatico) {
            this_thread::sleep_for(chrono::seconds(2)); // Pausa de 2 segundos
        } else {
            cout << "Pressione ENTER para sortear o próximo número...";
            cin.ignore();
            cin.get();
        }
    }

    cout << BOLD << GREEN << "Todos os números foram sorteados! Fim do jogo.\n" << RESET;
}