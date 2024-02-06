#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
int main(){
    printf("teste\n");
    printf("Characters: %c %c %c \n", 'e', 'i', 'o');
    printf("Decimals: %d %ld \n", 1977, 650000L);
    printf("Preceding with blanks: %10d \n", 1932477);
    printf("Width trick: %*d \n", 10, 10);
}
*/

    string str;
    int i;

int main(){

    system("clear");

    printf("Enter your family name: ");
    scanf("%79s", str);
    printf("Enter your age: ");
    scanf("%d", &i);
    printf("Mr. %s, %d years old.\n", str, i);
    return 0;
}