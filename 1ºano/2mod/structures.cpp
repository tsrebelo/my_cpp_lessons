#include <iostream>
using namespace std;

/*
typedef struct{                     /cria uma estrutura 
    string nomeBolo;                /string para definir o nome do bolo
    double pesoBolo;                /usa-se 'double' porque o resultado não é um número inteiro
    double precoBolo;               /usa-se 'double' porque o resultado não é um número inteiro
} boloBool;                         /

boloBool bolos[]= {};               /array de bolos
*/

struct bolo{                        //'struct' cria uma estrutura
    string nomeBolo;                //string para definir o nome do bolo
    double pesoBolo;                //usa-se 'double' porque o resultado não é um número inteiro
    double precoBolo;               //usa-se 'double' porque o resultado não é um número inteiro
};

string nome, peso, preco;

bolo bolos[] = {};                  //array de bolos


int main(){

 
    bolo produto;
    produto.nomeBolo    = "Bolo de Chocolate";
    produto.precoBolo   = 10.00;
    produto.pesoBolo    = 1;

    bolos[0] = produto;


    // cout << "Nome: " << bolos[0].nomeBolo << endl;
    // cout << "Preço: " << bolos[0].precoBolo << endl;
    // cout << "Peso: " << bolos[0].pesoBolo << endl;


    // for(int n = 1; n <= 6; n++){
    //    bolos[n]=produto;
    // }

    cout << "Olá! Vamos fazer a nossa receita!" << endl;
    cout << "Que nome tem este bolo? ";
    cin >> nome;
    cout << "Quanto custa este bolo? ";
    cin >> preco;
    cout << "Quanto pesa este bolo? ";
    cin >> peso;

    bolos[1].nomeBolo = nome;
    bolos[1].precoBolo = stod(preco);
    bolos[1].pesoBolo = stod(peso);

    for(int x = 0; x <=sizeof(bolos) ; x++){
        cout << "O nome do teu bolo é " << bolos[1].nomeBolo << endl;
        cout << "O preço do teu bolo é " << bolos[1].precoBolo << endl;
        cout << "O peso do teu bolo é " << bolos[1].pesoBolo << endl;
    }

    return 0;
}