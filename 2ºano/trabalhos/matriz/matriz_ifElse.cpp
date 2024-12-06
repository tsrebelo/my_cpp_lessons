#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void matriz(int dim){

    system("clear");
    int count = 0;

    for(int i=0; i<dim; i++){  
        for(int n=0; n<dim; n++)  
            cout << setw(5) << ++count; 
        cout << endl;
    }
    cout << endl;
}

int main() {

    system("clear");

    int dim;

    cout << "Digite a dimensão da matriz: ";
     cin >> dim;

    if (cin.fail()) {
        
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Entrada inválida! Por favor, insira um número inteiro." << endl;

            return 1;
        } else {

            matriz(dim);
        }

    return 0;
}
