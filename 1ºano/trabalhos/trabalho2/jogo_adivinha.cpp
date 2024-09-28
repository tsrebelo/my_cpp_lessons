#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){

    int num = 0;
    srand((unsigned) time(0));
    int numSorte = 1+(rand()%100);
    string name;
    int numTentativasMaximas = 5;
    int numTentativas = 0;

    cout << "Insere o teu nome: " << endl;
    cin >> name;
  
    while (numSorte != num && numTentativas < numTentativasMaximas){
        
        cout << "Qual é o número da sorte?" << endl;
        cin >> num;

        numTentativas ++;
        
        if (numSorte > num){
            cout << "O número é maior que:" << num << endl;

        } else if (numSorte < num){
            cout << "O número é menor que:" << num << endl;

        } else{
            cout << "Parabéns " << name << " acertaste o número!" << endl;
            break;
        }
        if (numTentativas == numTentativasMaximas){
            cout << "Quase acertaste " << name << "!" << endl;
            cout << "O número da sorte era:" << numSorte << endl;
        }
    }
        cout << "Fim do jogo!" << endl;
    return 0;
}