/**
 *
 * @file parte_2.cpp
 * @author Telma Rebelo
 * @brief Parte 2 - Arrays
 * @date 24-02-18
 * 
*/

#include <iostream>
using namespace std;

float notas[5];
float soma = 0;
float media = 0;

int main(){

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
    
    return 0;
}
