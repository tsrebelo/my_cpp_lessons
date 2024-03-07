#include <iostream>
using namespace std;

int perimetro(int x, int y){
    return 2*(x+y);
}

int area(int x, int y){
    return x*y;
}

int main(){
    int l1 = 5;
    int l2 = 6;

    int a = area(l1,l2);
    int p = perimetro(l1, l2);

    cout << "area: " << a << endl;
    cout << "perimetro: " << p << endl;

}