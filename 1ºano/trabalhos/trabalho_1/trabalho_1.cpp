#include <iostream>

using namespace std; 

void parte1(){
    int a;
    int b;
    const double PI = 3.14159;
    int r;
    int area;

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
}


void parte2(){

float notas[5];
float soma = 0;
float media = 0;

    cout << "Introduza as notas." << endl;
    for(int v = 0; v < 5; v++){
        cout << "NOTA: ";
        cin >> notas[v];
    }
cout << endl;

    for(int t = 0; t < 5; t++){
        soma += notas[t];
        media = soma;
    }

float maiorNota = notas[0];
    for(int x = 0; x < 5; x++){
        if(notas[x] > maiorNota){
            maiorNota = notas[x];
        }
    }
    cout << "A maior nota é " << maiorNota << "." << endl;
    
float menorNota = notas[0];
    for(int y = 0; y < 5; y++){
        if(notas[y] < menorNota){
            menorNota = notas[y];
        }
    }
    cout << "A menor nota é " << menorNota << "." << endl;
cout << endl;
    

//Array[10]
int arr[10] = {59, 31, 49, 51, 28, 72, 89, 52, 63, 24};
    cout << "Os números são: " << endl;
    
    for(int z = 0; z < 10; z++){
        cout << arr[z] << " ";
    }
cout << endl;
cout << endl;

int maiorArr = arr[0];
    for(int a = 0; a < 10; a++){
        if(arr[a] > maiorArr){
            maiorArr = arr[a];
        }
    }
    cout << "O maior número é " << maiorArr << "." << endl;
    
int menorArr = arr[0];
    for(int b = 0; b < 10; b++){
        if(arr[b] < menorArr){
            menorArr = arr[b];
        }
    }
    cout << "O menor número é " << menorArr << "." << endl;
}


void parte3(){
//Ciclo for - Tabuada
int n;
    
    cout << "Esta é uma tabuada digital." << endl;
    cout << "Escolha um número entre 0 e 10: ";
    cin >> n;
    
    for(int i = 0; i <= 10; i++){
        cout << n << "x" << i << "=" << n * i << endl;
    }
}

void menu(){

    system("clear");
    int opcao;
    cout << "=====================" << endl;
    cout << "         MENU" << endl;
    cout << "=====================" << endl;
    cout << "1 - Calculadora" << endl;
    cout << "2 - Arrays" << endl;
    cout << "3 - Tabuada" << endl;
    cout << "=====================" << endl;
    cout << "Insira a sua opção: ";
    cin >> opcao;
    switch(opcao){
        case 1:
        parte1();
            break;
        case 2:
        parte2();
            break;
        case 3:
        parte3();
            break;
        default:
            break;
    }
}

int main(){

    menu();

    return 0;
}