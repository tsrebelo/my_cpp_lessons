#include <iostream>
using namespace std;

int main(){

    int num, sum = 0;

    for(num = 1; num <= 10; num++){
        if(num%4==0)
            continue;
        sum += num;
    }

    cout << "Total: " << sum << endl;
    return 0;
}