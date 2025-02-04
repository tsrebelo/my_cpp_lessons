#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 6; // Tamanho do mapa (matriz 5x5) deixando de parte o 0

void exibirMapa(string mapa[SIZE][SIZE]) {
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Para garantir que as posições sejam aleatórias a cada execução

    // Inicializando o mapa
    string mapa[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            mapa[i][j] = "⬜️"; // Marca as posições como água
        }
    }

    // Gerando a posição aleatória do tesouro
    int tesouroX = rand() % SIZE;
    int tesouroY = rand() % SIZE;

    // Exibindo as instruções do jogo
    cout << "Bem-vindo ao jogo de Caça ao Tesouro!" << endl;
    cout << "O tesouro está escondido em algum lugar no mapa." << endl;
    // Loop principal do jogo
    int tentativaX, tentativaY;
    bool encontrouTesouro = false;

    while (!encontrouTesouro) {
        system("clear");
        cout << "Tente adivinhar as coordenadas (linha e coluna) para encontrar o tesouro." << endl;
        cout << "Mapa (5x5):" << endl;
        exibirMapa(mapa);

        // Pedir as coordenadas do jogador  
        cout << "Digite a linha (1-5): ";
        cin >> tentativaX;
        cout << "Digite a coluna (1-5): ";
        cin >> tentativaY;

        // Verificar se a coordenada está dentro do mapa
        if (tentativaX < 0 || tentativaX >= SIZE || tentativaY < 0 || tentativaY >= SIZE) {
            cout << "Coordenada inválida. Tente novamente!" << endl;
            continue;
        }

        // Verificar se o jogador encontrou o tesouro
        if (tentativaX == tesouroX && tentativaY == tesouroY) {
            mapa[tentativaX][tentativaY] = "💰"; // Marca o tesouro no mapa
            encontrouTesouro = true;
            system("clear");
            cout << "Parabéns! Você encontrou o tesouro!" << endl;
            exibirMapa(mapa);
        } else {
            mapa[tentativaX][tentativaY] = "🟥"; // Marca a tentativa no mapa
            cout << "Não há tesouro nessa coordenada. Tente novamente!" << endl;
        }
    }

    return 0;
}