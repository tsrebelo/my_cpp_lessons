#include <iostream>

using namespace std;

/*
int main(){
    

    for (int n=0; n=10; n++){
        cout << "Telma" << endl;
    }
    return 0;
}
*/


int main(){
    

    int i = 10;

   // while (i != 10){                          //while faz eternamente
   //     cout << "Olá" << endl;
   // }

    do {                                        //do while faz uma única vez, e depois avalia o código 
        cout << "Olá" << endl;
    } while (i != 10);

    return 0;
}