#include <iostream>
#include <iomanip>
using namespace std;

void matriz(int dim){

    system("clear");

    for(int i=1; i<=dim; i++){
        for(int n=1; n<=dim; n++) cout << setw(4) << i*n; 
        cout << endl;
    }
    cout << endl;
}

int main() {

    matriz(15);

    return 0;
}
