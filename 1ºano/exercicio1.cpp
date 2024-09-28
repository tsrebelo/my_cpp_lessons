#include <iostream>
using namespace std;


/**
 * Exercício #1 (15 minutos para completar)
 * 
 * Crie uma função capaz de ler os dados de uma matriz
 * quadrada de inteiros. Ao final da leitura o programa
 * deverá imprimir o número da linha que contém o menor
 * dentre todos os números lidos. 
 */

int arr[3][3] = {{1, 5, 3},
                 {2, 5, 1},
                 {7, 5, 9}};

/**
 * @brief Function that reads a square matrix of integers
 *          and prints the line with the lowest number
*/
void readMatriz(int array[][3], int size){

    int lower = array[0][0];
    int line = 0;

    for(int i = 0; i < size; i++){
        for(int n = 0; n < size; n++){
            if(array[i][n] < lower){

                lower = array[i][n];
                //line = i;
            } 
        }
    }

    cout << "The lower number is: " << lower << endl;
    //cout << "The line is: " << line + 1 << endl;
};

void shorArr(int n){

    for(int l = 0; l < n; l++){
        for(int c = 0; c < n; c++){

            cout << arr[l][c];

        }
        cout << endl;
    }

};

int main(){

    system("clear");
    //shorArr(3);
    readMatriz(arr, 3);

    int n=0;
    n==10 ? cout << "sim" : cout << "não";
    
    return 0;
}

