#include <iostream>
using namespace std;

class Fatura{

    private:
        string num;
        string nome;
        string cc;
        double preco;
        int sh;

        void calculaImposto(){

            cout << "Calculando imposto..." << endl;
        }

    public:

        Fatura(int sh){

            this->sh = sh;
            cout << "-------------------------------" << endl;
            cout << "Construtor chamado(O ash)" << this->sh << endl;
            cout << "-------------------------------" << endl;
        }

        void criaFatura(string num, string nome, string cc, double preco){
            
            this->num = num;
            this->nome = nome;
            this->cc = cc;
            this->preco = preco;
            calculaImposto();

        }

        void imprimeFatura(){

            cout << "-------------------------------" << endl;
            cout << "            Fatura" << endl;
            cout << "-------------------------------" << endl;
            cout << "-------------------------------" << endl;
            cout << "Número: " << num << endl;
            cout << "-------------------------------" << endl;
            cout << "Nome: " << nome << endl;
            cout << "-------------------------------" << endl;
            cout << "Contribuinte: " << cc << endl;
            cout << "-------------------------------" << endl;
            cout << "Preço: " << preco << endl;
            cout << "-------------------------------" << endl;

        }
};

int main(){

    system("clear");
    
    Fatura fatura(435); //instancia a class

    fatura.criaFatura("00KJB1", "BLABLA", "OHFWE34EFS", 12.43);
    fatura.imprimeFatura();

    return 0;
}