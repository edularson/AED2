#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Definindo a constante para o tamanho máximo da heap
const int MAX_tam = 100;  // Define o tamanho máximo da heap
int heap[MAX_tam];         // Array que representa a heap
int tam = 0;               // Variável que armazena o número atual de elementos na heap

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

// Função recursiva para ajustar a posição de um elemento na heap para cima (max-heap)
void ajusta_MaxHeap(int posicaoElemento) {
    if (posicaoElemento == 0) return;  // Se o índice for 0, já é a raiz, então não precisa ajustar.

    int parent = (posicaoElemento - 1) / 2;  // Calcula o índice do pai do elemento.
    if (heap[posicaoElemento] > heap[parent]) {  // Se o elemento for maior que seu pai, troca os valores.
        swap(heap[posicaoElemento], heap[parent]);
        ajusta_MaxHeap(parent);  // Chama recursivamente para garantir a propriedade de heap.
    }
}

// Função recursiva para ajustar a heap após a remoção do maior valor
void ajusta_MaxHeap_Pos_Remocao(int posicaoElemento) {
    int maior = posicaoElemento;
    int Llink = 2 * posicaoElemento + 1;  // Índice do filho esquerdo
    int Rlink = 2 * posicaoElemento + 2;  // Índice do filho direito

    // Verifica se o filho esquerdo é maior que o elemento atual
    if (Llink < tam && heap[Llink] > heap[maior]) {
        maior = Llink;
    }

    // Verifica se o filho direito é maior que o maior elemento
    if (Rlink < tam && heap[Rlink] > heap[maior]) {
        maior = Rlink;
    }

    // Se o maior não for o elemento atual, troca e chama recursivamente.
    if (maior != posicaoElemento) {
        swap(heap[posicaoElemento], heap[maior]);
        ajusta_MaxHeap_Pos_Remocao(maior);
    }
}

// Função para inserir um valor na MaxHeap
void insereMaxHeap(int value) {
    if (tam >= MAX_tam) {  // Verifica se a heap atingiu seu tam máximo
        cout << "Heap está cheio!" << endl;
        return;
    }

    heap[tam] = value;  // Insere o valor no final da heap
    ajusta_MaxHeap(tam);  // Ajusta a heap para manter a propriedade de MaxHeap
    tam++;  // Incrementa o tam da heap
}

// Função para retornar o maior valor da MaxHeap (raiz) e removê-lo
int maiorValorMaxHeap() {
    if (tam == 0) {  // Verifica se a heap está vazia
        cout << "Heap vazio!" << endl;
        return -1;
    }

    int max = heap[0];  // O maior valor é sempre a raiz
    heap[0] = heap[tam - 1];  // Substitui a raiz pelo último elemento
    tam--;  // Diminui o tam da heap
    ajusta_MaxHeap_Pos_Remocao(0);  // Ajusta a heap após a remoção do maior valor

    return max;
}

// Função para imprimir a heap por níveis (como uma árvore binária)
void imprimeArvorePorNiveis() {
    int nivel = 0;
    int inicio = 0;
    while (inicio < tam) {
        int fim = min((int)pow(2, nivel) - 1 + inicio, tam - 1);  // Determina os limites do nível
        cout << "Nivel " << nivel << ": ";
        for (int i = inicio; i <= fim; i++) {
            cout << heap[i] << " ";  // Imprime os elementos no nível atual
        }
        cout << endl;
        inicio = fim + 1;
        nivel++;  // Avança para o próximo nível
    }
}

// Função para exibir a heap atual por níveis
void atualizaMaxHeap() {
    cout << endl << "MaxHeap atual (por niveis)" << endl;
    imprimeArvorePorNiveis();  // Exibe a heap organizada por níveis
    cout << endl;
}

int main() {
    cout << arte_ascii1 << " " << endl;  // Exibe a arte ASCII
    cout << endl;

    cout << "Teste: 8 : 31 : 19 : 14 : 73 : 35" << endl;
    cout << endl;

    // Soma dos dias de aniversário: 12 + 19 = 31
    // Soma dos meses de aniversário: 12 + 2 = 14

    // Vetor com os valores a serem inseridos
    int valores[] = {8, 31, 19, 14, 73, 35};
    
    // Laço para inserir os valores na heap e atualizar
    for (int i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        insereMaxHeap(valores[i]);
        atualizaMaxHeap();
    }

    cout << "Maior valor da Heap: " << maiorValorMaxHeap() << endl;
    cout << endl;

    // Exibe a MaxHeap depois de excluir o maior valor
    cout << "MaxHeap depois de excluir o maior valor (por niveis): " << endl;
    imprimeArvorePorNiveis();

    return 0;
}

