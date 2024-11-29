#include <iostream>
#include <vector>
using namespace std;

vector<int> numeros = {6, 7, 3, 2, 9};

int main(){

    system("clear");

    cout << "-----------------------------------------------------" << endl;
    cout << "Todos os elementos: ";
    
    for(int num : numeros){ // : -> in
        cout << num << " ";
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    
    cout << "Primeiro elemento: " << numeros.front() << endl; 
    cout << "-----------------------------------------------------" << endl;
    cout << "Último elemento: " << numeros.back() << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Elemento na posição 1: " << numeros.at(1) << endl; 
    cout << "-----------------------------------------------------" << endl;

    numeros.erase(numeros.begin() + 2); // remove o elemento na posição 2 (o valor 3)

    cout << "Todos os elementos após remoção: ";
    for(int num : numeros){ 
        cout << num << " ";
    }

    cout << endl;
    cout << "-----------------------------------------------------" << endl;

    return 0;
}
