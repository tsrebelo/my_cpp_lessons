/**
 *
 * @file parte_3.cpp
 * @author Telma Rebelo
 * @brief Parte 3 - Ciclo for (Tabuada)
 * @date 24-02-18
 * 
*/

#include <iostream>
using namespace std;

//Ciclo for - Tabuada
int n;

int main(){
    
    cout << "Esta é uma tabuada digital." << endl;
    cout << "Escolha um número entre 0 e 10: ";
    cin >> n;
    
    for(int i = 0; i <= 10; i++){
        cout << n << "x" << i << "=" << n * i << endl;
    }
    
    return 0;
}
