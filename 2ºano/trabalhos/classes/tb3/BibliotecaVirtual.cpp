#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
using namespace std;


struct Livro{

    string titulo;
    string autor;
    string categoria;

};

void salvar(const Livro& livro){
    ofstream arquivo("livros.txt", ios::app);

    if (arquivo.is_open()){
        arquivo << livro.titulo << " | " << livro.autor << " | " << livro.categoria << "\n";
        arquivo << "--------------------------------------------------\n"; 
        arquivo.close();

    } else{
        cout << "Erro ao abrir o arquivo!" << endl;
    }
}

void carregarLivrosDeArquivo(vector<Livro>& livros){
    ifstream arquivo("livros.txt");

    if (arquivo.is_open()){
        Livro livro;
        string linha;
        
        while (getline(arquivo, linha)) {
            livro.titulo = linha;
            getline(arquivo, livro.autor);
            getline(arquivo, livro.categoria);
            getline(arquivo, linha); 
            livros.push_back(livro); 
        }
        arquivo.close();

    } else{
        cout << "Arquivo não encontrado! Nenhum livro carregado." << endl;
    }
}


void registrarLivro(vector<Livro>& livros){

    Livro livro;
    system("clear");

    cout << "---------------------------------------------------------\n"; 
    cout << "Insira o título do livro: ";
    cin.ignore();
    getline(cin, livro.titulo);

    cout << "---------------------------------------------------------\n"; 
    cout << "Insira o autor do livro: ";
    getline(cin, livro.autor);

    cout << "---------------------------------------------------------\n"; 
    cout << "Digite a categoria (Romance, Aventura, Terror): ";
    getline(cin, livro.categoria);

    livros.push_back(livro); // Adiciona o livro ao vetor
    salvar(livro); // Salva no arquivo

    system("clear");
    cout << "--------------------------------------\n"; 
    cout << "Livro registrado com sucesso!" << endl;
}
// Função para pesquisar livro por categoria
void pesquisarPorCategoria(const vector<Livro>& livros, const string& categoria){

    system("clear");

    bool encontrado = false;
    for (const auto& livro : livros) {
        if (livro.categoria == categoria) {
            cout << "---------------------------------------------------------\n"; 
            cout << "Título: " << livro.titulo << ", Autor: " << livro.autor << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "Nenhum livro encontrado na categoria: " << categoria << endl;
    }
}

// Função para pesquisar livro por autor
void pesquisarPorAutor(const vector<Livro>& livros, const string& autor){

    system("clear");

    bool encontrado = false;
    for (const auto& livro : livros){
        if (livro.autor == autor){
            cout << "---------------------------------------------------------\n"; 
            cout << "Título: " << livro.titulo << ", Categoria: " << livro.categoria << endl;
            encontrado = true;
        }
    }
    if (!encontrado){
        cout << "Nenhum livro encontrado para o autor: " << autor << endl;
    }
}

int main(){

    system("clear");

    vector<Livro> livros;
    carregarLivrosDeArquivo(livros); 

    int opcao;

    do {
        cout << "--------------------------------------\n"; 
        cout << "\t\tMenu\n";
        cout << "--------------------------------------\n"; 
        cout << "1. Registrar Livro\n";
        cout << "2. Pesquisar Livro por Categoria\n";
        cout << "3. Pesquisar Livro por Autor\n";
        cout << "4. Sair\n";
        cout << "--------------------------------------\n"; 
        cout << "Escolha uma opção: ";

        cin >> opcao;

        switch (opcao){

            case 1:
                registrarLivro(livros); // Registrar livro
                break;
                
            case 2: {
                string categoria;
                cout << "Digite a categoria (Romance, Aventura, Terror): ";
                cin.ignore(); 
                getline(cin, categoria);
                pesquisarPorCategoria(livros, categoria); 
                break;
            }
            case 3: {
                string autor;
                cout << "Digite o nome do autor: ";
                cin.ignore();
                getline(cin, autor);
                pesquisarPorAutor(livros, autor); 
                break;
            }
            case 4:
                cout << "A sair do programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }

    } while (opcao != 4);

    return 0;
}
