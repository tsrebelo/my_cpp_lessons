#include <iostream>
using namespace std;

//#define Y "teste"
//const int X = 10;

class A{

    public: 
        int pubA = 10;

    private:
        int privA = 20;

    protected:
        int protA = 30;

};

class B : public A{

    public: 
        int pubB = 40;

    private:
        int privB = 50;

    protected:
        int protB = 60;

};

class C : public A, public B{

    public: 
        int pubC = 70;

    private:
        int privC = 80;

    protected:
        int protC = 90;

};

int main(){

    B objB;

    objB.pubA;
    objB.pubB;

    return 0;
}