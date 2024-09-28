#include <iostream>
using namespace std;

long a,b;
const double PI = 3.14159265358979323846;
int myArr[5];
int r;

int main(){

//CALCULADORA
/*
    cout << "Digite o valor de a: ";
    cin >> a;
    cout << "Digite o valor de b: ";
    cin >> b;
    cout << "A soma de a e b é: " << a+b << endl;
    cout << "A subtração de a e b é: " << a-b << endl;
    cout << "A multipicação de a e b é: " << a*b << endl;
    if(b != 0){
        cout << "A divisão de a e b é: " << a/b << endl;
    }else{
        double c = a/(double)b;
        cout << "Não é possível dividir por zero!" << endl;
        cout << "O resto da divisão de a e b é: " << a%b << endl;
    }
*/

//CÁLCULO DA ÁREA
/*
    cout << "Digite o valor do raio: ";
    cin >> r;
    cout << "A área do círculo é ≃ " << PI*r*r << endl;
*/

//Arrays
float soma=0;
float maior=0;
float menor=0;

cout << "Digite as notas dos alunos.\n" << endl;
    for(int i=0; i<5; i++){
        cout << "A nota do aluno " << i << " é: ";
        cin >> myArr[i];
        soma += myArr[i];
    }if(i==0){
        maior = myArr[i];
        menor = myArr[i];
    } else {
        if(myArr[i] > maior){
            maior = myArr[i];
        }
        if(myArr[i] < menor){
            menor = myArr[i];
        }
    }
cout << endl;

cout << "A soma das notas é: " << soma << endl;


/*
cout << "Digite as notas dos alunos.\n" << endl;
    for(int i=0; i<5; i++){
        cout << "A nota do aluno " << i << " é: ";
        cin >> myArr[i];
    }
cout << endl;
*/

    return 0;
}