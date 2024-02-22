#include <iostream>
using namespace std;

void opcao1(){
        cout << " n é 1 " << endl;
}

void opcao2(){
        cout << " n é 2 " << endl;
}

void opcao3(){
        cout << " n é 3 " << endl;
}

int main(){

    int n = 1;
    cin >> n;
    switch(n){
        case 1:
            opcao1();
        break;

        case 2:
            opcao2();
        break;

        case 3:
            opcao3();
        break;

        default:
        cout << " n é diferente de 1, 2 e 3 " << endl;
            break;
    }

    return 0;
}

