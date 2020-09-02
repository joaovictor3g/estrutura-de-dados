#ifndef CIRC_LIST_DOUBLE_LINKED
#define CIRC_LIST_DOUBLE_LINKED

struct Node;

class List {
private:
    // Cabeça da Lista: Aponta para o primeiro nó válido
    Node *head; 
    // Remove da lista o nó apontado pelo ponteiro p.
    void removeNode(Node *p);
    // Retorna o primeiro nó que contem um campo com o valor igual a key
    Node *searchNode(int key);
    // Retorna o tamanho da lista recursivamente
    int auxRecursiveSize(Node *no);
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
    // Remove da lista a primeira ocorrência do inteiro key
    void remove(int key);
    // Imprime as chaves dos nós inversamente
    void printReverse();
    // Remove da lista todas as ocorrências do inteiro key.
    void removeAll(int key);
    // Retorna true se lista vazia e false caso contrário
    bool isEmpty();
    int size();

};

#endif