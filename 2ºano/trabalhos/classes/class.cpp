#include <iostream>
using namespace std;

struct Hardware {

    string RAM;
    string GPU;
    string CPU;
    string PSU;
    string caixa;
    string motherBoard;
    string discoRigido;
    string FANs;
    string dispExternos;

};

class Computador{
    
    private:

        void formatar(){
            cout << "A formatar..." << endl;
        }

        void openFolders(){
            cout << "A abrir pastas..." << endl;
        }

        void removeFolders(){
            cout << "A remover pastas.." << endl;
        }

        const void initSO(){
            cout << "A iniciar o SO..." << endl;
        }

        void const initCPU(){
            cout << "A iniciar CPU..." << endl;
        }

        void hardware(){
            
            Hardware hardware;


            cout << 
        }


    public:

        void on(){
            cout << "O pc está ligado..." << endl;
        }

        void off(){
            cout << "O pc está desligado..." << endl;
        }

        void reset(){
            cout << "O pc vai reiniciar..." << endl;
        }

        void abrirTampa(){
            cout << "A tampa está aberta..."
        }

        void execut(/*formatar(), openFolders(), removeFolders()*/){

            switch(){
                case 1:
                    on();
                break;
                case 2:
                    off();
                break;
                case 3:
                    reset();
                break;
                case 4:
                    abrirTampa();
                break;
                default:

                break;
            }
        }

        void input(){

        }


};

int main(){

    system("clear");

    Hardware hardware = {"16GB", "RTX 4060", "i6 10900k", "1000W", "Corsair 4000D", "Asus ROG Strix Z490-E", "1TB SSD", "Corsair LL120", {"M", "K", "L", "R", "J"}};

    return 0;
}