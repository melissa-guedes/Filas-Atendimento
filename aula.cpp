#include <iostream>
#define TAM 100

using namespace std;

struct Fila {
    int dados[TAM];
    int inicio, fim;
};

void inicializar(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
}

bool estaVazia(Fila* f) {
    return f->inicio == f->fim;
}

bool estaCheia(Fila* f) {
    return f->fim == TAM;
}

bool enfileirar(Fila* f, int valor) {
    if (estaCheia(f)) return false;
    f->dados[f->fim++] = valor;
    return true;
}

bool desenfileirar(Fila* f, int* valor) {
    if (estaVazia(f)) return false;
    *valor = f->dados[f->inicio++];
    return true;
}

int tamanho(Fila* f) {
    return f->fim - f->inicio;
}

int main() {
    Fila senhasGeradas, senhasAtendidas;
    inicializar(&senhasGeradas);
    inicializar(&senhasAtendidas);

    int opcao, senhaAtual = 1;
    int senha;

    do {
        cout << "\n--- Sistema de Atendimento ---\n";
        cout << "Senhas aguardando: " << tamanho(&senhasGeradas) << endl;
        cout << "0 - Sair\n1 - Gerar Senha\n2 - Realizar Atendimento\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 0:
                if (!estaVazia(&senhasGeradas)) {
                    cout << "Ainda ha senhas aguardando atendimento. Finalize antes de sair.\n";
                } else {
                    cout << "\nSistema encerrado.\n";
                    cout << "Total de senhas atendidas: " << tamanho(&senhasAtendidas) << "\n";
                }
                break;

            case 1:
                if (enfileirar(&senhasGeradas, senhaAtual)) {
                    cout << "Senha gerada: " << senhaAtual << endl;
                    senhaAtual++;
                } else {
                    cout << "Erro: fila cheia, nao foi possivel gerar senha.\n";
                }
                break;

            case 2:
                if (desenfileirar(&senhasGeradas, &senha)) {
                    cout << "Atendendo senha: " << senha << endl;
                    enfileirar(&senhasAtendidas, senha);
                } else {
                    cout << "Nenhuma senha para atender.\n";
                }
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0 || !estaVazia(&senhasGeradas));

    return 0;
}
