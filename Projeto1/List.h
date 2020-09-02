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
    // Retorna tamanho da lista
    int size();
    // Remove todos os nós da lista
    void clear();
    int removeNodeAt(int k);
    // Concatena a lista passada como parâmetro com a lista atual
    void concat(List *list);
    // Retorna um ponteiro para uma cópia desta lista.
    List *copy();
    // Copia os elementos do array arr para a
    // lista. O array arr tem n elementos. Todos os elementos anteriores da lista são
    // mantidos e os elementos do array arr devem ser adicionados após os elementos
    // originais.
    void copyArray(int arr[], int size);
    bool equal(List *list);

};

#endif