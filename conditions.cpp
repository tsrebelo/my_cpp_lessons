#include <iostream>
using namespace std;


/*
int a = 10, b = 12, c = 9;

int main(){

    if (a < b ){                                        // "||" esse ou outro, "&&" e outro
        cout << "é verdade" << endl;
    }else if (a<c){
        cout << "é verdade" << endl;
        }else{
            cout << "é mentira" << endl;
    }



    return 0;
}
*/



/**
 * @brief peça um número e mostre se ele é positivo ou negativo
 * 
 * @return int
*/

/*
int main(){
    
    int num;

    cout << "Digite umn número: ";
    cin >> num;

    if(num >= 0){
        cout << "é positivo" << endl;
    }else{
        cout << "é negativo" << endl;
    }
    return 0;
}
*/

/*
int main(){
    
    int num;
    cout << "Digite um número: " << endl;
    cin >> num;

    switch (num)
    {
        case 1:
        cout << "O número é 1" << endl;
        break;

        case 2:
        cout << "O número é 2" << endl;
        break;

    default:
        cout << "O número não é 1 nem é 2" << endl;
        break;
    }
    return 0;
}
*/

/*
int main(){
    
    int num;
    int result;
    cout << "Digite um número: " << endl;
    cin >> num;

    result = num % 2;

    switch (result)
    {
        case 0:
        cout << "O número é par" << endl;
        break;

    default:
        cout << "O número não é par" << endl;
        break;
    }
    return 0;
}
*/

int main(){
    
    int num=0;


    while(num < 5){
        cout << "Digite um número: " << endl;
        cin >> num;
    }

    return 0;
}