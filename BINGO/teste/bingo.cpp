#include "bingo.h"
#include "bibliotecas.h"

// Códigos de escape ANSCI para cores e formatação
#define DOURADO "\033[1;93m" // Amarelo brilhante e negrito
#define ROSA "\033[35m"      // Rosa
#define AZUL_BEBE "\033[1;96m" // Azul bebé e negrito
#define RESET "\033[0m"      // Resetar formatação
#define NEGRITO "\033[1m"    // Negrito

Bingo::Bingo() : numeroAnterior(-1){
    srand(time(0)); // Inicializa a semente para números aleatórios
    limparCarta();
}

void Bingo::limparCarta(){
    cartela.clear();
    numerosSorteados.clear();
    numeroAnterior = -1; // Reseta o número anterior
}

void Bingo::gerarCarta(){
    cartela.resize(5, vector<int>(5));

    for(int j = 0; j < 5; ++j){
        vector<int> numerosColuna;
        for(int i = 0; i < 5; ++i) {
            int numero;
            do{
                numero = (rand() % 15) + 1 + (j * 15); // Números de 1 a 75
            } while (find(numerosColuna.begin(), numerosColuna.end(), numero) != numerosColuna.end());
            numerosColuna.push_back(numero);
            cartela[i][j] = numero;
        }
    }
    cartela[2][2] = 0; // Espaço livre no centro
}

bool Bingo::numeroJaSorteado(int numero){
    return find(numerosSorteados.begin(), numerosSorteados.end(), numero) != numerosSorteados.end();
}

int Bingo::linhaVencedora(){
    for(int i = 0; i < 5; ++i){
        bool linhaCompleta = true;
        for(int j = 0; j < 5; ++j){
            if(cartela[i][j] != 0 && !numeroJaSorteado(cartela[i][j])){
                linhaCompleta = false;
                break;
            }
        }
        if(linhaCompleta){
            return i; // Retorna a linha que fez bingo
        }
    }
    return -1; // Nenhuma linha fez bingo
}

int Bingo::colunaVencedora(){
    for(int j = 0; j < 5; ++j){
        bool colunaCompleta = true;
        for(int i = 0; i < 5; ++i){
            if(cartela[i][j] != 0 && !numeroJaSorteado(cartela[i][j])){
                colunaCompleta = false;
                break;
            }
        }
        if(colunaCompleta){
            return j; // Retorna a coluna que fez bingo
        }
    }
    return -1; // Nenhuma coluna fez bingo
}

void Bingo::exibirCarta(){
    // Exibe o cabeçalho com as letras do Bingo em dourado e negrito
    cout << DOURADO << "B\tI\tN\tG\tO" << RESET << "\n";

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            int numero = cartela[i][j];
            if(numero == 0){
                cout << AZUL_BEBE << "X" << RESET << "\t"; // Espaço livre em azul bebé e negrito
            }else if(numeroJaSorteado(numero)){
                cout << ROSA << numero << RESET << "\t"; // Número sorteado em rosa
            }else{
                cout << numero << "\t"; // Número não sorteado em branco
            }
        }
        cout << "\n";
    }
}

void Bingo::exibirCartaBingo(){
    int linhaBingo = linhaVencedora(); // Verifica qual linha fez bingo
    int colunaBingo = colunaVencedora(); // Verifica qual coluna fez bingo

    // Exibe o cabeçalho com as letras do Bingo em dourado e negrito
    cout << DOURADO << "B\tI\tN\tG\tO" << RESET << "\n";

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            int numero = cartela[i][j];
            if(numero == 0){
                cout << AZUL_BEBE << "X" << RESET << "\t"; // Espaço livre em azul bebé e negrito
            }else if (numeroJaSorteado(numero)){
                if(i == linhaBingo || j == colunaBingo){
                    cout << ROSA << NEGRITO << numero << RESET << "\t"; // Linha/coluna do bingo em rosa e negrito
                }else{
                    cout << ROSA << numero << RESET << "\t"; // Números sorteados em rosa (sem negrito)
                }
            } else {
                cout << numero << "\t"; // Número não sorteado em branco
            }
        }
        cout << "\n";
    }
}

void Bingo::sortearNumero(){
    int numeroSorteado;
    do{
        numeroSorteado = (rand() % 75) + 1;
    }while(numeroJaSorteado(numeroSorteado)); // Evita números repetidos

    numerosSorteados.push_back(numeroSorteado);
    cout << "\n\nNúmero anterior sorteado: " << (numeroAnterior == -1 ? "Nenhum" : to_string(numeroAnterior)) << "\n";
    cout << "Número atual sorteado: " << numeroSorteado << "\n";
    numeroAnterior = numeroSorteado; // Atualiza o número anterior
}

bool Bingo::verificarVencedor(){
    return linhaVencedora() != -1 || colunaVencedora() != -1; // Verifica se há uma linha ou coluna vencedora
}

void Bingo::criarNovaCarta(){
    limparCarta();
    gerarCarta();
    exibirCarta();
}

int Bingo::getNumeroAnterior() const{
    return numeroAnterior;
}