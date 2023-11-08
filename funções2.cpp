#include <iostream>
using namespace std;


/*o struct pode ser usado de duas maneiras*/



/**primeira maneira**/

struct                           //é uma declaração de tipo de dado composto que define uma lista de atributos ​​fisicamente agrupados sob um nome
{
    string nome;
    int idade;
    string codPostal;
    string rua;
    string cidade;
    string pais;

} pessoa1, pessoa2, pessoa3;

int main(){

    pessoa1.nome = "João";
    pessoa1.idade = 20;
    pessoa1.codPostal = "9625-301";
    pessoa1.rua = "Rua do João";
    pessoa1.pais = "Portugal";

    pessoa3.nome = "Maria";
    pessoa3.idade = 25;
    pessoa3.codPostal = "9625-308";
    pessoa3.rua = "Rua da Maria";
    pessoa3.pais = "Portugal";

    cout << pessoa1.nome << endl;
}



/**segunda maneira**/

struct pessoa   
{
    string nome;
    int idade;
    string codPostal;
    string rua;
    string cidade;
    string pais;

};

int main(){

    pessoa p1, p2, p3;
 

    p1.nome = "João";
    p3.nome = "Maria";

    cout << p1.nome << endl;                        //uma vez que o nome não é definido não aparece
    cout << p2.nome << endl;
    cout << p3.nome << endl;           
}