#include <iostream>
using namespace std;                            //resulta como uma fronteira

int somaNumeros(int x, int y){
    return x+y;
}


double somaNumeros(double x, double y){
    return x+y;
}



int soma(int k){
    if (k>0){                                  
        return k + soma(k - 1);                 //recursividade
    }else{
        return 0;
    }

}




int main(){

    int resultado = soma(5);
    cout << resultado << "\n";
    //cout << somaNumeros() << "\n";
    return 0;
}

