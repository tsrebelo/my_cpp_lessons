#include <iostream>
using namespace std;


namespace xpto{
    void func(){
        cout << "xpto1" << endl;
    }
    namespace xpto2{
        void func(){
            cout << "xpto2" << endl;
        }
    }
}

namespace first_space{
    void func1(){
        cout << "Inside first1_space" << endl;
    }
        void func2(){
        cout << "Inside first2_space" << endl;
    }
}

namespace second_space{
        void func(){
        cout << "Inside second_space" << endl;
    }
}

using namespace xpto;


int main(){

    system("clear");

    func();
    xpto::xpto2::func();
    first_space::func2();
    first_space::func2();
    second_space::func();
    return 0;
}