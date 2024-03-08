#include <iostream>
using namespace std;

const float PI = 3.1415;

int teste(){
    static int xpto = 3;

    return xpto;
}

int main(){

    system("clear");

    cout << teste() << endl;

}