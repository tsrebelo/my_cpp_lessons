#include <iostream>
using namespace std;

int tentativas = 0;

void titulo(){

    cout << "\t\tDados eletrónicos - No âmbito do módulo" << '\n';
    cout << "\tProgramação c/c++ Estruturas básicas e Conceitos Fundamentais" << '\n';
    cout << "\t\t\t       ENTA - 2024" << '\n';

    cout << '\n'; 
    cout << '\n'; 
    cout << '\n'; 
    cout << '\n'; 
}

void dado(int num){


    switch(num){
        case 1:
            cout << "\t\t\t\t " << '\t' << " \n" << endl;
            cout << "\t\t\t\t    " << "*" << " \n" << endl;
            cout << "\t\t\t\t " << '\t' << " \n" << endl;
        break;
        case 2:
            cout << "\t\t\t\t " << '\t' << "*\n" << endl;
            cout << "\t\t\t\t " << '\t' << " \n" << endl;
            cout << "\t\t\t\t*" << '\t' << " \n" << endl;
        break;
        case 3:
            cout << "\t\t\t\t " << '\t' << "*\n" << endl;
            cout << "\t\t\t\t    " << "*" << " \n" << endl;
            cout << "\t\t\t\t*" << '\t' << " \n" << endl;
        break;
        case 4:
            cout << "\t\t\t\t*" << '\t' << "*\n" << endl;
            cout << "\t\t\t\t " << '\t' << " \n" << endl;
            cout << "\t\t\t\t*" << '\t' << "*\n" << endl;
        break;
        case 5:
            cout << "\t\t\t\t*" << '\t' << "*\n" << endl;
            cout << "\t\t\t\t    " << "*" << " \n" << endl;
            cout << "\t\t\t\t*" << '\t' << "*\n" << endl;
        break;
        case 6:
            cout << "\t\t\t\t*" << '\t' << "*\n" << endl;
            cout << "\t\t\t\t*" << '\t' << "*\n" << endl;
            cout << "\t\t\t\t*" << '\t' << "*\n" << endl;
        break;
    }
}

void ye(int num){

    cout << '\n'; 
    cout << '\n'; 
    cout << '\n'; 
    cout << '\n'; 

    cout << "\t\t\t   Lançamento número: " << num ;

    cout << '\n'; 
    cout << '\n';
    cout << '\n';


    cout << "\tPressione enter para jogar novamente ou ctrl + c para sair: ";
    cin.get();
}

int main(){

    srand(time(NULL));
    while (true){
        system("clear");
        titulo();
        dado(rand() % 6+1); 
        ye(++tentativas);
    }

    return 0;
}