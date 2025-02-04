#include <iostream>
#include <iomanip>
using namespace std;

float calculaIMC(float peso, float altura){
    return peso / (altura * altura);
}

string categoriaIMC(float imc){
    if(imc < 18.5){
        return "Peso baixo";
    } else if(imc >= 18.5 && imc < 24.9){
        return "Peso normal";
    } else if(imc >= 25.00 && imc < 29.9){
        return "Sobrepeso";
    } else if(imc >= 30.00 && imc < 34.9){
        return "Obesidade grau I";
    } else if(imc >= 35.00 && imc < 39.9){
        return "Obesidade grau II";
    } else{
        return "Obesidade grau III";
    }
}

int main(){
    float altura, peso;

    system("clear");
    cout << "Calculadora de IMC (Índice de Massa Corporal)\n" << endl;
    cout << "Por favor, insira o seu peso (kg): ";
    cin >> peso;
    cout << "Por favor, isira a sua altura (m): ";
    cin >> altura;

    float imc = calculaIMC(peso, altura);

    system("clear");
    cout << fixed << setprecision(2);

    cout << "O seu IMC é: " << imc << endl;
    cout << "Categoria: " << categoriaIMC(imc) << endl;

    return 0;
}