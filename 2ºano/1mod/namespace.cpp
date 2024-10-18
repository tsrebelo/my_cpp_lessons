#include <iostream>
using namespace std;

void teste(){
    cout << "Hello World" << endl;
}

namespace xpto{
    void teste(){
        cout << "teste namespace xpto" << endl;
    }
}

int main(){
    
    system("clear");
    teste();
    xpto::teste();

    return 0;
}