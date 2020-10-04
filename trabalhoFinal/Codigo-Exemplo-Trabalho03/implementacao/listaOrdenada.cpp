#include <iostream>
#include "listaOrdenada.h"

struct Node {
    int key;
    Node *prev;
    Node *next;
};

List::List() {
    head = new Node;
    head->prev = nullptr;
    head->next = nullptr;
}

void List::pushBack(int key) {
    Node *novo = new Node;
    novo->key = key;

    if(head->next == nullptr) {
        head->next = novo;
        novo->prev = head;
    }else{
        Node *aux = head->next;

        while(aux->next != nullptr)
            aux = aux->next;
        aux->next = novo;
        novo->prev = aux;
    }   
    novo->next = nullptr;
}

void List::linkedIteractiveBubbleSort() {
    bool ordenado = false;

    while(!ordenado) {
        ordenado = true;
        for(Node *aux = head->next; aux->next != nullptr; aux = aux->next) {
            if(aux->key > (aux->next)->key) {
                ordenado = false;
                

            }
        }
    }
}


void List::print() {
    Node *aux = head->next;

    std::cout << "[";
    while(aux != nullptr) { 
        std::cout << aux->key << ", ";
        aux = aux->next;
    }
    std::cout << "]" << std::endl;
}