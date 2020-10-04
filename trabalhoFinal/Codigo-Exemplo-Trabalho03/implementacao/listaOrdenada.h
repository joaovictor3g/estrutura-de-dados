#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

struct Node;

class List {
private:
    Node *head;
public:
    // Construtor
    List();
    // Insere um novo nó com a key passada no fim da lista
    void pushBack(int key);
    // Bubble sort interativo
    void linkedIteractiveBubbleSort();
    void swap(Node **a, Node **b);
    // Imprime a lisa
    void print();
    // Destrutor
    ~List();
};

#endif