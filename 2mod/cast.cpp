/**
 * C++ program to demonstrate casting
*/

#include <iostream>
using namespace std;

const int NUM_CONST = 20;

void showASCIITable(){

    int i = 0;
    for(int x = 33; x <=127; x++){
        cout << (char)x << "\t";
        i++;
        if(i%NUM_CONST == 0 || i >= 94){                //faz uma coluna e "NUM_CONST"
            cout << "\n";
        }
    }
}


int main(){

    system("clear");
    showASCIITable();


/*
    int i = 80;
    float f = 3.14;
    char c = 'a';

    //Cast implicito
    float f2 = i;
    char c2 = i;                //o char tem infulência com a tabela de ascii
    
    cout << "f2: " << f2 << endl;
    cout << "c2: " << c2 << endl;

    //Cast explicito
    int i2 = (int)f;
    int i3 = (int)c;

    //char de um inteiro para um char
    char c3 = (char)i;

    cout << "i2: " << i2 << endl;
    cout << "i3: " << i3 << endl;
    */


}