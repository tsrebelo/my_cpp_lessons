/*
ABRIR UM FICHEIRO USANDO TRY CATCH
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){

    string ficheiro;

    system("clear");
    cout << "Nome do ficheiro: ";
    cin >> ficheiro;

    try{
        ifstream file(ficheiro);
        if(!file.is_open()){
            throw "O ficheiro não existe";
        }
        throw "O ficheiro foi aberto com sucesso";
    }catch(const char* e){
        cout << e << endl;
    }


    return 0;
}