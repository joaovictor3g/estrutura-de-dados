#include <iostream>
#include <climits>
#include "List.h"

struct Node {
    int key; // Chave do nó
    Node *next; // ponteiro para o próximo nó
    Node *ant; // ponteiro para o nó anterior

};

List::List() {
    head = new Node; // Inicio a cabeça da lista;
    head->ant = head; // Anterior da cabeça aponta para head;
    head->next = head; // Proóximo da cabeça aponta pra head
}

void List::pushBack(int key) {
    Node *newNode = new Node; // Crio um ponteiro para um nó
    newNode->key = key; // Atribuo ao campo key do Nó

    Node *aux = head->ant; // Faço o auxiliar apontar para o último nó
    aux->next = newNode; // Proximo do ultimo nó aponta para o novo nó
    newNode->ant = aux; // Anterior do novo nó aponta para o antigo último nó
    newNode->next = head; // Proximo do novo nó aponta para cabeça
    head->ant = newNode; // Anterior da cabeça aponta para novo nó
    
}

int List::popBack() {
    if(isEmpty()) // Lista vazia
        return INT_MIN; // retorno o menor inteiro

    Node *aux = head->ant; // auxiliar: recebe endereço do último nó
    int lastKey = aux->key;
    Node *antAux = aux->ant; // anterior do auxiliar: recebe o endereço penúltimo nó
    antAux->next = head; // faço o próximo dele apontar pra cabeça
    head->ant = antAux; // faço o anterior da cabeça apontar para o penultimo no
    delete aux; // deleto o último nó

    return lastKey;
}

void List::auxRemoveNode() {
    removeNode((head->next)->next);
}

void List::removeNode(Node *p) {
    if(isEmpty()) {
        std::cout << "Sem nós válidos para remoção" << std::endl;
    }else{
        Node *aux = head->next; // Auxliar recebe o primeiro nó válido
        while(aux != head) { 
            if(p == aux) { // Comparo se p aponta para onde este auxiliar aponta
                Node *noRem = p; // Crio um ponteiro q aponta para onde p aponta
                Node *newNode = noRem->next; // Crio um novo nó que aponta para o próximo nó que p aponta
                newNode->ant = noRem->ant; // Faço o anterior deste, apontar para onde o anterior de p aponta
                (noRem->ant)->next = newNode; // Faço o próximo deste anterior apontar para o proximo de p
                delete noRem; // delete o ponteiro
            }
            aux = aux->next;
        }
    }
}

void List::remove(int key) {
    if(isEmpty()) {
        std::cout << "Impossível remover" << std::endl;
    }else{
        Node *aux = head->next; // Auxiliar recebe endereço do último nó
        while(aux != head) { 
            if(aux->key == key) { 
                Node *noRem = aux; // Crio um ponteiro para armazenar o endereço do nó que quero remover
                (noRem->ant)->next = noRem->next; // Proximo do no anterior aponta para o proximo do no que quero remover 
                (noRem->next)->ant = noRem->ant; // O anterior do proximo aponta para o anterior do no que quero remover
                delete noRem; // Finalmente removo o nó
            }
            aux = aux->next;
        }
    }
}

Node *List::searchNode(int key) {
    if(isEmpty()) 
        return head;
    Node *aux = head->next;
    while(aux != head) {
        if(aux->key == key)
            return aux;
        aux = aux->next;
    }
    return head;
}

void List::removeAll(int key) {
    while(searchNode(key) != head)  remove(key);
}

void List::print() {
    if(isEmpty())
        return;
    Node *aux = head->next;
    while(aux != head) {
        std::cout << aux->key << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

void List::printReverse() {
    if(isEmpty()) {
        std::cout << "Sem nós para imprimir" << std::endl;
    }else{
        Node *print = head->ant;
        while(print != head) {
            std::cout << print->key << " ";
            print = print->ant;
        }
        std::cout << std::endl;
    }
}

bool List::isEmpty() {
    return (head == head->next) ; // Se a a cabeça aponta pra ela mesma, lista vazia
}

int List::size() {
   return auxRecursiveSize(head->ant);
}

int List::auxRecursiveSize(Node *no) {
    if(no == head) // caso base: nó igual a cabeça
        return 0;  // Como a cabeça não é nó valido retorna 0
    return auxRecursiveSize(no->ant)+1; // Retorna a função recursivamente passando o nó anterior
}

List::~List() {
    if(isEmpty()) {
        std::cout << "Sem nós para remover" << std::endl;
    }else{
        Node *aux = head->ant;
        while(aux != head) {
            std::cout << "Removendo: " << popBack() << std::endl;
            aux = aux->ant;
        }
        head->next = head;
        head->ant = head;
    }
}