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

void List::printReverse() {
    Node *aux = end;

    std::cout << "[";
    while(aux != nullptr) {
        std::cout << aux->value << ", ";
        aux = aux->ant;
    }
    std::cout << "]" << std::endl;
}