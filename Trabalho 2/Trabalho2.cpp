#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;


string arte_ascii1 = R"(
 /$$      /$$                     /$$   /$$                              
| $$$    /$$$                    | $$  | $$                              
| $$$$  /$$$$  /$$$$$$  /$$   /$$| $$  | $$  /$$$$$$   /$$$$$$   /$$$$$$ 
| $$ $$/$$ $$ |____  $$|  $$ /$$/| $$$$$$$$ /$$__  $$ |____  $$ /$$__  $$
| $$  $$$| $$  /$$$$$$$ \  $$$$/ | $$__  $$| $$$$$$$$  /$$$$$$$| $$  \ $$
| $$\  $ | $$ /$$__  $$  >$$  $$ | $$  | $$| $$_____/ /$$__  $$| $$  | $$
| $$ \/  | $$|  $$$$$$$ /$$/\  $$| $$  | $$|  $$$$$$$|  $$$$$$$| $$$$$$$/
|__/     |__/ \_______/|__/  \__/|__/  |__/ \_______/ \_______/| $$____/ 
                                                               | $$      
                                                               | $$      
                                                               |__/      
)";

// Estrutura para representar um nó da árvore
struct TreeNo {
    int info;              // Valor armazenado no nó
    struct TreeNo *Llink;  // Ponteiro para o filho esquerdo
    struct TreeNo *Rlink;  // Ponteiro para o filho direito
};

// Protótipos das funções
int altura_MaxHeap(TreeNo *T);
void imprime_em_niveis(TreeNo *T);

// Função para inicializar o MaxHeap
// Retorna NULL para indicar uma árvore vazia
TreeNo *ini_MaxHeap(TreeNo *T) {
    return NULL;
}

// Função para trocar dois valores
// Parâmetros:
// - 'a' e 'b': referências aos inteiros a serem trocados
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para inserir um novo elemento no MaxHeap e manter a propriedade do MaxHeap
// Parâmetros:
// - 'T': ponteiro para o nó raiz do MaxHeap
// - 'x': valor a ser inserido no MaxHeap
// Retorna o ponteiro atualizado do nó raiz
TreeNo *insere_MaxHeap(TreeNo *T, int x) {
    if (T == NULL) {
        // Cria um novo nó se a árvore estiver vazia
        T = (TreeNo *) malloc(sizeof(TreeNo));
        T->info = x;
        T->Llink = NULL;
        T->Rlink = NULL;
    } else {
        // Insere o elemento na subárvore esquerda ou direita, mantendo o balanceamento
        if (T->Llink == NULL) {
            T->Llink = insere_MaxHeap(T->Llink, x);
        } else if (T->Rlink == NULL) {
            T->Rlink = insere_MaxHeap(T->Rlink, x);
        } else {
            // Insere na subárvore com menor altura
            if (altura_MaxHeap(T->Llink) <= altura_MaxHeap(T->Rlink))
                T->Llink = insere_MaxHeap(T->Llink, x);
            else
                T->Rlink = insere_MaxHeap(T->Rlink, x);
        }
        
        // Ajusta a propriedade do MaxHeap
        if (T->Llink != NULL && T->Llink->info > T->info)
            swap(T->info, T->Llink->info);
        if (T->Rlink != NULL && T->Rlink->info > T->info)
            swap(T->info, T->Rlink->info);
    }
    return T;
}

// Função para obter a altura do MaxHeap
// Parâmetro:
// - 'T': ponteiro para o nó raiz
// Retorna a altura da árvore
int altura_MaxHeap(TreeNo *T) {
    if (T == NULL) return 0;
    int aL = altura_MaxHeap(T->Llink);
    int aR = altura_MaxHeap(T->Rlink);
    return max(aL, aR) + 1;
}

// Função para percorrer e imprimir o MaxHeap em ordem decrescente (pré-ordem)
// Parâmetro:
// - 'T': ponteiro para o nó raiz do MaxHeap
void imprime_MaxHeap(TreeNo *T) {
    if (T != NULL) {
        cout << T->info << " ";
        imprime_MaxHeap(T->Llink);
        imprime_MaxHeap(T->Rlink);
    }
}

// Função para remover o maior elemento (raiz) do MaxHeap
// Parâmetro:
// - 'T': ponteiro para o nó raiz do MaxHeap
// Retorna o ponteiro atualizado do nó raiz após a remoção
TreeNo *remove_MaxHeap(TreeNo *T) {
    if (T == NULL)
        return NULL;
    
    // Caso o nó não tenha filhos, libera a memória e retorna NULL
    if (T->Llink == NULL && T->Rlink == NULL) {
        free(T);
        return NULL;
    }

    // Troca a raiz com o maior filho e ajusta o MaxHeap
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

// Função para imprimir o MaxHeap em níveis, facilitando a visualização em árvore
// Parâmetro:
// - 'T': ponteiro para o nó raiz do MaxHeap
void imprime_em_niveis(TreeNo *T) {
    if (T == NULL) return;

    queue<TreeNo*> q;
    q.push(T);
    
    int nivel = 0;
    while (!q.empty()) {
        int n = q.size();
        cout << "Nivel " << nivel << ": ";
        for (int i = 0; i < n; i++) {
            TreeNo *temp = q.front();
            q.pop();
            cout << temp->info << " ";
            if (temp->Llink != NULL) q.push(temp->Llink);
            if (temp->Rlink != NULL) q.push(temp->Rlink);
        }
        cout << endl;
        nivel++;
    }
}

// Função principal
int main() {
    TreeNo *heap = ini_MaxHeap(heap);  // Inicializa o MaxHeap vazio

    // Dados dos estudantes para criação do conjunto de dados de teste
    int diaLarson = 12;  // Dia de aniversário de Eduardo
    int mesLarson = 13;  // Mês de aniversário de Eduardo (12 + 1)
    int diaThiago = 19;  // Dia de aniversário de Thiago
    int mesThiago = 2;   // Mês de aniversário de Thiago

    // Soma dos dias e meses dos aniversários dos estudantes
    int somaDia = diaLarson + diaThiago;
    int somaMes = mesLarson + mesThiago;

    // Conjunto de dados para inserção no MaxHeap
    int data[] = {8, diaLarson, mesLarson, diaThiago, mesThiago, 73, 35};

    // Insere cada elemento do conjunto de dados no MaxHeap
    for (int i = 0; i < 7; i++) {
        heap = insere_MaxHeap(heap, data[i]);
    }

    cout << arte_ascii1 << " " << endl;

    // Imprime o MaxHeap em ordem decrescente
    cout << "MaxHeap em ordem decrescente (pre-ordem): ";
    imprime_MaxHeap(heap);
    cout << endl;

    // Exibe o MaxHeap em níveis
    cout << endl << "MaxHeap em niveis:" << endl;
    imprime_em_niveis(heap);
    cout << endl;

    // Remove o maior elemento (raiz) do MaxHeap e imprime o resultado
    heap = remove_MaxHeap(heap);
    cout << "Apos remover o maior elemento (pre-ordem): ";
    imprime_MaxHeap(heap);
    cout << endl;

    cout << endl << "MaxHeap apos remocao em niveis:" << endl;
    imprime_em_niveis(heap);
    cout << endl;

    // Exibe as somas dos dias e meses dos aniversários
    cout << "Soma dos dias do aniversario da dupla: " << somaDia << endl;
    cout << "Soma dos meses do aniversario da dupla: " << somaMes << endl;

    return 0;
}
