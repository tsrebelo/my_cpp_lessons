#include <iostream>
using namespace std;

int main(){

    int a = 12, b = 25;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a & b = " << (a&b) << endl;
    cout << "a | b = " << (a|b) << endl;
    cout << "a ^ b = " << (a^b) << endl;
    //deslocamento de bits à esquerda
    cout << "a << 2 = " << (a << 1) << endl;
    //deslocamento de bits à direita
    cout << "a >> 2 = " << (a >> 1) << endl;

    return 0;
}