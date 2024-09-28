#include <iostream>
using namespace std;

//-------------------------------------------------------------------
//                              funções
//-------------------------------------------------------------------

/*int soma(int lista[]){

    int soma = 0;
    for(int i=0; i < 5; i++){
        soma += lista[i];
    }

    return (int)soma; //cast, convertido de float para int
}

float soma(float x, float y=10.2){

    return x+y;
}*/

//-------------------------------------------------------------------
//                           over loading
//-------------------------------------------------------------------

/*int soma(int x, int y){
    return x+y;
}

float soma(float x, float y){
    return x+y;
}

double soma(double x, double y){
    return x+y;
}*/
 

//-------------------------------------------------------------------
//                               scope
//-------------------------------------------------------------------

/*int x = 0;

int soma(){
    int y = x+1;
    return y;
}


int main(){

    cout << soma() << endl;

    return 0;
}*/

//-------------------------------------------------------------------
//                          regrossividade
//-------------------------------------------------------------------

/*int sum(int k){

    if(k > 0){
        return k + sum(k - 1);
    } else{
        return 0;
    }
}

int main(){

    int result = sum(10);
    cout << result;
    return 0;
}*/

//-------------------------------------------------------------------
//                              class
//-------------------------------------------------------------------

class Carro{

public:    
    int anos;
    string marca;
    void setVelocidade(int v){
        velocidade = v;
        setVelMedia(velocidade);
    }
    //void mostra();                  //funções dentro de classes são chamadas de métodos

private:
    int velocidade;
    void setVelMedia(int vm){
        int velMedia = vm;
    }

};

int main(){

    Carro carro1;

    carro1.anos = 15;
    carro1.marca = "Ford";
    carro1.setVelocidade(100);
    

    return 0;
}