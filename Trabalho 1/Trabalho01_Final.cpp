#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

void inserir(Node*& root, int data, string caminho) {
    if (root == nullptr) {
        root = newNode(data);
        return;
    }

    Node* atual = root;
    for (int i = 0; i < caminho.length() - 1; ++i) {
        if (caminho[i] == 'L') {
            if (atual->left == nullptr) {
                atual->left = newNode(-1); // Nó temporário
            }
            atual = atual->left;
        } else if (caminho[i] == 'R') {
            if (atual->right == nullptr) {
                atual->right = newNode(-1); // Nó temporário
            }
            atual = atual->right;
        }
    }

    if (caminho.back() == 'L') {
        atual->left = newNode(data);
    } else if (caminho.back() == 'R') {
        atual->right = newNode(data);
    }
}

void imprimirArvore(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    imprimirArvore(root->left);
    imprimirArvore(root->right);
}

int main() {
    Node* root = nullptr;
    int data;
    string caminho;

    while (true) {
        cout << "Digite o valor do nó (-1 para sair): ";
        cin >> data;
        if (data == -1) break;

        cout << "Digite o caminho (L para esquerda, R para direita): ";
        cin >> caminho;

        inserir(root, data, caminho);
    }

    cout << "Árvore resultante: ";
    imprimirArvore(root);
    cout << endl;

    return 0;
}