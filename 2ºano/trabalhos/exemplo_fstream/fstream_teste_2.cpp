#include <iostream> // Importa a biblioteca para manipulação de entrada e saída no terminal, como cin e cout (inputs e outputs)
#include <fstream>  // Permite a manipulação de arquivos externos (como leitura e escrita em arquivos)
#include <sstream>  // Para manipulação de fluxos de strings, convertendo string em dados estruturados (útil para ler arquivos)

using namespace std; // Evita a necessidade de prefixar objetos da biblioteca padrão com std:: como cout, cin e strings

const string DBfile = "lista.txt"; // Define o nome do arquivo onde os produtos serão armazenados
const int prodMax = 80; // Limita o número máximo de produtos que o programa pode ter

// Define uma estrutura Produto com atributos id, nome, preco, quantidade e status
struct Produto {
    int id;          // Identificador único do produto
    string nome;     // Nome do produto
    float preco;     // Preço do produto
    int quantidade;  // Quantidade disponível do produto
    char status;     // Status do produto ('A' = ativo, 'E' = eliminado)
};

// Função para verificar se o arquivo de base de dados existe e, se necessário, criar um novo
bool fileDB() {
    ifstream file(DBfile); // Tenta abrir o arquivo "lista.txt"
    
    // Se o arquivo não existir
    if (!file) {
        char opcao;

        // Informa ao usuário que o arquivo não foi encontrado e pergunta se deseja criar um novo
        cout << "---------------------------------------------------------" << endl;
        cout << "O ficheiro de base de dados não foi encontrado." << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Deseja criar um novo ficheiro de base de dados? (S/N): ";
        cin >> opcao;

        // Se o usuário escolher 'S', cria o arquivo
        if (opcao == 'S' || opcao == 's') {
            ofstream newFile(DBfile); // Cria um novo arquivo "lista.txt"
            newFile.close(); // Fecha o arquivo após criá-lo
            system("clear"); // Limpa a tela do terminal

            // Confirma ao usuário que o arquivo foi criado
            cout << "-----------------------------------------------" << endl;
            cout << "Ficheiro de base de dados criado com sucesso!" << endl;

            return false; // Retorna false indicando que o arquivo foi criado
        } else {
            // Caso o usuário opte por não criar o arquivo, encerra o programa
            system("clear"); // Limpa a tela do terminal
            cout << "-----------------------------------------------" << endl;
            cout << "A sair do programa..." << endl;
            cout << "-----------------------------------------------" << endl;

            return false; // Termina o programa
        }
    }

    return true; // Se o arquivo já existir, retorna true
}

// Função para carregar os produtos salvos no arquivo "lista.txt"
void loadProd(Produto produtos[], int& quantidadeAtual) {
    ifstream file(DBfile); // Abre o arquivo para leitura
    
    if (!file) return; // Se o arquivo não puder ser aberto, sai da função

    quantidadeAtual = 0; // Inicializa a quantidade de produtos como zero

    // Enquanto houver dados no arquivo e o número de produtos for menor que o máximo permitido (prodMax)
    while (file.good() && quantidadeAtual < prodMax) {
        Produto p;
        string line;

        // Lê uma linha do arquivo
        if (getline(file, line)) {
            stringstream ss(line); // Converte a linha para um fluxo de string
            string status;
            
            // Extrai os campos da linha e armazena no objeto Produto
            getline(ss, status, ','); // Lê o status (ativo/eliminado)
            p.status = status[0];     // Armazena o status como um caractere

            ss >> p.id;               // Lê o ID do produto
            ss.ignore();              // Ignora a vírgula
            getline(ss, p.nome, ','); // Lê o nome do produto

            ss >> p.preco;            // Lê o preço do produto
            ss.ignore();              // Ignora a vírgula
            ss >> p.quantidade;       // Lê a quantidade do produto

            produtos[quantidadeAtual] = p; // Armazena o produto no array
            quantidadeAtual++;             // Incrementa o contador de produtos
        }
    }

    file.close(); // Fecha o arquivo após a leitura
}

// Função para salvar os produtos no arquivo "lista.txt"
void saveProd(const Produto produtos[], int quantidadeAtual) {
    ofstream file(DBfile); // Abre o arquivo para escrita, sobrescrevendo o conteúdo anterior

    // Percorre todos os produtos armazenados no array
    for (int x = 0; x < quantidadeAtual; x++) {
        // Escreve os dados de cada produto no arquivo, separados por vírgula
        file << produtos[x].status << ","
             << produtos[x].id << ","
             << produtos[x].nome << ","
             << produtos[x].preco << ","
             << produtos[x].quantidade << endl; // Cada produto em uma nova linha
    }

    file.close(); // Fecha o arquivo após a gravação

    // Informa ao usuário que os produtos foram salvos
    cout << "-----------------------------------------------" << endl;
    cout << "Produtos salvos com sucesso!" << endl;
}

// Função para consultar os produtos no estoque (ativos, eliminados ou todos)
void consultProd(const Produto produtos[], int quantidadeAtual) {
    char opcao;

    // Se não houver produtos cadastrados, exibe uma mensagem de aviso
    if (quantidadeAtual == 0) {
        cout << "-----------------------------------------------" << endl;
        cout << "Sem produtos adicionados." << "\nVoltando ao menu..." << endl;
        return;
    } else {
        // Pergunta ao usuário se deseja consultar produtos ativos, eliminados ou todos
        cout << "------------------------------------------------------------------" << endl;
        cout << "Quer consultar os produtos ativos(A), eliminados(E) ou todos(T)? ";
        cin >> opcao;

        system("clear"); // Limpa a tela do terminal

        // Exibe apenas os produtos ativos
        if (opcao == 'A' || opcao == 'a') {
            cout << "-----------------------------------------------" << endl;
            cout << "           Lista de produtos ativos" << endl;

            // Itera sobre todos os produtos e exibe apenas os que estão ativos
            for (int a = 0; a < quantidadeAtual; a++) {
                if (produtos[a].status == 'A') { // Verifica se o produto está ativo
                    // Exibe os detalhes do produto
                    cout << "-----------------------------------------------" << endl;
                    cout << "ID: " << produtos[a].id << endl;
                    cout << "Nome: " << produtos[a].nome << endl;
                    cout << "Preço: " << produtos[a].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[a].quantidade << endl;
                    cout << "Status: " << produtos[a].status << endl;
                }
            }
        }

        // Exibe apenas os produtos eliminados
        if (opcao == 'E' || opcao == 'e') {
            cout << "-----------------------------------------------" << endl;
            cout << "         Lista de produtos eliminados" << endl;

            // Itera sobre todos os produtos e exibe apenas os eliminados
            for (int e = 0; e < quantidadeAtual; e++) {
                if (produtos[e].status == 'E') { // Verifica se o produto está eliminado
                    cout << "-----------------------------------------------" << endl;
                    cout << "ID: " << produtos[e].id << endl;
                    cout << "Nome: " << produtos[e].nome << endl;
                    cout << "Preço: " << produtos[e].preco << "€" << endl;
                    cout << "Quantidade: " << produtos[e].quantidade << endl;
                    cout << "Status: " << produtos[e].status << endl;
                }
            }
        }

        // Exibe todos os produtos, tanto ativos quanto eliminados
        if (opcao == 'T' || opcao == 't') {
            cout << "-----------------------------------------------" << endl;
            cout << "          Lista de todos os produtos" << endl;

            // Itera sobre todos os produtos e os exibe
            for (int t = 0; t < quantidadeAtual; t++) {
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

// Função para alterar os dados de um produto específico
void changeProd(Produto produtos[], int quantidadeAtual) {
    int id; // ID do produto a ser alterado

    // Solicita o ID do produto que será alterado
    cout << "-----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja alterar: "; 
    cin >> id; 

    system("clear"); // Limpa a tela

    // Itera sobre o array de produtos para encontrar o produto com o ID fornecido
    for (int y = 0; y < quantidadeAtual; y++) {
        // Verifica se o produto existe e está ativo
        if (produtos[y].id == id && produtos[y].status == 'A') {
            // Solicita e armazena o novo preço do produto
            cout << "-----------------------------------------------" << endl;
            cout << "Insira o novo preço do produto: ";
            cin >> produtos[y].preco;

            // Solicita e armazena a nova quantidade do produto
            cout << "-----------------------------------------------" << endl;
            cout << "Insira a nova quantidade do produto: ";
            cin >> produtos[y].quantidade;

            // Salva as mudanças no arquivo
            saveProd(produtos, quantidadeAtual); 
            system("clear"); // Limpa a tela

            // Confirma que o produto foi alterado
            cout << "-----------------------------------------------" << endl;
            cout << "Produto alterado com sucesso." << endl;

            return; // Encerra a função após a alteração
        }
    }

    // Se o produto não for encontrado ou estiver eliminado, exibe uma mensagem de erro
    cout << "-----------------------------------------------" << endl;
    cout << "Produto não foi encontrado ou já foi eliminado." << endl;
}

// Função para eliminar um produto, alterando o seu status para 'E' (eliminado)
void eliminateProd(Produto produtos[], int quantidadeAtual) {
    int id; // ID do produto a ser eliminado

    // Solicita o ID do produto a ser eliminado
    cout << "-----------------------------------------------" << endl;
    cout << "Insira o ID do produto que deseja eliminar: ";
    cin >> id;

    // Itera sobre o array de produtos para encontrar o produto com o ID fornecido
    for (int w = 0; w < quantidadeAtual; w++) {
        if (produtos[w].id == id) {
            produtos[w].status = 'E'; // Altera o status do produto para 'E' (eliminado)
            saveProd(produtos, quantidadeAtual); // Salva as mudanças no arquivo
            system("clear"); // Limpa a tela

            // Confirma que o produto foi eliminado
            cout << "-----------------------------------------------" << endl;
            cout << "Produto eliminado com sucesso!" << endl;

            return; // Encerra a função após eliminar o produto
        }
    }

    system("clear"); // Limpa a tela

    // Se o produto não for encontrado, exibe uma mensagem de erro
    cout << "-----------------------------------------------" << endl;
    cout << "Produto não encontrado." << endl;
}

// Função para adicionar novos produtos ao estoque
void addProduto(Produto produtos[], int& quantidadeAtual) {
    // Verifica se o limite máximo de produtos foi atingido
    if (quantidadeAtual >= prodMax) {
        // Exibe uma mensagem de erro se o limite de produtos for atingido
        cout << "-----------------------------------------------" << endl;
        cout << "Atingiu o limite máximo de produtos." << "\nNão é possível adicionar mais produtos." << endl;
        return; // Sai da função, sem adicionar nenhum produto
    } else {
        Produto newProduct; // Cria um novo produto
        newProduct.status = 'A'; // Define o status do novo produto como 'A' (ativo)

        // Define o ID do novo produto
        if (quantidadeAtual == 0) {
            newProduct.id = 1; // Se for o primeiro produto, atribui ID 1
        } else {
            newProduct.id = produtos[quantidadeAtual - 1].id + 1; // Atribui o próximo ID disponível
        }       

        // Solicita o nome do novo produto
        cout << "-----------------------------------------------" << endl;
        cout << "Insira o nome do produto: ";
        cin.ignore(); // Limpa o buffer de entrada para evitar problemas com a leitura de strings
        getline(cin, newProduct.nome); // Armazena o nome do produto

        // Solicita o preço do novo produto
        cout << "-----------------------------------------------" << endl;
        cout << "Insira o preço do produto: ";
        cin >> newProduct.preco;

        // Solicita a quantidade do novo produto
        cout << "-----------------------------------------------" << endl;
        cout << "Insira a quantidade do produto: ";
        cin >> newProduct.quantidade;

        // Adiciona o novo produto ao array de produtos
        produtos[quantidadeAtual] = newProduct;
        quantidadeAtual++; // Incrementa a quantidade total de produtos

        // Salva o novo produto no arquivo
        saveProd(produtos, quantidadeAtual);
        system("clear"); // Limpa a tela

        // Confirma que o produto foi adicionado
        cout << "-----------------------------------------------" << endl;
        cout << "O produto foi adicionado." << endl;
    }
}

// Função para calcular o valor total em estoque dos produtos ativos
float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {
    float total = 0; // Inicializa o total como 0

    // Itera sobre todos os produtos
    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].status == 'A') { // Considera apenas os produtos ativos
            // Soma o valor total (preço * quantidade) dos produtos ativos
            total += produtos[i].preco * produtos[i].quantidade;
        }
    }

    return total; // Retorna o valor total do estoque
}

// Função para exibir o menu principal do programa
void showMenu() {
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
    cout << "Digite a sua opção: "; // Solicita que o usuário escolha uma opção do menu
}

// Função para executar a opção selecionada pelo usuário
void executaOpcao() {
    Produto produtos[prodMax]; // Cria um array para armazenar os produtos (tamanho máximo definido por prodMax)
    int quantidadeAtual = 0; // Armazena a quantidade atual de produtos no sistema
    int escolha; // Armazena a escolha do usuário

    loadProd(produtos, quantidadeAtual); // Carrega os produtos do arquivo

    // Loop principal do programa que continua até que o usuário escolha sair (opção 0)
    do {
        showMenu(); // Exibe o menu
        cin >> escolha; // Lê a opção escolhida pelo usuário

        system("clear"); // Limpa a tela

        // Executa a ação correspondente à escolha do usuário
        switch (escolha) {
        case 1:
            addProduto(produtos, quantidadeAtual); // Adiciona um novo produto
            break;

        case 2:
            // Calcula e exibe o valor total dos produtos em estoque
            cout << "-----------------------------------------------" << endl;
            cout << "O valor total em stock é: " << calcularValorTotal(produtos, quantidadeAtual) << "€" << endl;
            break;

        case 3:
            consultProd(produtos, quantidadeAtual); // Consulta os produtos no estoque
            break;

        case 4:
            changeProd(produtos, quantidadeAtual); // Altera as informações de um produto
            break;

        case 5:
            eliminateProd(produtos, quantidadeAtual); // Elimina um produto
            break;

        case 0:
            // Exibe uma mensagem ao sair do programa
            cout << "-----------------------------------------------" << endl;
            cout << "A sair do programa..." << endl;
            cout << "-----------------------------------------------" << endl;
            break;

        default:
            // Exibe uma mensagem de erro se a opção escolhida for inválida
            cout << "-----------------------------------------------" << endl;
            cout << "Opção inválida! Voltando ao menu..." << endl;
        }

    } while (escolha != 0); // Repete até o usuário escolher a opção 0 (sair)
}

// Função principal do programa
int main() {
    system("clear"); // Limpa a tela ao iniciar o programa
    fileDB(); // Verifica se o arquivo de banco de dados existe (ou cria um novo)
    executaOpcao(); // Executa o loop principal de opções do programa

    return 0; // Encerra o programa
}
