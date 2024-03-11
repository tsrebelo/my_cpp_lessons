#include <iostream>
using namespace std;

int n = 10;

namespace xpto{
    int x = 20;
    void func(){
        cout << "xpto1" << endl;
    }
    namespace xpto2{
        int x = 30;
        void func(){
            cout << "xpto2" << endl;
        }
    }
}

namespace first_space{
    int x = 40;
    void func1(){
        cout << "Inside first1_space" << endl;
    }
        void func2(){
        cout << "Inside first2_space" << endl;
    }
}

namespace second_space{
    int x = 50;
        void func(){
        cout << "Inside second_space" << endl;
    }
}

namespace a{
    int x = 40;
    void func(){
        cout << "a" << endl;
    }
}

namespace b{
        void func(){
        cout << a::x << endl;                       //imprime o valor de x do namespace a
    }
}

using namespace xpto;


int main(){

    system("clear");

    cout << n << "\n";

    b::func();                                  

    cout << xpto::x << "\n";
    cout << xpto::xpto2::x << "\n";

    func();
    xpto::xpto2::func();

    first_space::func2();
    first_space::func2();
    
    second_space::func();


    return 0;
}