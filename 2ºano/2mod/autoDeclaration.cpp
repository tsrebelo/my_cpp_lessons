#include <iostream>
using namespace std;
//usar a biblioteca iomanip para usar setw para fazer distancia entre valores


void decAuto(){

    string nome = "Paulo";  //declaração manual de nome, numero e num
    int numero = 123;
    float num = 3.14;

    auto string_nome = "Paulo";    //auto declara o nome, o numero, e o num
    auto int_numero = 123;
    auto float_num = 3.14;

    unsigned int altura = 10;   //não pode ser negativo, assim sendo só pode ser positivo e 0

    cout << num << " / " << numero << " / " << nome << endl;

    cout << float_num << " / " << int_numero << " / " << string_nome << endl;
}

void escape(){

    cout << "--------------------------" << endl;

    cout << "\nBackspace: " << "Paula" << '\b' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nNew line: " << "Paula" << '\n' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nHorizontal tab: " << "Paula" << '\t' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nAudible bell: " << "Paula" << '\a' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nCarriage return: " << "Paula" << '\r' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nNew page: " << "Paula" << '\f' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nNull value: " << "Paula" << '\0' << "o" << endl;
    cout << "\n--------------------------" << endl;
    cout << "\nBackslash: " << "Paula" << '\\' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nSingle quote: " << "Paula" << '\'' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nDouble quote: " << "Paula" << '\"' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nQuestion mark: " << "Paula" << '\?' << "o" << endl; 
    cout << "\n--------------------------" << endl;
    cout << "\nVertical tab: " << "Paula" << '\v' << "o" << endl;
}

void mtoM(){

    char m;

    cout << "----------------------------------" << endl;

    cout << "Digite uma letra minúscula: ";
    cin >> m; 

    cout << "\nLetra " << m << " em maiúscula é " << (char)(m - 32) << endl; //converte uma variável em char
}

void equacaoA(){
    float x1, x2, y1, y2;
    cin >> x1, x2, y1, y2;

}

void nestedCondition(){
    
    

}

void decisions(){

    cout << "---------------" << endl;

    int x = 0;
    while(x < 5){
        x++;
        cout << " " << x;
    }
    cout << "\n---------------" << endl;
    cout << "finish!" << endl;
    cout << "---------------" << endl;

}

int main(){

    system("clear");
    
    escape();

    return 0;
}