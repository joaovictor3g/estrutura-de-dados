#include <iostream>
#include "List.h"

struct Node {
    int value;
    Node *next;
};

List::List() {
    this->head = nullptr;
}   

void List::addBack(int value) {
    Node *no = new Node;
    no->value = value;

    if(head == nullptr) {
        no->next = no;
        head = no;
    }else{
        Node *aux = head;
        while(aux->next != head) 
            aux = aux->next;
        no->next = head;
        aux->next = no;
    }
}

void List::addFront(int value) {
    Node *novo = new Node;
    novo->value = value;

    if(head == nullptr) 
        novo->next = novo;
    else {
        Node *aux = head;
        while(aux->next != head)        
            aux = aux->next;
        novo->next = head;
        aux->next = novo;  
    }
    head = novo;
}

void List::print() {
    if(head == nullptr) {
        std::cout << "Lista vazia!\n";
        return;
    }
    Node *aux = head;
    
    std::cout << "[";
    do {    
        std::cout << aux->value << ", ";
        aux = aux->next; 
    
    } while(aux != head);
    std::cout << "]\n";
    
}

void List::clear() {
    if(head != nullptr) {
        Node *aux = head->next;
        
        while(aux != head) {
            Node *eraseNode = aux;  
            aux = aux->next;
            std::cout << "Removendo " << eraseNode->value << std::endl;
            delete eraseNode;
        }

        std::cout << "Removendo " << head->value << std::endl;
        delete head;
        head = nullptr;
    }
}

Node* List::search(int value) {
    if(head == nullptr) 
        return nullptr;
    
    Node *aux = head;
    do {
        if(aux->value == value) 
            return aux;
        aux = aux->next;
    } while(aux != head);
    return nullptr;
}

Node *List::prevNode(int value) {
    if(head == nullptr) 
        return nullptr;
    
    Node *aux = head->next;
    do {
        if(aux->value == value) 
            return aux;
        aux = aux->next;
    } while(aux != head);
    return nullptr;
}

void List::remove(int value) {
    Node *noRem = search(value);
    if(noRem == nullptr) 
        return;

    if(noRem == noRem->next) {
        delete noRem;
        head = nullptr;
        return;
    }
    Node *aux = noRem;

    while(aux->next != noRem) {
        aux = aux->next;
    }
    aux->next = noRem->next;
    if(head == noRem)
        head = noRem->next;
    delete noRem;
}

bool List::contains(int value) {
    return search(value) != nullptr;
}

void List::removeAll(int value) {
    while(contains(value))     remove(value);
    
}

bool List::isEmpty() {
    return head == nullptr;
}

int List::size() {
    // if(isEmpty())
    //     return 0;
    
    // Node *aux = head;
    // int counter = 0;

    // do {
    //     counter++;
    //     aux = aux->next;
    // } while(aux != head);

    // return counter;
    return recursiveSize(head);
}

int List::recursiveSize(Node *no) {
    if(isEmpty())
        return 0;
    if(no->next == head)
        return 1;
    return recursiveSize(no->next) + 1; 
}

List::~List() {
    clear();
}

