/**
 * @author Telma Silva Rebelo e Martim Valério
 * @date 07-02-2025
 */

#include <iostream>
using namespace std;

string frase, adivinha;
string entrada;
char letra;

void joguin(){

    cout << "Insira uma frase: ";
    getline(cin, frase);

    for(char n : frase){
        if(n != ' '){
            adivinha += '_'; 
        }else{
            adivinha += ' '; 
        }
    }

    system("clear");

    cout << "Adivinhe a frase!" << endl;

    while(adivinha != frase){

        cout << "Frase a ser adivinhada: " << adivinha << endl;
        cout << "Digite uma letra ou a frase inteira: ";
        getline(cin, entrada);
        bool entradaCorreta = false;

        if(entrada.size() == 1){
            letra = entrada[0];
            entradaCorreta = false;

            for(int i = 0; i < frase.size(); i++){
                if (frase[i] == letra){
                    adivinha[i] = letra;
                    entradaCorreta = true;
                }
            }

            if(!entradaCorreta){
                system("clear");
                cout << "Errou a letra!\n" << endl;

            } else{
                system("clear");
                cout << "Acertou a letra!\n" << endl;
            } 
        }

        else{
            if (entrada == frase){
                adivinha = frase; 
                break;
            } else{
                system("clear");
                cout << "Frase incorreta! \n" << endl;
            }
        }
    }
    system("clear");
    cout << "Parabéns acertou a frase: " << frase << endl;
}

int main(){

    system("clear");
    cout << "Bem-vindo/a ao Jogo do Adivinha!\n" << endl;
    joguin();

    return 0;
}