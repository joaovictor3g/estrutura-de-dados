#include <iostream>
#include <climits>
#include "Set.h"

struct Node {
    int value;
    Node *next;
};

// Lista circular simplesmente encadeada
Set::Set() {
    head = new Node;
    head->next = head;
}

// Adiciona elementos ao fim da lista
void Set::insert(int value) {
    Node *novo = new Node; // Inicio un ponteiro para nó
    novo->value = value; // Atribuo um valor ao campo value

    if(head->next == head) { // Se nao existe no valido
        head->next = novo; // O proximo da cabeça aponta para o novo nó
        novo->next = head; // O proximo do novo nó aponta para cabeça
    }else{
        Node *aux = head;
        while(aux->next != head) 
            aux = aux->next;
        aux->next = novo;
        novo->next = head;
    }
    
}

Set* Set::unionSet(Set *set1, Set *set2) {
    if((set1->head == (set1->head)->next))  return set2;

    else if((set2->head == (set2->head)->next)) return set1;

    Node *aux = (set2->head)->next;
    while(aux != set2->head) {
        set1->insert(aux->value);
        aux = aux->next;
    }

    return set1;   
}

Set *Set::intersectionSet(Set  *set1, Set *set2) {
    if(set1->isEmptySet())  return set2;
    if(set2->isEmptySet())  return set1;

    Set *newSet = new Set();

    Node *aux1 = (set1->head)->next; // Auxiliar 1 aponta para o primeiro nó válido do cojunto1.
    Node *aux2 = (set2->head)->next; // Auxiliar 2 aponta para o primeiro nó válido do conjunto2.
    if(set1->size() >= set2->size()) { 
        while(aux1 != set1->head) {
            if(set2->contains(aux1->value))
                newSet->insert(aux1->value);
            aux1 = aux1->next;
        }    
    }else{
        while(aux2 != set2->head) {
            if(set1->contains(aux2->value))
                newSet->insert(aux2->value);
            aux2 = aux2->next; 
        }
    }
    return newSet;
}

Set *Set::diference(Set *set1, Set *set2) {
    if(set1->isEmptySet())  return set2;
    if(set2->isEmptySet())  return set1;

    Set *newSet = new Set(); // Novo conjunto

    Node *aux1 = (set1->head)->next; 

    while(aux1 != set1->head) { 
        if(!set2->contains(aux1->value))
            newSet->insert(aux1->value);
        aux1 = aux1->next; 
    
    } 
   
    return newSet;
}

int Set::min(Set *set) {
    if(set->isEmptySet()) 
        return INT_MIN;

    Node *aux = (set->head)->next; // Inicio auxiliar apontando para primeiro no valido
    int minInitialValue = aux->value; // Crio uma variavel para guardar o primeiro valor do conjunto 
    
    while(aux != set->head) {
        if(minInitialValue >= aux->value)
            minInitialValue = aux->value;
        aux = aux->next;
    }

    return minInitialValue;
}

int Set::max(Set *set) {
    if(set->isEmptySet()) 
        return INT_MIN;

    Node *aux = (set->head)->next; // Inicio auxiliar apontando para primeiro no valido
    int maxInitialValue = aux->value; // Crio uma variavel para guardar o primeiro valor do conjunto 
    
    while(aux != set->head) {
        if(maxInitialValue <= aux->value)
            maxInitialValue = aux->value;
        aux = aux->next;
    }

    return maxInitialValue;
}

Node *Set::search(int value) {
    if(isEmptySet())
        return head;
    
    Node *aux = head->next;
    while(aux != head) {
        if(aux->value == value)
            return aux;
        aux = aux->next;
    }
    return head;
}

bool Set::contains(int value) {
    return (search(value) != head);
}

Set *Set::createEmptySet() {
    return new Set();
}

int Set::size() {
    if(this->isEmptySet())
        return 0;

    Node *aux = head->next;
    int counter = 0;
    
    while(aux != head) {
        counter++;
        aux = aux->next;
    }
    return counter;
}

bool Set::isEmptySet() {
    return (head == head->next);
}

void Set::remove(int value) {
    if(isEmptySet())
        return;
    Node *noRem = search(value);
    
    if(noRem == head)
        return;
    Node *aux = head;

    while(aux->next != noRem) 
        aux = aux->next;
    aux->next = noRem->next;
    delete noRem;
}

int Set::member(int value) {
    return (contains(value)) ? 1 : 0;
}

bool Set::isEqual(Set *a, Set *b) {
    if((a->isEmptySet() || b->isEmptySet()) || (a->size() != b->size()))
        return false;
    
    Node *aux1 = (a->head)->next;
    Node *aux2 = (b->head)->next;
    int counter = 0;

    while(aux1 != a->head) {
        if(aux1->value == aux2->value)
            counter++;
        aux1 = aux1->next;
        aux2 = aux2->next;
    }

    return (counter == size());
}

void Set::clear() {
    if(isEmptySet())
        return;
    Node *aux = head->next;
    while(aux != head) {
        Node *noRem = aux;
        std::cout << "Removendo: " << aux->value << std::endl;
        remove(noRem->value);
        aux = aux->next;
    }
}

void Set::print() {
    Node *aux = head->next;
    std::cout << "{ ";
    while(aux != head) {
        std::cout << aux->value;
        if(aux->next != head) 
            std::cout << ", ";  
        aux = aux->next;
    }
    std::cout << " }" << std::endl;
}

// Destrutor
Set::~Set() {
    clear();
}
