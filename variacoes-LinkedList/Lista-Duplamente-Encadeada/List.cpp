#include <iostream>
#include "List.h"

struct Node {
    int value;
    Node *ant;
    Node *next;
};

List::List() {
    begin = nullptr;
    end = nullptr;
}

void List::addBack(int value) {
    Node *newNode = new Node;
    newNode->value = value;

    if(begin == nullptr) {
        begin = newNode;
        end = newNode;
        newNode->ant = nullptr;
        newNode->next = nullptr;
    }else{
        Node *aux = begin;
        while(aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = newNode;
        newNode->ant = aux;
        newNode->next = nullptr;
        end = newNode;
    }
}

void List::addFront(int value) { // O(1)
    Node *no = new Node;
    no->value = value;

    if(begin == nullptr) {
        begin = no;
        end = no;
        no->ant = nullptr;
        no->next = nullptr;
    }else{
        Node *aux = begin;
        begin = no;
        no->next = aux;
        aux->ant = no;
        no->ant = nullptr;
    }
}

void List::print() {
    Node *aux = begin;

    std::cout << "[";
    while(aux != nullptr) {
        std::cout << aux->value << ", ";
        aux = aux->next;
    }
    std::cout << "]" << std::endl; 
}
 
Node* List::search(int value) {
    if(begin == nullptr)
        return nullptr;

    Node *aux = begin;
    while(aux != nullptr) {
        if(aux->value == value) 
            return aux;
        aux = aux->next;
    }
    return nullptr;
}

void List::remove(int value) {
    Node *noRem = search(value);
    if(noRem == nullptr) {
        std::cout << "Não foi possível remover\n";  
    }else if(noRem->ant == nullptr){
        Node *aux = noRem;
        if(noRem->next == nullptr) {
            delete noRem;
            begin = nullptr;
            end = nullptr;
            return;
        }
        begin = noRem->next;
        (aux->next)->ant = nullptr;
        delete noRem;

    }else if(noRem->next == nullptr) {
        Node *aux = noRem->ant;
        end = noRem->ant;
        aux->next = nullptr;
        delete noRem;

    }else{
        Node *aux = noRem->ant;
        aux->next = noRem->next;
        (noRem->next)->ant = aux;
        delete noRem;
    }
}

void List::removeAll(int value) {
    while(search(value) != nullptr) remove(value);
}

void List::printReverse() {
    Node *aux = end;

    std::cout << "[";
    while(aux != nullptr) {
        std::cout << aux->value << ", ";
        aux = aux->ant;
    }
    std::cout << "]" << std::endl;
}

void List::clear() {
    if(begin == nullptr)
        return;
    Node *aux = begin;
    while(aux != nullptr) {
        Node *noRem = aux;
        std::cout << "Removendo: " << noRem->value << "\n";
        delete noRem;
        aux = aux->next;
    }
    begin = nullptr;
    end = nullptr;
}

List::~List() {
    clear();
}