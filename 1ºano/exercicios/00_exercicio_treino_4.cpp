#include <iostream>
using namespace std;

const long PI = 3.1415;
const long r = 10.0;

long area(long x){

    return PI*x*x;
}

long perimetro(long x){

    return 2*PI*r;
}

int main(){

    cout << "a área é: " << area(r) << endl;
    cout << "o peímetro é: " << perimetro(r) << endl;

}