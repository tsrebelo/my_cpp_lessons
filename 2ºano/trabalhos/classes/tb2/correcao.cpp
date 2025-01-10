#include <iostream>
using namespace std;

struct lata{

    string marca;
    string sabor;
    string validade;
    string fornecedor;
    string codBarras;
    string lote;
    string dataFabricacao;
    string infofornecedor;
    string materialEmbalagem;
    string infoNutricional[5];

    double capacidade;
    double preco;
    double peso;

    bool status;

};

class Refrigerante{

    private:
        lata refrigerante;
        double qntSumoDisp;

    public:
        //Constructor
        Refrigerante(lata lata){
            refrigerante = lata; //incapsulamento
            qntSumoDisp = refrigerante.capacidade;
        }

        //abrir lata
        void abrirLata(){
            
            if(refrigerante.status == false){
                cout << "A abrir a lata...tsshh" << endl;
                refrigerante.status = true;
            } else{
                cout << "Lata já está aberta" << endl;
            }
        }

        //beber refrigerante
        void beberRefri(){
            system("clear");
            double qnt;

            if(qntSumoDisp == 0){
                cout << "Não há refrigerante disponível" << endl;
            }
            
            if(refrigerante.status){


                cout << "Há " << qntSumoDisp << "ml de refrigerante disponível" << endl;
                cout << "Digite a quantidade de refrigerante que deseja beber: ";
                cin >> qnt;

                if(qnt <= qntSumoDisp){
                    qntSumoDisp -= qnt;
                    cout << "Bebes-te " << qnt << " ml de refrigerante" << endl;
                } else{
                    cout << "Não há quantidade suficiente" << endl;
                }

            } else {
                cout << "É preciso abrir a lata antes de beber" << endl;
            }
        }

        //

};

int main(){

    system("clear");

    lata lata1 = {"Fanta", "Ananás", "10/10/2021","Fanta","3487234902932",
                  "123456", "21/1/2024", "Fanta Company", "Alumínio",
                  {"Calorias: 12kcal", "Proteinas: 50", "Carboidratos: 0", 
                  "Gorduras: 10" "Sódio: 10"}, 330, 0.75, 0.330, false};

    Refrigerante refri1(lata1);

    while(true){
        int opcao;
        cout << "1 - Abrir lata" << endl;
        cout << "2 - Beber refrigerante" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma opção:";
        cin >> opcao;

        if(opcao == 1){
            system("clear");
            refri1.abrirLata();
        } else if(opcao == 2){
            system("clear");
            refri1.beberRefri();
        } else if(opcao == 3){
            system("clear");
            break;
        } else{
            system("clear");
            cout << "Opção inválida!" << endl;
        }
   
    }
    
    

    return 0;
}