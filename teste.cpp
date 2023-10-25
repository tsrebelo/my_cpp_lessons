#include <iostream>             //include serve para incluir uma biblioteca com um grupo de códigos
#include <cmath>                //inclui uma biblioteca matemática
#include "asminhascontas.h"            
using namespace std;

int NUM_PORT_SENS_HUM = 5;   


int O_MEU_NUMERO = 10;                          //números inteiros
double O_MEU_NUMERO_REAL = 10.5;                //números reais
char O_MEU_CARACTER = 'a';                      //caracteres
string O_MEU_TEXTO = "isto é um texto";         //texto
bool O_MEU_BOOLEANO = true;                     //booloeano
const double PI = 3.141592653589793238463;      //constante (não se pode alterar)
int x = 2, y=3, z=14;
int minutosPorHora=60;
int numero;                                     //variavel nule
//tudo entre "()" vai ser avaliado

//tipo de variavel  nome da variavel = valor da variavel

int sensorTemperatura = 10;                     //variavel inteira (pode-se alterar)
const double INTERVALO_TEMPO = 1000;            

int myBool = 1; //true
//char teste = '1';

/*
int a=2, b=3;

int main(){
    cout << log(16) << endl;
    cout << oDobro(2) << endl;
    xpto();
    return 0;

}
*/

/*
int main(){
    cout << log(b) << endl;             log = logarítmo
    return 0;

}
*/

/*
int main(){
    cout << max(a,b) << endl;
    return 0;

}
*/

/*
int main(){
    cout << pow(4,2) << endl;               pow = eleva
    return 0;

}
*/


/*
*@author sou eu
*teste
*
*/
/** int main()
{

    cout << "Digita um numero: ";   //imprime no ecrã
    cin >> numero;                  //lê do teclado
    cout << "O numero que digitaste foi: " << numero << endl;
    return 0;
}
   */ 
    /**
     * @brief
     * 
     * @param a número inteiro
     */
    /**void teste(int a){

    }
 */

 /*
   NOTAS

    1 BYTE = 8 bits
    concatenação = juntar uma ou mais coisas
    % é o resto da sobra da divisão da conta
 */



/*
int main()
{
    cout << "Hello \\ World!\t";    // isto é um comentário
    cout << "I'm a C++ program\n";
    cout << O_MEU_NUMERO + "\n";
    cout << "\n";
    cout << PI << " valor de PI\n";
    cout << sensorTemperatura << " vslor do sensor de temperatura\n";

    sensorTemperatura = 20;
    cout << sensorTemperatura << " valor do sensor de temperatura\n" << PI << " valor de PI\n";
    return 0;
}

    concatenação = juntar uma ou mais coisas
    % é o resto da sobra da divisão da conta
*/
  


/*
int main()
{

    string a = 1;
    string b = 2;
    cout << a+b << endl;
    return 0;
}
*/


/*
tendo em consideração que a área do circulo é PI * raio * raio, calcula a área do circulo com raio 10


int main()
{
    int r = 10;
    double area = PI * r * r;

    cout << area << endl;
    
    return 0;
}
*/

/*int main()
{
    int raio;
    cout << "Qual o raio do circulo?" << endl;
    cin >> raio;
    double area = PI * raio * raio;
    cout << area << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 1000;
    int b = 2000;
    int c = b-a;
    cout << c << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 4;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = a+(b*c)+d;
    cout << resultado << endl;
    return 0;
}
*/


/*
int main()
{
    int a = 4;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = a/c;
    cout << resultado << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 5;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = a%c;
    cout << resultado << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 4;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = ++a;                // '++' antes do valor adiciona um valor
    cout << resultado << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 4;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = --a;                // '--' antes do valor retira um valor
    cout << resultado << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 4;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = a%c;
    cout << resultado << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 4;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = a+=6;
    cout << resultado << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 4;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = a-=6;
    cout << resultado << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 4;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = a+=2;
    cout << resultado << endl;
    resultado = a+=2;
    cout << resultado << endl;
    return 0;
}
*/

/*
int main()
{
    int a = 4;
    int b = 5;
    int c = 2;
    int d = 1;
    int resultado = a&=4;
    cout << resultado << endl;
    return 0;
}
*/

 