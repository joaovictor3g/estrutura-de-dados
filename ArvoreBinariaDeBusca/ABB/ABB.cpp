#include <iostream>
#include <climits>
#include "ABB.h"

using std::cout;
using std::endl;

// O no da arvore eh definido como um struct
struct nodeTree {
    int key;
    nodeTree* left;
    nodeTree* right;
};


int abb_get_key(nodeTree* no) {
    return (no != nullptr) ? no->key : INT_MIN;
}

// Recebe a raiz da arvore e uma chave k e retorna
// um ponteiro para o no contendo a chave k caso ela
// exista na arvore , ou retorna nullptr caso contrario .
nodeTree* abb_search(nodeTree* no, int key) {
    if(no == nullptr || no->key == key) 
        return no;
    if(key < no->key) 
        return abb_search(no->left, key);
    return abb_search(no->right, key);
}

nodeTree* abb_insert(nodeTree *root, int key) {
    if(root == nullptr) {
        root = new nodeTree;
        root->key = key;
        root->left = root->right = nullptr;
    
    }else if(key > root->key)     root->right = abb_insert(root->right, key);
    else if(key < root->key)      root->left = abb_insert(root->left, key);

    return root;
}

nodeTree* abb_insert_iteractive(nodeTree *root, int key) {
    if(root == nullptr) {
        root = new nodeTree;
        root->key = key;
        root->left = root->right = nullptr;
    
    } else if(key > root->key) {
        if(root->right == nullptr) {
            
        }
    }


    return root;
}
