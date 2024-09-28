#include <iostream>
using namespace std;

//criar um array bidiomensional
int teste[3][3] = { {1,2,3},
                    {4,5,6},
                    {7,8,9}};

int main(){

    for(int n = 0; n < 3; n++){
        for(int x = 0; x < 3; x++){
            cout << teste[n][x] << " ";
        }
    }
}

//criar um array tridiomensional
int teste[3][3][3] = {  {{1,2,3},{1,2,3},{1,2,3}},
                        {{4,5,6},{4,5,6},{4,5,6}},
                        {{7,8,9},{7,8,9},{7,8,9}}};

int main(){

    for(int n = 0; n < 3; n++){
        for(int x = 0; x < 3; x++){
            for(int i = 0; i < 3; i++){
                cout << teste[n][x][i] << " ";
            }
        }
    }
}
