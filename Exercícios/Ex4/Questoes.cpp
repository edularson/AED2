#include <iostream>
using namespace std;

// Q1
void imprimeFilhos(no *T){
    if (T != NULL){
        if (T->Llink != NULL && T->Rlink != NULL){
            cout << "\n No: " << T->info
                 << " -> Filho Esquerda: " << T->Llink->info
                 << ", Filho Direita: " << T->Rlink->info;
        }
        imprimeFilhosDoisNos(T->Llink);
        imprimeFilhosDoisNos(T->Rlink);
    }
};

//Q2
void imprimePai(no *T, int x)
{
    no *pai = encontraPai(T, x, NULL);
    if (pai != NULL)
    {
        cout << "\n O pai do no " << x << " e: " << pai->info;
    }
    else
    {
        cout << "\n O no " << x << " nao possui pai (e a raiz ou nao foi encontrado)";
    }
}

no *encontraPai(no *T, int x, no *pai)
{
    if (T == NULL)
    {
        return NULL;
    }
    if (T->info == x)
    {
        return pai;
    }
    if (x < T->info)
    {
        return encontraPai(T->Llink, x, T);
    }
    else
    {
        return encontraPai(T->Rlink, x, T);
    }
}

//Q3
void emOrdemDecrescente(no *T){
    if (T != NULL){
        emOrdemDecrescente(T->Rlink);
        cout << "\n " << T->info;
        emOrdemDecrescente(T->Llink);
    }
}

//Q4
void apagaArvore(no *T){
    if (T != NULL){
        apagaArvore(T->Llink);
        apagaArvore(T->Rlink);
        delete T;
    }
}

//Q5
int contaNos(no *T){
    if (T == NULL){
        return 0;
    } else {
        return 1 + contaNos(T->Llink) + contaNos(T->Rlink);
    }
}

//Q6
int somaNos(no *T){
    if (T == NULL){
        return 0;
    } else {
        return T->info + somaNos(T->Llink) + somaNos(T->Rlink);
    }
}

//Q7
no *rotacaoEsquerda(no *p){
    no *temp, *q;
    q = p->Rlink;
    temp = q->Llink;
    q->Llink = p;
    p->Rlink = temp;
    return q;
}

//Q8
no *rotacaoDireita(no *p){
    no *temp, *q;
    q = p->Llink;
    temp = q->Rlink;
    q->Rlink = p;
    p->Llink = temp;
    return q;
}

//Q9
no *menor_AB(no *T){
    if (T == NULL) {
        return NULL;
    }
    while (T->Llink != NULL) {
        T = T->Llink;
    }
    return T;
}
