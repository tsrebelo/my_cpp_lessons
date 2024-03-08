/**
 * @brief Faz um exercicio onde faças o mesmo que o loopFor só que em while e DoWhile
 * 
 * While: primeiro verifica e depois faz
 * DoWhile: primeiro faz e depois verifica
*/

#include <iostream>
using namespace std;

int main(){
    system("clear");

cout << "LOOPFOR:" << endl;
    for(int n=0; n<=10; n++){                                   
        cout << n << "   ";
    }

cout << "\n___________________________________________\n" << endl;

cout << "WHILE:" << endl;
    int x;
    while(x<=10){
        cout << x << "   ";
        x++;
    }

cout << "\n___________________________________________\n" << endl;

cout << "DOWHILE:" << endl;
    int y = 23;
    do{
        y++;
        cout << y << "   ";
    }while(x<=10);
    cout << endl;
}