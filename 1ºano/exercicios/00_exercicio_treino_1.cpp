#include <iostream>
using namespace std;

int somaImpares(int x){
    
    int sum = 0;
    for(int i=0; i<=x; i++){
        if(i%2 != 0){
            sum+=i;
        }
    }
    return sum;
}

int main(){
    int n;
    cout << "Insira o valor de 'n': ";
    cin >> n;
    int resultado = somaImpares(n);
    cout << "O resultado é: " << resultado << endl;

    return 0;
}