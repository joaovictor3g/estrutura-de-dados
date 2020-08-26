#ifndef LIST_H
#define LIST_H

struct Node;

class List {
   private:
      Node *head; // Ponteiro para a cabeca da lista
      // Operacao auxiliar search: retorna o antecessor do no 
      // com valor x, ou NULL caso x nao esteja presente 
      Node *search(int x); 
      Node *clearRecursive(Node *node);
      void printRecursive(Node *node);
      void printRecursiveReverso(Node *node);
   public:
      List(); // Construtor
      ~List(); // Destrutor: libera memoria alocada
      void add(int x); // Insere x ao final da lista
      void remove(int x); // remove o primeiro no com valor x
      void removeAll(int x); // remove todo no com valor x
      int removeNodeAt(int k); // remove k-esimo no
      void print(); // Imprime elementos
      void printReverso(); // Imprime de tras para frente
      bool isEmpty(); // Esta vazia?
      int size(); // retorna numero de nos
      void clear(); // deixa a lista vazia
      void insertAfter( int x, int k ); //Insere um novo nó com valor x após o k-ésimo nó da lista. Deve-se ter 0 ≤ k ≤ size() para que a inserção seja realizada; caso contrário, não sera realizada.
      List *copy(); // Retorna um ponteiro para uma cópia desta lista.
};

#endif
