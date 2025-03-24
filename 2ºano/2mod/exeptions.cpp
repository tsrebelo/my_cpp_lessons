/*
ABRIR UM FICHEIRO USANDO TRY CATCH
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){

    string ficheiro;
    system("clear");

    while(true){

        cout << "Nome do ficheiro: ";
        cin >> ficheiro;
        system("clear");

        try{
            ifstream file(ficheiro);
            if(!file.is_open()){
                throw "E";
            }
            throw "O";
        }catch(const char *e){ //*e apontando para endereço de memória onde está o 'e'
            if(e[0] == 'E'){
                cout << "--------------------------------" << endl;
                cout << "Erro ao abrir o ficheiro" << endl;
                cout << "--------------------------------" << endl;
            }else{
                cout << "--------------------------------" << endl;
                cout << "Ficheiro aberto com sucesso" << endl;
                cout << "--------------------------------" << endl;
                break;
            }
        }
    }



    return 0;
}