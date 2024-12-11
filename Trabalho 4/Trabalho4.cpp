#include <iostream>
#include <string>
#include <memory>

using namespace std;

typedef struct TreeNo
{
    string info;
    TreeNo *Llink;
    TreeNo *Rlink;
} No;

No *criarNo(const string &valor)
{
    No *novoNo = new No;
    novoNo->info = valor;
    novoNo->Llink = nullptr;
    novoNo->Rlink = nullptr;
    return novoNo;
}

string arte_ascii1 = R"(
 ####### ##   ##   # #####                     ###    ### ###   ######  ##   ##    ###     # #####  #####   ######
  ##   # ##   ##  ## ## ##                    ## ##    ## ##      ##    ###  ##   ## ##   ## ## ## ### ###   ##  ##
  ##     ##   ##     ##                      ##   ##   ####       ##    #### ##  ##   ##     ##    ##   ##   ##  ##
  ####   ##   ##     ##                      ##   ##   ###        ##    #######  ##   ##     ##    ##   ##   #####
  ##     ##   ##     ##                      #######   ####       ##    ## ####  #######     ##    ##   ##   ## ##
  ##     ##   ##     ##                      ##   ##   ## ##      ##    ##  ###  ##   ##     ##    ### ###   ## ##
 ####     #####     ####                     ##   ##  ### ###   ######  ##   ##  ##   ##    ####    #####   #### ##
)";

void deletarArvore(No *no)
{
    if (no)
    {
        deletarArvore(no->Llink);
        deletarArvore(no->Rlink);
        delete no;
    }
}

void jogarRecursivo(No *no)
{
    if (!no)
        return;

    if (!no->Llink && !no->Rlink)
    {
        cout << "Você está pensando em " << no->info << "? (sim/nao): ";
        string resposta;
        while (true)
        {
            cin >> resposta;
            if (resposta == "sim" || resposta == "nao")
            {
                break;
            }
            else
            {
                cout << "Por favor, responda com 'sim' ou 'nao'.\n";
            }
        }

        if (resposta == "sim")
        {
            cout << "Acertei! :D\n";
        }
        else
        {
            cout << "Quem era então? ";
            string novaResposta;
            cin.ignore(); // Limpar buffer
            getline(cin, novaResposta);

            cout << "O que poderia diferenciar " << novaResposta << " de " << no->info << "?\n";
            string novaPergunta;
            getline(cin, novaPergunta);

            No *novoNoResposta = criarNo(novaResposta);
            No *noRespostaAtual = criarNo(no->info);

            no->info = novaPergunta;
            no->Llink = novoNoResposta;
            no->Rlink = noRespostaAtual;
        }
        return;
    }

    cout << no->info << " (sim/nao): ";
    string resposta;
    while (true)
    {
        cin >> resposta;
        if (resposta == "sim" || resposta == "nao")
        {
            break;
        }
        else
        {
            cout << "Por favor, responda com 'sim' ou 'nao'.\n";
        }
    }

    if (resposta == "sim")
    {
        jogarRecursivo(no->Llink);
    }
    else
    {
        jogarRecursivo(no->Rlink);
    }
}

No *inicializarArvore()
{
    No *raiz = criarNo("O uniforme principal é vermelho?");

    raiz->Llink = criarNo("É um time brasileiro?");
    raiz->Llink->Llink = criarNo("Flamengo");
    raiz->Llink->Rlink = criarNo("O time é da Espanha?");
    raiz->Llink->Rlink->Llink = criarNo("Sevilla");
    raiz->Llink->Rlink->Rlink = criarNo("Liverpool");

    raiz->Rlink = criarNo("O uniforme principal é azul?");
    raiz->Rlink->Llink = criarNo("É um time europeu?");
    raiz->Rlink->Llink->Llink = criarNo("O time é da Inglaterra?");
    raiz->Rlink->Llink->Llink->Llink = criarNo("Chelsea");
    raiz->Rlink->Llink->Llink->Rlink = criarNo("Napoli");
    raiz->Rlink->Llink->Rlink = criarNo("Cruzeiro");

    raiz->Rlink->Rlink = criarNo("O uniforme principal é preto e branco?");
    raiz->Rlink->Rlink->Llink = criarNo("O time é brasileiro?");
    raiz->Rlink->Rlink->Llink->Llink = criarNo("Botafogo");
    raiz->Rlink->Rlink->Llink->Llink->Rlink = criarNo("Corinthians");
    raiz->Rlink->Rlink->Llink->Rlink = criarNo("O time é europeu?");
    raiz->Rlink->Rlink->Llink->Rlink->Llink = criarNo("Juventus");
    raiz->Rlink->Rlink->Llink->Rlink->Llink->Rlink = criarNo("Newcastle");

    return raiz;
}

void jogar(No *raiz)
{
    cout << "Vamos jogar Akinator! Pense em um time de futebol e eu tentarei adivinhar.\n";
    jogarRecursivo(raiz);
}

int main() {
    system("chcp 65001");
    system("cls");

    No *raiz = inicializarArvore();
    int escolha;
    do {
        cout << arte_ascii1 << " " << endl;
        cout << "Menu:\n";
        cout << "1. Jogar\n";
        cout << "2. Parar\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                jogar(raiz);
                break;
            case 2:
                cout << "Obrigado por jogar!\n";
                break;
            default:
                cout << "Opção inválida. Por favor, escolha novamente.\n";
        }
    } while (escolha != 2);

    deletarArvore(raiz);

    return 0;
}
