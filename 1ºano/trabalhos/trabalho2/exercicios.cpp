#include    <iostream>
using namespace std;

int somaImpares(int x){
    int  sum = 0;
    for(int i = 0; i <= x; i++){
        if(i%2 != 0){
            sum+=i;
        }
    }
    return sum;
}

void multiplica(int a){
    for(int b = 1; b <= 10 ; b++){
        cout  <<  a  <<  " x "  <<  b  <<  " = "  <<  a*b  <<  endl;
    }
}

int perimetro(int x, int y){
    return 2*(x+y);
}

int area(int x, int y){
    return x*y;
}

int main( ){

    system("clear");
    int  n;
    int x;
    int w;
    int l;
    cout  <<  "---------------------------------------------"  <<  endl;
    cout  <<  "               SOMA DOS ÍMPARES"  <<  endl;
    cout  <<  "---------------------------------------------"  <<  endl;
    cout  <<  "Insira um número inteiro:  ";
    cin   >>  n;
    int resultado = somaImpares(n);
    cout  <<  "A soma dos números ímpares até  "  <<  n  <<  "  é :  "  <<  resultado  <<  endl;
    cout  <<  "---------------------------------------------" << endl;
    cout  <<  "                  TABUADA" << endl;
    cout  <<  "---------------------------------------------" << endl;
    cout  <<  "Insira um número inteiro entre 0 e 10:  ";
    cin >>  x;
    multiplica(x);
    cout << "----------------------------------------------" << endl;
    cout << "                AREA E PERIMETRO" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "O valor da altura é ";
    cin >> w;
    cout << "O valor do comprimento é ";
    cin >> l;
    int p = perimetro(w,l);
    int a = area(w, l);
    cout << "O perimetro do retângulo: " << p << endl;
    cout << "A área do retângulo: " << a << endl;


    return 0;
}
