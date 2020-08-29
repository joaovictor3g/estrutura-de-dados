#include <iostream>
#include <climits>
#include "List2.h"
using namespace std;

struct Node {
    int value;
    Node *next;
};

// Construtor
List::List() {
    head = new Node;
    head->next = nullptr;
}

// Adiciona o inteiro x ao final da lista
void List::add(int x) {
    Node *novo = new Node;
    novo->value = x;
    novo->next = nullptr;
        Node *aux = head; 
    while(aux->next != nullptr) 
        aux = aux->next;
    aux->next = novo;
}

void List::clear() {
    head->next = clearRecursive(head);
}

Node *List::clearRecursive(Node *node) {
    if(node == nullptr) // Caso base: lista vazia
        return nullptr;
    else { // Caso geral
        node->next = clearRecursive(node->next); // 1: remover todo mundo que vem depois
        delete node; // 2: remove o no atual
        return nullptr; // 3: retorna nulo para o no que vem antes de voce
    }
}

List::~List() {
    clear();
    delete head;
}


void List::print() {
    printRecursive(head->next);
    cout << endl;
}

void List::printRecursive(Node *node) {
    if(node == nullptr) // Caso base: não tenho nó pra imprimir
        return;
    else {
        std::cout << node->value << " ";
        printRecursive(node->next);
    }
}

void List::printReverso() {
    printRecursiveReverso(head->next);
    cout << endl;
}

void List::printRecursiveReverso(Node *node) {
    if(node == nullptr) // Caso base: não tenho nó pra imprimir
        return;
    else {
        printRecursiveReverso(node->next);
        std::cout << node->value << " ";    
    }
}

bool List::isEmpty() {
    return (head->next == nullptr);
}

int List::size() {
    int soma = 0;
    Node *aux = head->next;
    while(aux != nullptr) {
        soma++;
        aux = aux->next;
    }
    return soma;
}

// Operacao auxiliar: retorna o antecessor do no 
// com valor x, ou nullptr caso x nao esteja presente 
Node *List::search(int x) {
    if(head->next == nullptr) return nullptr; // lista vazia
    Node *aux = head;
    while((aux->next != nullptr) && (aux->next)->value != x) {
        aux = aux->next;
    }
    return ((aux->next == nullptr) ? nullptr : aux);
}

void List::remove(int x) {
    Node *ant = search(x);
    if(ant != nullptr) {
        Node *noRem = ant->next;
        ant->next = noRem->next;
        delete noRem;
    }
}

void List::removeAll(int x) {
    Node *aux = head->next;
    while(search(x) != nullptr) {
        remove(x);
        aux = aux->next;
    }
}

int List::removeNodeAt(int index) {
    if(index > size() || index < 1)
        return INT_MIN;
    
    int TAM = size();
    Node **aux =  new (nothrow) Node*[TAM];
    for(int i = 0; i < TAM; i++)
        aux[i] = new (nothrow) Node;
    
    int position = 0;
    
    for(Node *no2 = head->next; no2 != nullptr; no2 = no2->next) {
        aux[position] = no2;
        position++;
    }

    int value = aux[index-1]->value;
    remove(value);
    return value;
}

void List::insertAfter(int value, int index) {
    if(index > size() || index < 1)
        return;
    
    Node *new_node = new Node{ value, nullptr };

    int TAM = size()+1;
    Node **aux =  new (nothrow) Node*[TAM];
    for(int i = 0; i < TAM; i++)
        aux[i] = new (nothrow) Node;
    
    int position = 0;
    
    for(Node *no2 = head->next; (no2 != nullptr); no2 = no2->next) {
        aux[position] = no2;
        position++;
    }
    Node *ant = aux[index];
    aux[index-1]->next = new_node;
    new_node->next = ant;
    
    if(index+1 == TAM)
        ant->next = nullptr;
}

List* List::copy() {
    if(isEmpty()) {
        cout << "Lista vazia" << endl;
        return this;
    }
    Node *aux = head->next;
    List* list = new List();

    while(aux != nullptr) {
        list->add(aux->value);
        aux = aux->next;
    } 
    return list;
}

void List::copyArray(int v[], int size) {
    clear();
    for(int i = 0; i < size; i++)   add(v[i]);
    
}

bool List::equal(List *list) {
    if((size() != list->size()) || isEmpty() || list->isEmpty())
        return false;

    Node *aux = head->next;
    Node *newNode = (list->head)->next;
    int counter = 0;

    while(aux != nullptr && newNode != nullptr) {
        if(aux->value == newNode->value)
            counter++;
        aux = aux->next;
        newNode = newNode->next;
    }

    return (counter == size());
}

void List::concatenate(List *list) {
    if(isEmpty())
        return;
    Node *aux = head;

    while(aux->next != nullptr) 
        aux = aux->next;
    
    aux->next = (list->head)->next;
    list = new List();
}

Node* List::ultimo() {
    if(this->isEmpty()) 
        return nullptr;

    Node *aux = head->next;
    Node *ultimoNo = nullptr;

    while(aux != nullptr) {
        if(aux->next == nullptr)
            ultimoNo = aux;
        aux = aux->next;
    }
    return ultimoNo;
}

Node* List::auxReverse(Node *node) {
    if(node->next == nullptr)
        return node;
    Node *ant = node;

    node = auxReverse(node->next);
    
    Node *no = this->ultimo();
    no->next = ant;
    ant->next = nullptr;
    return node;
}

void List::reverse() {
    if(isEmpty())   cout << "Lista Vazia" << endl;
    else head->next = auxReverse(head->next);
}







