/*
    Nome: João Victor Dias Barros   Matrícula: 474110
    Disciplina: Estrutura de Dados
*/

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
    // Função auxiliar para testar a função de removeNode
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
    // Verifica se a lista contem a chave especificada
    bool contains(int key);
    // Remove todos os nós da lista
    void clear();
    //     Remove o k-ésimo nó da lista encadeada e retorna
    // o seu valor. Caso o k-ésimo nó não exista, o programa retorna o valor especial
    // INT MIN definido no cabeçalho climits.
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
    // Determina se a lista passada por parâmetro é igual à
    // lista em questão. Duas listas são iguais se elas possuem o mesmo tamanho e o valor
    // do k-ésimo elemento da primeira lista é igual ao k-ésimo elemento da segunda lista.
    bool equal(List *list);
    //     Recebe como parâmetro um valor inteiro n e divide a
    // lista em duas, de forma à segunda lista começar no primeiro nó logo após a primeira
    // ocorrência de n na lista original. A função deve retornar um ponteiro para a segunda
    // subdivisão da lista original, enquanto a cabeça da lista original deve continuar
    // apontando para o primeiro elemento da primeira lista, caso ele não tenha sido o
    // primeiro a ter valor n.
    List *separate(int key);
    //     Recebe uma List como parâmetro e constrói
    // uma nova lista com a intercalação dos nós da lista original com os nós da lista
    // passada por parâmetro. Ao final desta operação, list2 deve ficar vazia.
    List* mergeLists(List *list);

};

#endif