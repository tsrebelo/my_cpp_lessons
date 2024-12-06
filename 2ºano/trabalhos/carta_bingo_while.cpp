#include <iostream>
#include <iomanip>
#include <limits>  
using namespace std;

void matriz(int dim){

    system("clear");
    int count = 0;

    cout << "Tipo de dado de 'dim': " << typeid(dim).name() << endl;

    for(int i=0; i<dim; i++){  
        for(int n=0; n<dim; n++)  
            cout << setw(5) << ++count; 
        cout << endl;
    }
    cout << endl;
}

int main() {

    int dim;

    while (true) {
        cout << "Digite a dimensão da matriz (um número inteiro): ";
        cin >> dim;

        if (cin.fail()) {
        
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida! Por favor, insira um número inteiro." << endl;
        } else {
            
            break;
        }
    }

    matriz(dim);

    return 0;
}
