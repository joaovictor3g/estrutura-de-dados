#ifndef SET_H
#define SET_H

struct Node;

class Set {
private:
    Node *head;
public:
    // Construtor
    Set();
    // Destrutor
    ~Set(); 
    // Adicionar valor
    void add(int value);
    // recebe os conjuntos A e B como parâmetro e retorna o conjunto C= A ∪ B.
    Set* unionSet(Set *set1, Set *set2);
    void print();
};

#endif