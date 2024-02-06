#include <stdio.h>
#include <stdlib.h>

/*
int main(){
    printf("teste\n");
    printf("Characters: %c %c %c \n", 'e', 'i', 'o');
    printf("Decimals: %d %ld \n", 1977, 650000L);
    printf("Preceding with blanks: %10d \n", 1932477);
    printf("Width trick: %*d \n", 10, 10);
}
*/

int main(){

    char nome[50];

    system("clear");

    printf("Nome: ");
    scanf("%s", nome);
    printf("Olá %s\n", nome);
}