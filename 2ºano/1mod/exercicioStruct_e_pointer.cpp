#include <iostream>
using namespace std;

struct livro {
    string autor;
    string titulo;
    string subtitulo;
    string isbn;
    string data;
    
};

void inserelivro(livro &l){

    cout << "Qual é o titulo do livro: ";
    cin >> l.titulo;
}

void mostralivro(livro l){

    cout << "O titulo do livro é: " << l.titulo << endl;

}

int main(){

    livro livro1;
    livro livro2;
    inserelivro(livro1);
    mostralivro(livro1);


    return 0;
}