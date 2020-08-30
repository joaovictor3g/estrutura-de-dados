#include <iostream>
#include "List.h"

struct Node {
    int value;
    Node *next;
};

List::List() {
    head = new Node;
    head->next = head;
}

void List::addBack(int value) {
    Node *no = new Node;
    no->value = value;
    Node *aux = head;

    while(aux->next != head) 
        aux = aux->next;
    aux->next = no;
    no->next = head;
}

void List::addFront(int value) {
    Node *no = new Node;
    no->value = value;

    Node *aux = head;
    no->next = aux->next;
    head->next = no;
    
}

void List::print() {
    Node *aux = head->next;

    std::cout << "[";
    while(aux != head) { 
        std::cout << aux->value << ", ";
        aux = aux->next;
    }
    std::cout << "]\n";
}

void List::clear() {
    Node *aux = head;
    
    while(aux->next != head) {
        Node *noRem = aux;
        std::cout << "Removendo: " << noRem->value << "!!\n" ;
        delete noRem;
        aux = aux->next;
    }
    head->next = head;
}

bool List::isEmpty() {
    return head->next == head;
}

Node* List::search(int value) {
    if(isEmpty())  
        return nullptr;
    Node *aux = head->next;

    while(aux != head) {
        if(aux->value == value)
            return aux;
        aux = aux->next;
    }
    return nullptr;
}

void List::remove(int value) {
    Node *noRem = search(value);
    if(noRem == nullptr) {
        std::cout << "Não foi possível remover" << std::endl;
    }else{
        Node *aux = head;
        while(aux->next != noRem)
            aux = aux->next;
        aux->next = noRem->next;
        std::cout << "Removendo: " << noRem->value << "\n";
        delete noRem;
    }
}

bool List::contains(int value) {
    return (search(value) != nullptr);
}

void List::removeAll(int value) {
    while(contains(value))  remove(value);
}

List::~List() {
    clear();
}