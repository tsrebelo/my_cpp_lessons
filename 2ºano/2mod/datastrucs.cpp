#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

vector<int> numeros = {6, 7, 3, 2, 9};

map<string, int> mapa = {

    {"um", 1},
    {"dois", 2},
    {"três", 3},
    {"quatro", 4},
    {"cinco", 5},
    {"seis", 6},
    {"sete", 7},
    {"oito", 8},
    {"nove", 9},
    {"dez", 10}

};

void vectorr(){

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
}

void mapaa(){

    system("clear");
    cout << mapa["um"] << endl;

}

int main(){

    vectorr();
    mapaa();

    return 0;
}
