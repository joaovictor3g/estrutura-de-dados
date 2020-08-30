#ifndef LISTCIRC_H
#define LISTCIRC_H

struct Node;

class List {    
private: 
    Node *head;
    Node *search(int x);
    Node *prevNode(int x);
public:
    List();
    ~List();
    void addBack(int x); // Adiciona elemento no fim da lista
    void print(); // Imprime os elementos da lista
    void addFront(int x); // Adiciona um elemento no começo da lista
    void clear(); // Remove todos os nós
    void remove(int x); // Remove o primeiro nó com value == x
    void removeAll(int x); // Remove todos os nós com value == x
    bool contains(int x);
    bool isEmpty();
    int size();
    int recursiveSize(Node *node);

};
    
#endif