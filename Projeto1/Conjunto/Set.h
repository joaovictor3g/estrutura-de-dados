#ifndef SET_H
#define SET_H

struct Node;

class Set {
private:
    Node *head;
    Node *search(int value);
public:
    // Construtor
    Set();
    // Destrutor
    ~Set(); 
    // Adicionar valor
    void insert(int value);
    // recebe os conjuntos A e B como parâmetro e retorna o conjunto C= A ∪ B.
    Set* unionSet(Set *set1, Set *set2);
    // Imprime os elementos do conjunto
    void print();
    // recebe os conjuntos A e B como parâmetro e retorna o con-
    // junto C = A ∩ B.
    Set* intersectionSet(Set *set1, Set *set2);
    // Verifica se o conjunto está vazio ou não;
    bool isEmptySet();
    // Retotna tamanho do conjunto;
    int size();
    // Verifica se o valor existe no conjunto.
    bool contains(int value);
    // recebe os conjuntos A e B como parâmetro e retorna o conjunto
    // C = A - B.
    Set* diference(Set *set1, Set *set2);
    // recebe o conjunto A e um elemento y e remove y do conjunto A, isto
    // é, A = A - y.
    void remove(int value);
    // Retorna 1 se o o elemento passado por parâmetro pertence ao conjunto e 0 caso contrário
    int member(int value);
    // cria um conjunto vazio
    Set* createEmptySet();
    // Retorna o menor valor do conjunto
    int min(Set *a);
    // Retorna o maior valor do conjunto
    int max(Set *a);
    // retorna true se os conjuntos A e B são iguais e false caso contrário.
    bool isEqual(Set *a, Set *b);
    // recebe os conjuntos A e B como parâmetro e re-
    // torna o conjunto C = A xor B.
    Set *simetricDiference(Set *a, Set *b);
    // Remove todos os nós
    // faz uma cópia do conjunto A em B.
    Set *copy(Set *set1, Set *set2);
    // Remove todos os nós do conjunto
    void clear();
};

#endif