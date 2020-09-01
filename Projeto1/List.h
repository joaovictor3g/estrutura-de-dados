#ifndef CIRC_LIST_DOUBLE_LINKED
#define CIRC_LIST_DOUBLE_LINKED

struct Node;

class List {
private:
    // Cabeça da Lista: Aponta para o primeiro nó válido
    Node *head; 
    // Remove da lista o nó apontado pelo ponteiro p.
    void removeNode(Node *p);
public: 
    // Construtor: Inicia a lista com valores válidos
    List();
    // Destrutor: Libera memória alocada
    ~List();
    // Insere um inteiro key ao final da lista.
    void pushBack(int key);
    // Imprime todos os elementos da lista.
    void print();
    // Remove elemento do final da lista e retorna seu valor.
    int popBack();
    //Insere um novo nó com valor key após o k-ésimo nó da lista.
    void insertAfter(int key, int k);
    void auxRemoveNode();
    
};

#endif