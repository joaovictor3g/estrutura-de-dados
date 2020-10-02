#ifndef ABB_H
#define ABB_H

struct nodeTree;

int abb_get_key(nodeTree* no); // retorna chave do nó

void abb_preorder(nodeTree* raiz); // percurso em preordem

nodeTree* abb_destroy(nodeTree* raiz); // libera memoria

nodeTree* abb_search(nodeTree* raiz, int k); // busca chave k

nodeTree* abb_insert(nodeTree* raiz, int k); // insere chave k

nodeTree* abb_insert_iteractive(nodeTree *raiz, int key);

nodeTree* abb_remove(nodeTree* raiz, int k ); // remove chave k

void remove_predecessor(nodeTree* no); // funcao auxiliar

nodeTree* abb_minimum(nodeTree* raiz); // retorna no minimo

nodeTree* abb_maximum(nodeTree* raiz); // retorna no

nodeTree* abb_successor(nodeTree* x, nodeTree* raiz); // Retorna o sucessor

nodeTree* abb_predecessor(nodeTree* x, nodeTree* raiz); // Retorna o sucessor

#endif 