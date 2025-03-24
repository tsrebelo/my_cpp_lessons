#include <iostream>
#include <iomanip>
using namespace std;

void graficoHorizontal(int x, int y, int z){

    system("clear");

    cout << "Valor de x: ";
    cin >> x;
    cout << "---------------" << endl;
    cout << "Valor de y: ";
    cin >> y;
    cout << "---------------" << endl;
    cout << "Valor de z: ";
    cin >> z;

    int maior = x;

    if (maior < y) maior = y;
    if (maior < z) maior = z;

    int x1 = x;
    int y1 = y;
    int z1 = z;

    x = x * 50 / maior;
    y = y * 50 / maior;
    z = z * 50 / maior;

    system("clear");

    cout << "------------------------------------------------------------------------------" << endl;
    cout << "x: " << setw(2) << x1 <<" ";
    while (x > 0){
        cout << "*";
        x--;
    }

    cout << "\n------------------------------------------------------------------------------" << endl;

    cout << "y: "<< setw(2) << y1 <<" ";
    while (y > 0){
        cout << "*";
        y--;
    }

    cout << "\n------------------------------------------------------------------------------" << endl;

    cout << "z: " << setw(2) << z1 <<" ";
    while (z > 0){
        cout << "*";
        z--;
    }

    cout << "\n------------------------------------------------------------------------------" << endl;
    cout << endl;

}

int main(){

    int x, y, z;
    graficoHorizontal(x, y, z);
    
    return 0;
}