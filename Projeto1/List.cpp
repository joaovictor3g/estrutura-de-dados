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
    if(head == head->next) // Lista vazia
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
    if(head == head->next) {
        std::cout << "Sem nós válidos para remoção" << std::endl;
    }else{
        /*
            Esse if serve no caso de o p apontar para
            o último nó.
        */
        if(head->ant == p) { // Comparo se o último nó aponta para onde p aponta
            Node *noRem = p; // Faço noRem receber este ponteiro
            head->ant = noRem->ant; // Faço o anterior da cabeça apontar para o anterior de quem p aponta;
            (noRem->ant)->next = head; // Faço o proximo do penúltimo apontar para head;
            delete noRem; // delete o nó a qual p aponta
            return;
        }
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

void List::print() {
    if(head == head->next)
        return;
    Node *aux = head->next;
    while(aux != head) {
        std::cout << aux->key << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

List::~List() {

}