/**
 * @brief Faz um exercicio onde faças o mesmo que o loopFor só que em whileDo
*/

#include <iostream>
using namespace std;

int main(){

cout << "LOOPFOR:" << endl;
    for(int n=0; n<=10; n++){                                   
        cout << n << endl;
    }
cout << "_________________________________\n" << endl;

cout << "WHILEDO:" << endl;
    int x;
    while(x<=10){
        cout << x << endl;
        x++;
    }

    return 0;
}