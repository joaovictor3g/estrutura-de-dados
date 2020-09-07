#include <iostream>
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
void Set::add(int value) {
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
        set1->add(aux->value);
        aux = aux->next;
    }

    return set1;   
}

Set *Set::intersectionSet(Set  *set1, Set *set2) {
    if(set1->isEmptySet())  return set2;
    if(set2->isEmptySet())  return set1;

    Set *newSet = new Set();

    Node *aux1 = (set1->head)->next;
    Node *aux2 = (set2->head)->next;

    if(set1->size() >= set2->size()) {
        while(aux1 != set1->head) {
            if(set2->contains(aux1->value))
                newSet->add(aux1->value);
            aux1 = aux1->next;
        }    
    }else{
        while(aux2 != set2->head) {
            if(set1->contains(aux2->value))
                newSet->add(aux2->value);
            aux2 = aux2->next; 
        }
    }
    return newSet;
}

Set *Set::diference(Set *set1, Set *set2) {
    if(set1->isEmptySet())  return set2;
    if(set2->isEmptySet())  return set1;

    Set *newSet = new Set();

    Node *aux1 = (set1->head)->next;
    Node *aux2 = (set2->head)->next;

    if(set1->size() >= set2->size()) {
        while(aux1 != set1->head) {
            if(!set2->contains(aux1->value))
                newSet->add(aux1->value);
            aux1 = aux1->next;
        }    
    }else{
        while(aux2 != set2->head) {
            if(!set2->contains(aux1->value)) {
                newSet->add(aux2->value);
               
            }
            aux1 = aux1->next;
            if(aux1 == head) 
                break;
            aux2 = aux2->next; 
        }
    }
    return newSet;
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
