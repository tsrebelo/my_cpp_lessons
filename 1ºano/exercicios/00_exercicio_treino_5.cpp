#include <iostream>
using namespace std;

int arr[10] = {1,2,3,4,5,6,7,8,9,10};

int somaArr(){
    int sum = 0;
    for(int x=0; x<10; x++){
        sum+=arr[x];
    
    }
    return sum;
}

int main(){
    cout << "a soma dos elementos é: " << somaArr() << endl;
}