#include <iostream>
using namespace std;

int main(){

    int num, sum;

    for(num = 1; num <= 10; num++){
        if(num%4==0)
            continue;
        sum += num;
    }
}