#include <iostream>
using namespace std;

int main()
{
    int a[5]= {5,3,2,4,1};

    int l=5;

    for(int j = 0; j < l; j++){

        cout << a[j] << " ";
    }
    cout << endl;

    for(int i = 0; i < (l-1); i++)
    {
        for(int j = 0;j < (l-1-i); j++){

            if(a[j+1] < a[j]){

                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
        for(int j = 0; j < l; j++){

            cout << a[j] << " ";
        }
        cout << endl;
    
    }
}
