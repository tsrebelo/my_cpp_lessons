#include <iostream>
#include <ctime> // c = current / time - tempo
#include <unistd.h>
using namespace std;

int main(){

    //cout << "Hello World!" << endl;

    while(true){
        time_t timestamp;
        time(&timestamp);

        system("clear");

        cout << "current time: " << ctime(&timestamp) << endl;
        sleep(1);
    }

    return 0;
}