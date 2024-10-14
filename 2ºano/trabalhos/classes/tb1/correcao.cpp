#include <iostream>
using namespace std;

struct Hardware{

    string ram;
    string gpu;
    string cpu;
    string psu;
    string caixa;
    string mb;
    string hd;
    string fans;
    char perifericos[5];
    
};

class Computer{

    private:
        Hardware computer;
        bool state;

        void formatar(){
            cout << "-------------------------------------------" << endl;
            cout << "O pc vai ser formatado..." << endl;
        }

        void openFolder(){
            cout << "-------------------------------------------" << endl;
            cout << "A pasta do pc foi aberta..." << endl;
        }

        void initSO(){
            cout << "-------------------------------------------" << endl;
            cout << "O sistema operativo está a ser iniciado..." << endl;
        }

        void initGPU(){
            cout << "-------------------------------------------" << endl;
            cout << "A placa gráfica está a ser iniciada..." << endl;
        }

        void removeFiles(){
            cout << "-------------------------------------------" << endl;
            cout << "O ficheiro vai ser removido..." << endl;
            cout << "-------------------------------------------" << endl;
        }

        void listaHardware(){

            system("clear");
            cout << "-------------------------------------------" << endl;
            cout << "              HARDWARE DO PC" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "RAM: " << computer.ram << endl;
            cout << "-------------------------------------------" << endl;
            cout << "GPU: " << computer.gpu << endl;
            cout << "-------------------------------------------" << endl;
            cout << "CPU: " << computer.cpu << endl;
            cout << "-------------------------------------------" << endl;
            cout << "PSU: " << computer.psu << endl;
            cout << "-------------------------------------------" << endl;
            cout << "Caixa: " << computer.caixa << endl;
            cout << "-------------------------------------------" << endl;
            cout << "MotherBoard: " << computer.mb << endl;
            cout << "Disco: " << computer.hd << endl;
            cout << "-------------------------------------------" << endl;
            cout << "FANs: " << computer.fans << endl;
            cout << "-------------------------------------------" << endl;
            cout << "Periféricos: ";
            for(int i = 0; i < 5; i++){
                cout << "\t";
                cout << computer.perifericos[i] << endl;

            }
        }

    public:
        
        Computer(Hardware hardware){ //construtor

            system("clear");
            this->computer = hardware;
            this->state = false;
            cout << "----------------------------------------------------------" << endl;
            cout << "O pc foi instanciado com sucesso! Tem de ligar o pc..." << endl;
            cout << "----------------------------------------------------------" << endl;
            listaHardware();
        }  

        void onPc(){
            system("clear");
            if(state){
                cout << "-----------------------------------------" << endl;
                cout << "O pc já está ligado..." << endl;
                cout << "-----------------------------------------" << endl;
            } else{
                cout << "-----------------------------------------" << endl;
                cout << "O pc vai ligar..." << endl;
                cout << "-----------------------------------------" << endl;

                this->state = true;
            }
        }

        void offPc(){
            system("clear");
            if(state){
                cout << "-----------------------------------------" << endl;
                cout << "O pc vai ser desligado..." << endl;
                cout << "-----------------------------------------" << endl;
                this->state = false;
            } else{
                cout << "-----------------------------------------" << endl;
                cout << "O pc já está desligado..." << endl;
                cout << "-----------------------------------------" << endl;
            }
        }

        void reset(){
            system("clear");
            if(state){
                cout << "-----------------------------------------" << endl;
                cout << "O pc vai ser reiniciado..." << endl;
                cout << "-----------------------------------------" << endl;
            } else{
                cout << "-----------------------------------------" << endl;
                cout << "O pc não está ligado..." << endl;
                cout << "-----------------------------------------" << endl;
            }
        }

        void abrirTampa(){
            system("clear");
            cout << "-----------------------------------------" << endl;
            cout << "A tampa do pc foi aberta..." << endl;
            cout << "-----------------------------------------" << endl;
        }

        void executar(int opt){
            switch (opt){
            case 1:
                if(state){
                    formatar();
                } else{
                    cout << "-----------------------------------------" << endl;
                    cout << "O pc não esá ligado..." << endl;
                    cout << "-----------------------------------------" << endl;
                }
                break;
            case 2:
                if(state){
                    openFolder();
                } else{
                    cout << "-----------------------------------------" << endl;
                    cout << "O pc não esá ligado..." << endl;
                    cout << "-----------------------------------------" << endl;
                }
                break;
            case 3:
                if(state){
                    removeFiles();
                } else{
                    cout << "-----------------------------------------" << endl;
                    cout << "O pc não esá ligado..." << endl;
                    cout << "-----------------------------------------" << endl;
                }
                break;
            default:
                cout << "-------------------------------" << endl;
                cout << "Opçáo inválida" << endl;
                cout << "-------------------------------" << endl;
                break;
            }
        }

        void input() {

            if (state){

                cout << "Recebendo input" << endl;

            } else{
                
                cout << "O computador nao esta ligado" << endl;
            }
        }
        
};

int main(){

    Hardware hardware1 = {"16GB", "RTX 3090", "i9 10900k",
                          "1000W", "Corsair 4000D", "Asus ROG Strix Z290-E",
                          "1TB SSD", "Corsair LL120", {'M', 'K', 'J', 'L'}};

    Hardware hardware2 = {"32GB", "RTX 4090", "i9 10900k", "4000W", "Corsair 8000D", "Asus ROG Strix Z290-E", "2TB SSD", "Corsair LL120", {'O', 'A', 'Y', 'B'}};

    Computer computer1(hardware1);
    Computer computer2(hardware2);

    return 0;
}