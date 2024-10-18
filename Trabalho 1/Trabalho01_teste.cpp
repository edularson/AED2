#include <iostream>
using namespace std;

// Estrutura do nó da árvore
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Estrutura do nó da pilha
struct no {
    Node* info;
    no* link;
};

// Função para criar um novo nó da árvore
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Função para inicializar a pilha
no* inicializaPilha(no* L) {
    return nullptr;
}

// Função para empilhar um nó
no* PUSH(no* L, Node* x) {
    no* N = new no;
    N->info = x;
    N->link = L;
    L = N;
    return L;
}

// Função para desempilhar um nó
no* POP(no* L, Node** n) {
    no* AUX;
    if (L != nullptr) {
        *n = L->info;
        AUX = L;
        L = L->link;
        delete AUX;
    } else {
        *n = nullptr;
    }
    return L;
}

// Função para imprimir a árvore em nível usando pilha
void imprimirArvore(Node* root) {
    if (root == nullptr) return;

    no* stack1 = inicializaPilha(nullptr);
    no* stack2 = inicializaPilha(nullptr);
    stack1 = PUSH(stack1, root);

    while (stack1 != nullptr) {
        Node* node;
        stack1 = POP(stack1, &node);
        cout << node->data << " ";

        if (node->left != nullptr)
            stack2 = PUSH(stack2, node->left);
        if (node->right != nullptr)
            stack2 = PUSH(stack2, node->right);

        if (stack1 == nullptr) {
            cout << endl;
            while (stack2 != nullptr) {
                stack2 = POP(stack2, &node);
                stack1 = PUSH(stack1, node);
            }
        }
    }
}

// Função principal para testar o código
int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->left = newNode(8);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);


    cout << "Percurso em Largura da Arvore Binaria usando Pilha eh:\n";
    imprimirArvore(root);

    return 0;
}