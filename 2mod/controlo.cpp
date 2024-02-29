#include <iostream>
using namespace std;

/**
 * @brief Função que calcula a soma dos números até um determinado limite
 * @param limite - limite para a soma
 * @return soma dos números até ao limite
*/

int somaNumeros(int limite){

    int soma = 0;
    for(int x = 1; x <= limite; x++){
        soma += x;
    }
    return soma;
}

int getLimite(){

    int limite;
    cout << "Qual o limite que V. Exa. quer: ";
    cin >> limite;

    return limite;
}

int main(){

    system("clear");
    int limite;
    limite = getLimite();
    cout << "Total: " << somaNumeros(limite) << endl;

    return 0;
}
