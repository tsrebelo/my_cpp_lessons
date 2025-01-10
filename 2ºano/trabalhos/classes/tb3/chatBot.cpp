#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Função para carregar as perguntas e respostas já armazenadas no arquivo
void carregarConversas(vector<pair<string, string>>& conversas) {
    ifstream arquivo("conversas.txt");
    string pergunta, resposta;
    
    if (arquivo.is_open()) {
        while (getline(arquivo, pergunta)) {
            getline(arquivo, resposta);
            conversas.push_back(make_pair(pergunta, resposta));
        }
        arquivo.close();
    } else {
        cout << "Não foi possível carregar as conversas anteriores." << endl;
    }
}

// Função para salvar uma nova conversa (pergunta e resposta) no arquivo
void salvarConversa(const string& pergunta, const string& resposta) {
    ofstream arquivo("conversas.txt", ios::app);  // Abre o arquivo para adicionar novas conversas
    if (arquivo.is_open()) {
        arquivo << pergunta << "\n" << resposta << "\n";
        arquivo.close();
    } else {
        cout << "Erro ao salvar a conversa!" << endl;
    }
}

// Função para conversar com o usuário
void conversar() {
    vector<pair<string, string>> conversas;
    carregarConversas(conversas);  // Carregar as conversas anteriores
    
    string entrada, resposta;
    bool encontrouResposta;
    
    cout << "Olá! Como posso ajudar?" << endl;
    
    while (true) {
        cout << "Você: ";
        getline(cin, entrada);

        // Verifica se o usuário quer encerrar a conversa
        if (entrada == "sair" || entrada == "exit") {
            cout << "Tchau! Foi bom conversar com você!" << endl;
            break;
        }
        
        // Tenta encontrar uma resposta para a pergunta
        encontrouResposta = false;
        for (const auto& conversa : conversas) {
            if (entrada == conversa.first) {
                resposta = conversa.second;
                encontrouResposta = true;
                break;
            }
        }
        
        // Se não encontrou uma resposta, pede para o usuário ensinar
        if (encontrouResposta) {
            cout << "PC: " << resposta << endl;
        } else {
            cout << "PC: Não sei a resposta para isso. Quer me ensinar? (s/n) ";
            string respostaEnsinar;
            getline(cin, respostaEnsinar);

            if (respostaEnsinar == "s" || respostaEnsinar == "sim") {
                cout << "Você: Qual é a resposta para '" << entrada << "'?" << endl;
                getline(cin, resposta);
                salvarConversa(entrada, resposta);  // Salva a nova conversa no arquivo
                cout << "PC: Agora eu sei a resposta!" << endl;
            } else {
                cout << "PC: Ok, vou tentar aprender outra hora." << endl;
            }
        }
    }
}

int main() {
    conversar();
    return 0;
}
