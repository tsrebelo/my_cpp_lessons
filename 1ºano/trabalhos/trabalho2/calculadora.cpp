#include <iostream>
using namespace std;

int main(){

string num1;
string num2;
string resultado;
char operacao;


    cout << "Digite o primeiro número: " << endl;
    cin >> num1;
    cout << "Digite o segundo número: " << endl;
    cin >> num2;
    cout << "Escolha a operação (+, -, *, /): " << endl;
    cin >> operacao;

    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else{
                cout << "ERRO: Divisão por zero." << endl;
            }
            break;
        default:
            cout << "Operação inválida." << endl;
    }
    return 0;
}
