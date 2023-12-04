#include <iostream>
using namespace std;

//reference is an alias for a variable
string food = "Pizza";

//create a reference variable
string &meal = food;


int main(){

    cout << food << "\n";                  //outPut "Pizza"
    cout << meal << "\n";                  //outPut "Pizza"
    cout << &food << "\n";
   
   
    return 0;
}