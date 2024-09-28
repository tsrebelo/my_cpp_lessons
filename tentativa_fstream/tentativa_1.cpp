#include <iostream> 
#include <fstream> 
#include <sstream> 
using namespace std; 

const string DBfile = "lista"; 
const int prodMax = 80;

struct Produto{ 
    int id;
    string nome;
    float preco;
    int quantidade;
    char status;
};

void loadProd(Produto produtos[], int& quantidadeAtual){

    ifstream file(DBfile);

    while (file.good() && quantidadeAtual < prodMax) {
        Produto p;
        string line;

        if (getline(file, line)) {
            stringstream ss(line);
            string status; 
            getline(ss, status, ','); 
            p.status = status[0]; 
            ss >> p.id; 
            ss.ignore(); 
            getline(ss, p.nome, ','); 
            ss >> p.preco; 
            ss.ignore(); 
            ss >> p.quantidade;
            produtos[quantidadeAtual] = p; 
            quantidadeAtual++; 
        }
    }
    file.close();
}


void saveProd(const Produto produtos[], int quantidadeAtual){

    ofstream file(DBfile); 
    for(int x = 0; x < quantidadeAtual; x++){ 
        file << produtos[x].status << "," << produtos[x].id << ","  
        << produtos[x].nome << "," << produtos[x].preco << "," 
        << produtos[x].quantidade << endl;
    }
    file.close();

    cout << "-----------------------------------------------" << endl;
    cout << "Produtos salvos com sucesso!" << endl;
}


void consultProd(const Produto produtos[], int quantidadeAtual){

    char opcao;
    if(quantidadeAtual == 0){
        cout << "-----------------------------------------------" << endl;
        cout << "Sem produtos adicionados." << "\nVoltando ao menu..." << endl;
        return;

    } else{

        cout << "------------------------------------------------------------------" << endl;
        cout << "Quer consultar os produtos ativos(A), eliminados(E) ou todos(T)? ";
        cin >> opcao;
        system("clear");

        if(opcao == 'A' || opcao == 'a'){

            cout << "-----------------------------------------------" << endl;
            cout << "           Lista de produtos ativos" << endl; 
            for(int a = 0; a < quantidadeAtual; a++){

                if(produtos[a].status == 'A' || 'a'){ 

                    cout << "-----------------------------------------------" << endl;
                    cout << "ID: " << produtos[a].id << endl;
                    cout << "Nome: " << produtos[a].nome << endl;
                    cout << "Preço: " << produtos[a].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[a].quantidade << endl;
                    cout << "Status: " << produtos[a].status << endl;

                }
            }
        }

        if(opcao == 'E' || 'e'){

            cout << "-----------------------------------------------" << endl;
            cout << "         Lista de produtos eliminados" << endl; 
            for(int e = 0; e < quantidadeAtual; e++){

                if(produtos[e].status == 'E'){ 

                    cout << "-----------------------------------------------" << endl;
                    cout << "ID: " << produtos[e].id << endl;
                    cout << "Nome: " << produtos[e].nome << endl;
                    cout << "Preço: " << produtos[e].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[e].quantidade << endl;
                    cout << "Status: " << produtos[e].status << endl;

                }
            }
        }

        if(opcao == 'T'){

            cout << "-----------------------------------------------" << endl;
            cout << "          Lista de todos os produtos" << endl; 
            for(int t=0; t<quantidadeAtual; t++){
                cout << "-----------------------------------------------" << endl;
                cout << "ID: " << produtos[t].id << endl;
                cout << "Nome: " << produtos[t].nome << endl;
                cout << "Preço: " << produtos[t].preco << "€" << endl;
                cout << "Quantidade: " << produtos[t].quantidade << endl;
                cout << "Status: " << produtos[t].status << endl;                                                                                         

            }
        }
    }
}


void changeProd(Produto produtos[], int quantidadeAtual){

    int id; 
    cout << "-----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja alterar: "; 
    cin >> id; 
    system("clear");

    for(int y = 0; y < quantidadeAtual; y++){ 

        if(produtos[y].id == id && produtos[y].status == 'A'){ 

            cout << "-----------------------------------------------" << endl;
            cout << "Insira o novo nome do produto: ";
            cin.ignore(); 
            getline(cin, produtos[y].nome); 
            cout << "-----------------------------------------------" << endl;
            cout << "Insira o novo preço do produto: ";
            cin >> produtos[y].preco;
            cout << "-----------------------------------------------" << endl;
            cout << "Insira a nova quantidade do produto: ";
            cin >> produtos[y].quantidade;

            saveProd(produtos, quantidadeAtual);
            system("clear");
            cout << "-----------------------------------------------" << endl;
            cout << "Produto alterado com sucesso." << endl;
            return;

        }
    }

    cout << "-----------------------------------------------" << endl;
    cout << "Produto nao foi encontrado ou ja foi eliminado." << endl;
}

void eliminateProd(Produto produtos[], int quantidadeAtual){

    int id;
    cout << "-----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja eliminar: ";
    cin >> id;

    for(int w = 0; w < quantidadeAtual; w++){

        if(produtos[quantidadeAtual].id == id){

            produtos[w].status = 'E';
            saveProd(produtos, quantidadeAtual);

            system("clear");
            cout << "-----------------------------------------------" << endl;
            cout << "Produto eliminado com sucesso!" << endl;
            return;

        }
    }

    system("clear");
    cout << "-----------------------------------------------" << endl;
    cout << "Produto nao encontrado." << endl;
}


void addProduto(Produto produtos[], int quantidadeAtual){

    if(quantidadeAtual >= prodMax){

        cout << "-----------------------------------------------" << endl;
        cout << "Atingiu o limite máximo de produtos." << "\nNão é possível adicionar mais produtos." << endl;
        return;

    } else{

        Produto newProduct; 
        newProduct.status = 'A'; 

        if(quantidadeAtual == 0){ 
            newProduct.id = 1;

        } else{ 
            newProduct.id = produtos[quantidadeAtual - 1].id - 1; 
        }       

        cout << "-----------------------------------------------" << endl;
        cout << "Insira o nome do produto: ";
        cin.ignore();
        getline(cin, newProduct.nome);

        cout << "-----------------------------------------------" << endl;
        cout << "Insira o preço do produto: ";
        cin >> newProduct.preco;

        cout << "-----------------------------------------------" << endl;
        cout << "Insira a quantidade do produto: ";
        cin >> newProduct.quantidade;

        produtos[quantidadeAtual] = newProduct; 
        quantidadeAtual++; 
        saveProd(produtos, quantidadeAtual);
        system("clear");

        cout << "-----------------------------------------------" << endl;
        cout << "O produto foi adicionado." << endl;
    }
}

float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {

    float total = 0.0;

    for (int i = 0; i < quantidadeAtual; i++) {

        if (produtos[i].status == 'E') { 
            total += produtos[i].preco * produtos[i].quantidade;
        }
    }

    return total;
}

void showMenu(){

    cout << "-----------------------------------------------" << endl;
    cout << "                     MENU" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1 - Adicionar Produtos " << endl;
    cout << "2 - Calcular Valor Total do Stock " << endl;
    cout << "3 - Consultar Produtos " << endl;
    cout << "4 - Alterar Produto " << endl;
    cout << "5 - Eliminar Produto " << endl;
    cout << "0 - Sair " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Digite a sua opção: ";
   
}

void executaOpcao(){

Produto produtos[prodMax];
int quantidadeAtual = 0;
int escolha;
loadProd(produtos, quantidadeAtual); 

    do{

        showMenu();
        cin >> escolha;

        system("clear");

        switch (escolha) {
        case 1:
            addProduto(produtos, quantidadeAtual);
            break;
        case 2:
            cout << "-----------------------------------------------" << endl;
            cout << "O valor total em stock é: " << calcularValorTotal(produtos, quantidadeAtual) << "€" << endl;
            break;
        case 3:
            consultProd(produtos, quantidadeAtual); 
            break;
        case 4:
            changeProd(produtos, quantidadeAtual);
            break;
        case 5:
            eliminateProd(produtos, quantidadeAtual); 
            break;
        case 0: 
            cout << "-----------------------------------------------" << endl;
            cout << "A sair do programa..." << endl; 
            cout << "-----------------------------------------------" << endl;
            break;
        default:
            cout << "-----------------------------------------------" << endl;
            cout << "Opção inválida! Voltando ao menu..." << endl;
        }

    } while(escolha != 0);
}

int main(){

    system("clear");
    executaOpcao();

    return 0;
}