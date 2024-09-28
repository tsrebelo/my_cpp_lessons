/**
 *
 * @file parte_1.cpp
 * @author Telma Rebelo
 * @brief Parte 1 - Calculadora básica e Constantes
 * @date 24-02-18
 * 
*/

#include <iostream>
using namespace std;

int a;
int b;
const double PI = 3.14159;
int r;
int area;

int main(){

//Calculadora básica
    cout << "Introduza o primeiro valor: ";
    cin >> a;
    
    cout << "Introduza o segundo valor: ";
    cin >> b;
    
    cout << "A soma: " << a + b << endl;
    cout << "A diferença: " << a - b << endl;
    cout << "O produto: " << a * b << endl;
    cout << "A divisão: " << a / b << endl;
    cout << "O resto da divisão: " << a % b << endl;

cout << endl;

//Constantes
    cout << "Vamos calcular a área do circulo!" << endl;
    cout << "Defina o valor de 'r': ";
    cin >> r;
    
    area = PI * r * r;
    cout << "A área do circulo é: " << area << endl;
  
    return 0;
}
