#include <iostream>
using namespace std;

int main(){

    int n = 1;
    cin >> n;
    switch(n){
        case 1:
            cout << " n é 1 " << endl;
        break;

        case 2:
            cout << "n é 2" << endl;
        break;

        case 3:
            cout << "n é 3" << endl;
        break;

        default:
        cout << " n é diferente de 1, 2 e 3 " << endl;
            break;
    }

    return 0;
}
