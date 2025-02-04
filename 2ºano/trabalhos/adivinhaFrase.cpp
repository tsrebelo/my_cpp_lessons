#include <iostream>
using namespace std;

void frase(){

    string frase;
    string entrada;
    bool acertou = false;

    cout << "Insira uma frase:";
    getline(cin.ignore(), frase);

    string linhas(frase.size(), '_');


}

int main(){

    system("clear");
    cout << "Bem-Vindo/a ao jogo do Adivinha a Frase!\n" << endl;

    frase();

    return 0;
 }