#include <iostream>

using namespace std;


int main(){
    

    for (int n=0; n=10; n++){
        cout << "Telma" << endl;                //run do código é "Telma" infinitas vezes
    }
    return 0;
}



int main(){
    

    int i = 10;

   // while (i != 10){                          //while faz eternamente
   //     cout << "Olá" << endl;
   // }

    do {                                        //do while faz uma única vez, e depois avalia o código 
        cout << "Olá" << endl;                  //run do código é "Olá"
    } while (i != 10);

    return 0;
}




int main(){
cout << "inicio do ciclo For" << endl;          //run do código é "inicio do ciclo For"
    for (int n=0; n<=10; n++){
        cout << n << endl;                      //run do código é "0 1 2 3 4"
        if (n == 4){
            break;
        }
    }
    cout << "fim do ciclo For" << endl;         //run do código é "fim do ciclo For"
    return 0;
}



int main(){
cout << "inicio do ciclo For" << endl;          //run do código é "inicio do ciclo For"
    for (int n=0; n<=10; n++){                  
        if (n == 4){                            //run do código é "0 1 2 3 4 5 6 7 8 9 10"
            continue;
        }
        cout << n << endl;                      //run do código é "fim do ciclo For"
    }
    cout << "fim do ciclo For" << endl;
    return 0;
}



int main(){
    

    int i = 10;

 while (i != 10){                          
     cout << "Olá" << endl;                    
}

    do {                                        //executa independentemente da condição
        cout << "Olá" << endl;                  //run do código é "Olá"
    } while (i != 10);

    return 0;
}


/*
int main(){

    int test[4] = {7,8,9,7};
    for (int i=0; i<4; i++){
        cout << test[i] << endl;
    }

    return 0;
}
*/

/*
int main(){

    int chave[5];
    int estrelas[2];
    
    for (int i=0; i<4; i++){
        cout << chave[i] << endl;
    }

    return 0;
}
*/

/*
int main(){
    // indice            0       1       2       3       4
    string cars[] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};
    //cout << cars[2] << "\n";
    cars[2] = "Opel";
    //{"Volvo", "BMW", "Ford", "Mazda", "Tesla"}
    cout << cars[2] << "\n";

    return 0;
}
*/

/*
int main(){
    int numeros[] = {1,2,3,4,5};                    //são 4bytes para cada elemnto do araid
    cout << sizeof(numeros) << endl;
    

    return 0;
}
*/