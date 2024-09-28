#include <iostream>
using namespace std;

int a = 3;
int b = 4;
int c = 5;

int main(){

    if(a>b || b<c){
        cout << " ok A " << endl;
    }else if(b>a && c>a){
        cout << " ok B " << endl;
    }else{
        cout << " ok C " << endl;
    }
    
}