#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 6;

void exibirMapa(string mapa[SIZE][SIZE]){
    for(int x = 1; x < SIZE; x++){
        for (int y = 1; y < SIZE; y++){
            cout << mapa[x][y] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    string mapa[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            mapa[i][j] = "⬜️";
        }
    }

    int tesouroX = rand() % SIZE;
    int tesouroY = rand() % SIZE;

    system("clear");
    cout << "Bem-vindo ao jogo de Caça ao Tesouro!" << endl;
    cout << "O tesouro está escondido em algum lugar no mapa.\n" << endl;

    int tentativaX, tentativaY;
    bool encontrouTesouro = false;

    while(!encontrouTesouro){
        
        cout << "Tente adivinhar as coordenadas (linha e coluna) para encontrar o tesouro." << endl;
        cout << "Mapa (5x5):" << endl;
        exibirMapa(mapa);

        cout << "Digite a linha (1-5): ";
        cin >> tentativaX;
        cout << "Digite a coluna (1-5): ";
        cin >> tentativaY;

        if(tentativaX < 0 || tentativaX >= SIZE || tentativaY < 0 || tentativaY >= SIZE){
            system("clear");
            cout << "Coordenada inválida. Tente novamente!" << endl;
            continue;
        }

        if(tentativaX == tesouroX && tentativaY == tesouroY){
            mapa[tentativaX][tentativaY] = "💰"; 
            encontrouTesouro = true;
            system("clear");
            cout << "Parabéns! Você encontrou o tesouro!" << endl;
            exibirMapa(mapa);
        } else{
            mapa[tentativaX][tentativaY] = "🟥"; 
            system("clear");
            cout << "Não há tesouro nessa coordenada. Tente novamente!" << endl;
        }
    }

    return 0;
}