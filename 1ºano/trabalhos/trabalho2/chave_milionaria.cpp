#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){

    srand((unsigned) time(0));

    char resposta;
    int i;
    int s;
    int S;
    int n;
    int N;

    do{
        int chave[5];
        int estrelas[2];

        for(i = 0; i < 5; i++){
            chave[i] = 1+(rand()%50);
        }
    sort(chave, chave + 5);
    system("clear || cls");

        for(i = 0; i < 2; i++){
            estrelas[i] = 1+(rand()%12);
        }
    sort(estrelas, estrelas + 2);
    system("clear || cls"); 

    cout << "Chave: " ;
        for(i = 0; i < 5; i++){
            cout << chave[i] << " " ;
    }
    cout << endl;

    cout << "Estrelas: " ;
        for(i = 0; i < 2; i++){
            cout << estrelas[i] << " " ;
    }
    cout << endl;

    cout << "Deseja gerar uma nova chave? (s/n)" << endl;
    cin >> resposta;
    
    } while ( resposta == 's' | resposta == 'S');
    if (resposta == 'n' | resposta == 'N'){
        cout << "Obrigada por jogar!" << endl;
    }

    return 0;
}