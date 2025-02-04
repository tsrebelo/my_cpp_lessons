#include <iostream>
using namespace std;

int main(){
    system("clear");
    string frase, adivinha;
    string entrada;
    char letra;

    cout << "Insira uma frase: ";
    getline(cin, frase);

    for(char x : frase){
        if(x != ' '){
            adivinha += '_'; 
        }else{
            adivinha += ' '; 
        }
    }

    cout << "\nAdivinhe a frase!" << endl;

    while(adivinha != frase){

        cout << "\nFrase a ser adivinhada: " << adivinha << endl;
        cout << "Digite uma letra: ";
        cin >> entrada;
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

                cout << "Errou a letra!\n" << endl;

            } else{
                cout << "Acertou a letra!\n" << endl;
            } 
        }

        else{
            cout << "Frase incorreta!\n" << endl;
        }

    }

    cout << "Parabéns acertou a frase! " << frase;


    return 0;
}
