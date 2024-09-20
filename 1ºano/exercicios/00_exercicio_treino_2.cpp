#include <iostream>
using namespace std;

void multiplica(int n){
    for(int x=0; x<=10; x++){
        cout << n << " x " << x << " = " << n*x << endl;
    }
}

int main(){

    int p;
    cout << "Insira o número a multiplicar entre 0 e 10: ";
    cin >> p;
    multiplica(p);

}