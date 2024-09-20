#include <iostream>
using namespace std;

//reference is an alias for a variable
string food = "Pizza";

//create a reference variable
string &meal = food;


int main(){

    cout << food << "\n";                  //outPut "Pizza"
    cout << &food << "\n";                 //outPut endereço de memória 0x55834a084160
    cout << meal << "\n";                  //outPut "Pizza"
    cout << &meal << "\n";                 //outPut endereço de memória 0x55834a084160
   
    return 0;
}