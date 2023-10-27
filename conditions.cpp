#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


/*
int a = 10, b = 12, c = 9;

int main(){

    if (a < b ){                                        // "||" esse ou outro, "&&" e outro
        cout << "é verdade" << endl;
    }else if (a<c){
        cout << "é verdade" << endl;
        }else{
            cout << "é mentira" << endl;
    }



    return 0;
}
*/



/**
 * @brief peça um número e mostre se ele é positivo ou negativo
 * 
 * @return int
*/

/*
int main(){
    
    int num;

    cout << "Digite umn número: ";
    cin >> num;

    if(num >= 0){
        cout << "é positivo" << endl;
    }else{
        cout << "é negativo" << endl;
    }
    return 0;
}
*/

/*
int main(){
    
    int num;
    cout << "Digite um número: " << endl;
    cin >> num;

    switch (num)
    {
        case 1:
        cout << "O número é 1" << endl;
        break;

        case 2:
        cout << "O número é 2" << endl;
        break;

    default:
        cout << "O número não é 1 nem é 2" << endl;
        break;
    }
    return 0;
}
*/

/*
int main(){
    
    int num;
    int result;
    cout << "Digite um número: " << endl;
    cin >> num;

    result = num % 2;

    switch (result)
    {
        case 0:
        cout << "O número é par" << endl;
        break;

    default:
        cout << "O número não é par" << endl;
        break;
    }
    return 0;
}
*/

/*
int main(){
    
    int num=0;


    while(num < 5){
        cout << "Digite um número: " << endl;
        cin >> num;
    }

    return 0;
}
*/

/*
int main(){
    
    int numSorte=22;
    int num=0;
    while(numSorte != num){
        cout << "Digite um número: " << endl;
        cin >> num;
    }
    cout << "Parabéns, você acertou!" << endl;
    return 0;
}
*/

/*
int main(){
    
    int numSorte=22;
    int num=0;
    while(numSorte != num){
        cout << "Qual é o número da sorte?" << endl;
        cin >> num;
        if(numSorte > num){
            cout << "O número da sorte é maior do que:" << num << endl;
        }else if(numSorte < num){
            cout << "O número da sorte é menor do que:" << num << endl;
        }else{
            cout << "Parabéns, você acertou!" << endl;
        }
    }
    cout << "Acabou o jogo!" << endl;
    return 0;
}
*/

/*
rand = aleatório

int main(){
    
    int numSorte = 1+(rand()%100);
    int num = 0;

    while(numSorte != num){
        cout << "Qual é o número da sorte?" << endl;
        cin >> num;
        if(numSorte > num){
            cout << "O número da sorte é maior do que:" << num << endl;
        }else if(numSorte < num){
            cout << "O número da sorte é menor do que:" << num << endl;
        }else{
            cout << "Parabéns, você acertou!" << endl;
        }
    }
    cout << "Acabou o jogo!" << endl;

    return 0;
*/

/*
int main(){
    
    int num = 0;
    srand((unsigned) time(0));
    
    int numSorte = 1+(rand()%100);
    

    while(numSorte != num){
        cout << "Qual é o número da sorte?" << endl;
        cin >> num;
        if(numSorte > num){
            cout << "O número da sorte é maior do que:" << num << endl;
        }else if(numSorte < num){
            cout << "O número da sorte é menor do que:" << num << endl;
        }else{
            cout << "Parabéns, você acertou!" << endl;
        }
    }
    cout << "Acabou o jogo!" << endl;

    return 0;
}
*/

int main(){
    
    int num = 0;
    int numTentativasMáximas = 5;
    int tentativas = 0;
    srand (static_cast<unsigned> (time(0)));
    int name;
    int numSorte = 1+(rand()%100);
    
        cout << "Qual é o teu nome?" << endl;
        cin >> name;
    while(numSorte != num && tentativas < numTentativasMáximas){
        cout << "Tentativa #" << tentativas + 1 << "Qual é o número da sorte?" << endl;
        cin >> num;
        if(numSorte > num){
            cout << "O número da sorte é maior do que:" << num << endl;
        }else if(numSorte < num){
            cout << "O número da sorte é menor do que:" << num << endl;
        }else{
            cout << "Parabéns, você acertou!" << endl;
            break;
        }
        tentativas++;
    }
        if (tentativas == numTentativasMáximas){
    cout << "Quase lá! O número que tinhas de colocar era:" << numSorte << endl;
        }

    return 0;
}