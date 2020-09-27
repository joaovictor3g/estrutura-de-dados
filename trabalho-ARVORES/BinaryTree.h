#ifndef ARVOREBIN_H
#define ARVOREBIN_H

struct Node; // Cada no eh do tipo Node

Node* bt_emptyTree(); // retorna nulo, indicando arvore vazia

// cria no com chave 'key'
Node* bt_create(int key, Node* l, Node* r); 

// arvore enraizada em no esta vazia?
bool bt_empty(Node* node); 

void bt_print(Node* node); // imprime as chaves da arvore

bool bt_contains(Node* node, int key); // essa chave pertence?

int bt_count_leafs(Node *node); // conta o número de folhas

int bt_one_child(Node *root); //  retorna a quantidade de nós de uma árvore binária que possuem apenas um filho

int bt_num_interactive(Node *no); // função não-recursiva que calcula o número de nós de uma árvore binária dada como entrada

bool bt_equal(Node *a1, Node *a2); // Verifica se as arvores são identicas

Node* bt_destroy(Node* node); // libera todos os nos alocados

Node *bt_copy(Node *root); // Faz uma cópia da árvore

#endif
