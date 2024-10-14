#include <iostream>
using namespace std;

class Refrigerante {

    private:

        string nome;
        double mL;
        double preco;
        string gas;

        void sairGas(){

            cout << "-----------------------------------------" << endl;
            cout << "TSSH" << endl;
        }


    public:

        bool estado;
        

        Refrigerante(string nome, double preco, double mL){
            
            system("clear");
            this->estado = false;
            this->nome = nome;
            cout << "-----------------------------------------" << endl;
            cout << "Nome: " << nome << endl;
            this->preco = preco;
            cout << "Preço: " << preco << "€" << endl;
            this->mL = mL;
            cout << "Quantidade: " << mL << "mL" << endl;

        }

        void abrirLata(){
            system("clear");
            sairGas();
            cout << "-----------------------------------------" << endl;
            cout << "A lata foi aberta" << endl;
            cout << "-----------------------------------------" << endl;
        }

        void lataOpen(){
            system("clear");
            if(estado){
                cout << "-----------------------------------------" << endl;
                cout << "A lata está aberta" << endl;
                cout << "-----------------------------------------" << endl;
            } else{
                abrirLata();
                this->estado = true;
            }
        }

        void lataClose(){
            system("clear");
            if(estado){
                cout << "-----------------------------------------" << endl;
                cout << "A lata está fechada" << endl;
                cout << "-----------------------------------------" << endl;
                this->estado = false;
            }
        }


        void executa(bool opcao){
            
            cout << "-----------------------------------------" << endl;
            cout << "A lata está fechada." << endl;
            cout << "-----------------------------------------" << endl;
            cout << "Para abrir a lata pressione (1) e (0) para não abrir: ";
            cin >> opcao;

            if(opcao = 1){
                lataOpen();
            } else if(opcao = 0){
                lataClose();
            }

        }

};

int main(){

    Refrigerante f1("Fanta de Ananás", 0.75, 330);
    f1.executa(0);

    return 0;
}