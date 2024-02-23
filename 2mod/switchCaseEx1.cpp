#include <iostream>
using namespace std;

void soma(int a, int b){
    cout << a + b << endl;
}

void mult(int a, int b){
    cout << a * b << endl;
}

void divi(int a, int b){
    cout << a / b << endl;
}

void restDiv(int a, int b){
    cout << a % b << endl;
}

void menu(){

    system("clear");
    cout << "======================" << endl;
    cout << "         MENU" << endl;
    cout << "======================" << endl;
    cout << "1 - Soma " << endl;
    cout << "2 - Multiplicação " << endl;
    cout << "3 - Divisão " << endl;
    cout << "4 - Resto da divisão " << endl;
    cout << "======================" << endl;
}

int getOpcao(){
    int opcao;
    cout << "Digite a sua opção: ";
    cin >> opcao;

    return opcao;
}

void executaCalculo(int opcao, int x, int y){

    switch(opcao){
        case 1:
        soma(x, y);
            break;

        case 2:
        mult(x, y);
            break;

        case 3:
            divi(x, y);
            break;

        case 4:
        restDiv(x, y);
            break;

        default:

            break;

    }
}

int getValorX(){

    int x;
    cout << "Digite o valor de X: ";
    cin >> x;

    return x;
}

int getValorY(){

    int y;
    cout << "Digite o valor de y: ";
    cin >> y;

    return y;
}

int main(){

    menu();

    return 0;
}