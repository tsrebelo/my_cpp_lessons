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

int main(){

    cout << "Total: " << somaNumeros(10) << endl;

    return 0;
}