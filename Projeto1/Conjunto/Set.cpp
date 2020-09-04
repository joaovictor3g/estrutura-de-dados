#include <iostream>
#include "Set.h"

struct Node {
    int value;
    Node *next;
};

Set::Set() {
    head = new Node;
    head->next = head;
}

void Set::add(int value) {
    Node *novo = new Node;
    novo->value = value;

    if(head->next == head) {
        head->next = novo;
        // novo->next = head;
    }else{
        Node *aux = head->next;
        if(aux->next == head) {
            aux->next = novo;
            novo->next = head;
            return;
        }
        while(aux != head) 
            aux = aux->next;
        aux->next = novo;
    }
    novo->next = head;
}

void Set::print() {
    Node *aux = head->next;
    while(aux != head) {
        std::cout << aux->value << ", ";
        aux = aux->next;
    }
    std::cout << std::endl;
}