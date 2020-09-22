/**
 * Implementacao de uma arvore binaria
 */
#include <iostream>
#include "BinaryTree.h"
using std::cout;
using std::endl;

struct Node { // sem ponteiro para no pai
    int key;
    Node *left; // subarvore esquerda
    Node *right; // subarvore direita
};

Node* bt_emptyTree() {
    return nullptr;
}

Node* bt_create(int key, Node* l, Node* r) {
    Node* novo = new Node{};
    novo->key = key;
    novo->left = l;
    novo->right = r;
    return novo;
}

bool bt_empty(Node* node) {
    return (node == nullptr);
}

void bt_print(Node* node) {
    if ( ! bt_empty(node) ) {
        cout << node->key << endl;
        bt_print(node->left);
        bt_print(node->right);
    }
}

bool bt_contains(Node* node, int key) {
    if (node == nullptr) 
        return false; // Sub-arvore vazia 
    else 
        return node->key == key || 
               bt_contains(node->left, key) || 
               bt_contains(node->right, key);
}

int bt_count_leafs(Node *node) {
    if(bt_empty(node))
        return 0;
    return bt_count_leafs(node->left) + bt_count_leafs(node->right) + 1;

}

Node *bt_copy(Node *root) {
    return root;
}

Node* bt_destroy(Node* node) {
    if (node != nullptr) {
        node->left = bt_destroy(node->left);
        node->right = bt_destroy(node->right);
        cout << "Deleting " << node->key << endl;
        delete node;
    }
    return nullptr;
}

