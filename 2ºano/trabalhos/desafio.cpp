#include <iostream>
using namespace std;

int main(){

    const int XPTO = 123;


    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};


    for(int x=100; x>=0; x-=5){
        cout << x << endl;
    }


    for(int i=0; i<=100; i+=5){
        cout << i << endl;
    }


    int n = 0;
    while(n < 100){
        n++;
        cout << n << endl;
    }

    int option;
    switch (option){
        case 1:
            cout << "Opção 1" << endl;
            break;
        
        case 2:
            cout << "Opção 2" << endl;
            break;
        
        default:
            cout << "Erro" << endl;
            break;
        }


    int a = 2;
    int b = 5;
    if(a >= 5 || b >= 5){
        cout << "true" << endl;
    }

    return 0;
}