#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeNo {
    int info;
    struct TreeNo *Llink;
    struct TreeNo *Rlink;
};

// Protótipo da função altura_MaxHeap
int altura_MaxHeap(TreeNo *T);

// Inicializa a árvore
TreeNo *ini_MaxHeap(TreeNo *T) {
    return NULL;
}

// Função para trocar dois valores
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para inserir um novo elemento no MaxHeap e ajustar a árvore
TreeNo *insere_MaxHeap(TreeNo *T, int x) {
    if (T == NULL) {
        // Se a árvore está vazia, cria um novo nó
        T = (TreeNo *) malloc(sizeof(TreeNo));
        T->info = x;
        T->Llink = NULL;
        T->Rlink = NULL;
    } else {
        // Inserir o elemento na subárvore esquerda ou direita
        if (T->Llink == NULL) {
            T->Llink = insere_MaxHeap(T->Llink, x);
        } else if (T->Rlink == NULL) {
            T->Rlink = insere_MaxHeap(T->Rlink, x);
        } else {
            // Inserir de forma balanceada
            if (altura_MaxHeap(T->Llink) <= altura_MaxHeap(T->Rlink))
                T->Llink = insere_MaxHeap(T->Llink, x);
            else
                T->Rlink = insere_MaxHeap(T->Rlink, x);
        }

        // Após inserir, ajusta a propriedade do MaxHeap
        if (T->Llink != NULL && T->Llink->info > T->info)
            swap(T->info, T->Llink->info);
        if (T->Rlink != NULL && T->Rlink->info > T->info)
            swap(T->info, T->Rlink->info);
    }
    return T;
}

// Função para obter a altura do MaxHeap
int altura_MaxHeap(TreeNo *T) {
    if (T == NULL) return 0;
    int aL = altura_MaxHeap(T->Llink);
    int aR = altura_MaxHeap(T->Rlink);
    return max(aL, aR) + 1;
}

// Função para percorrer e imprimir o MaxHeap em ordem decrescente
void imprime_MaxHeap(TreeNo *T) {
    if (T != NULL) {
        imprime_MaxHeap(T->Rlink);
        cout << T->info << " ";
        imprime_MaxHeap(T->Llink);
    }
}

// Função para remover o maior elemento (raiz) do MaxHeap
TreeNo *remove_MaxHeap(TreeNo *T) {
    if (T == NULL)
        return NULL;
    
    // Se o nó não tem filhos, apaga o nó
    if (T->Llink == NULL && T->Rlink == NULL) {
        free(T);
        return NULL;
    }

    // Caso tenha filhos, trocamos a raiz com o maior filho
    if (T->Llink != NULL && T->Rlink != NULL) {
        if (T->Llink->info > T->Rlink->info) {
            swap(T->info, T->Llink->info);
            T->Llink = remove_MaxHeap(T->Llink);
        } else {
            swap(T->info, T->Rlink->info);
            T->Rlink = remove_MaxHeap(T->Rlink);
        }
    } else if (T->Llink != NULL) {
        swap(T->info, T->Llink->info);
        T->Llink = remove_MaxHeap(T->Llink);
    } else {
        swap(T->info, T->Rlink->info);
        T->Rlink = remove_MaxHeap(T->Rlink);
    }

    return T;
}

// Função principal
int main() {
    TreeNo *heap = ini_MaxHeap(heap);

    // Dados dos estudantes
    int diaLarson = 12;  // Dia de aniversário Eduardo
    int mesLarson = 13; // Mês de aniversário Eduardo (12 + 1)
    int diaThiago = 19; // Dia de aniversário Thaigo 
    int mesThiago = 2;  // Mês de aniversário Thiago

    // Soma dos aniversários dos dois estudantes
    int somaDia = diaLarson + diaThiago;
    int somaMes = mesLarson + mesThiago;

    // Conjunto de dados: soma dos dias, soma dos meses e outros valores
    int data[] = {8, diaLarson, mesLarson, diaThiago, mesThiago, 73, 35};

    // Inserir os elementos no MaxHeap
    for (int i = 0; i < 7; i++) {
        heap = insere_MaxHeap(heap, data[i]);
    }

    cout << "MaxHeap em ordem decrescente: ";
    imprime_MaxHeap(heap);
    cout << endl;

    // Remover a raiz (maior elemento)
    heap = remove_MaxHeap(heap);
    cout << "Apos remover o maior elemento: ";
    imprime_MaxHeap(heap);
    cout << endl;

    // Soma dos dias do aniversário
    cout << "Soma dos dias do aniversario da dupla: " << somaDia << endl;

    // Soma dos meses do aniversário
    cout << "Soma dos meses do aniversario da dupla: " << somaMes << endl;

    return 0;
}
