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

void List::insertAfter(int key, int index) {
    if(index < 0) {
        std::cout << "Indice inválido" << std::endl;
        return;
    }
    Node *no = new Node; // Crio um novo ponteiro para nó
    no->key = key; // Atribuo a key passada por parametro ao meu novo nó

    Node *aux = head->next; // Faço nó apontar para cabeça
    int counter = 0; // Contador
    while(aux != head && counter < index) { // Percorro meus nós até counter ser igual a index
        aux = aux->next; // Incremento auxiliar
        counter++; // Incremento contador
    }
    /*
        Este while vai me dar um aux apontando para um nó na posição do index;
    */
    Node *aux2 = aux->next; // Crio um pontairo para nó que aponta para onde o proximo do auxiliar aponta
    aux->next = no; // Faço proximo do auxiliar apontar para o novo nó
    no->ant = aux; // Faço o anterior do novo nó apontar para auxiliar
    no->next = aux2; // Faço o proximo do novo nó apontar para Auxiliar 2 que tem o endereco do nó que eu guardei
    aux2->ant = no; // Faço o anterior deste apontar para meu novo nó
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
                delete noRem; // deleto o ponteiro
                break;
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
                removeNode(aux);
                break;
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

int List::removeNodeAt(int index) {
    if(index < 0 || index > this->size()) // Se o index não estiver neste intervalo retorno o menor inteiro
        return INT_MIN;
    
    int counter = 0; // Crio um contador
    Node *aux = head->next; // Auxiliar aponta para o primeiro nó válido
    while(aux != head && counter < index) { 
        aux = aux->next;
        counter++;
    }
    int key = aux->key; // key variavel que recebe o valor do meu nó antes de removê-lo
    removeNode(aux); // removo nó para o qual o auxiliar está apontando
    return key; // retorno a chave
    
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

void List::concat(List* list) {
    if(list->isEmpty()) // Verifico se a lista passada como parametro é vazia
        return;
    Node *aux = (list->head)->next; // Auxiliar recebe o primeiro nó válido da lista passado por parametro
    while(aux != list->head) { 
        pushBack(aux->key); // Adicionando os nós existentes na lista passada por parametro para a lista que referenciou esta função;
        aux = aux->next;
    }
    list->clear(); // Liberando a lista passada por parâmetro
}

List *List::copy() {
    List *list = new List();
    if(isEmpty()) {
        std::cout << "Lista a ser copiada está vazia" << std::endl;
    }else{
        Node *aux = head->next;
        while(aux != head) {
            list->pushBack(aux->key);
            aux = aux->next;
        }
    }
    return list; // Retorno a nova lista criada, já preenchido ou não
}

void List::copyArray(int arr[], int size) {
    for(int i = 0; i < size; i++)   pushBack(arr[i]);
}

bool List::equal(List *list) {
    if(list->size() != this->size() || list->isEmpty() || this->isEmpty()) // Se as listas tiverem tamanhos diferentes ja é falso
        return false;

    Node *aux = head->next; // Auxiliar 1 recebe o primeiro nó válido
    Node *aux2 = (list->head)->next; // Auxiliar 2 recebe o primeiro nó válido da lista passada por parametro
    int counter = 0; // Contador 

    while(aux != head) {
        if(aux->key == aux2->key)  // Comparo as chaves das duas listas
            counter++; // Conto se são iguais
        aux = aux->next; 
        aux2 = aux2->next;
    }
    return (counter == this->size()); // se o contador é igual ao tamanho da lista, true se não false
}

void List::mergeLists(List *list) {
    if(list->isEmpty() || this->isEmpty()) {
        std::cout << "Impossível intercalar: uma ou mais listas são vazias" << std::endl;
    }else{
        Node *aux = (head); // Aux recebe o primeiro nó valido da lista passada por parametro
        Node *aux2 = (list->head);

        while(aux->next != head) {
            Node *aux3 = aux;
            Node *aux4 = aux2->next;
            aux3->next = aux4;
            aux4->ant = aux3;
            Node *aux5 = aux->next;
            aux4->next = aux5;
            aux5->ant = aux4;
            aux5->next = head;
            (head)->ant = aux5;
            
            // std::cout << "aux3 " << aux3->key << " aux4: " << aux4->key << " aux5: " << aux5->key << std::endl;
            aux = aux->next;
            aux2 = aux2->next;
        } 
        
    }
}

List *List::separate(int key) {
    List *list = new List();
    Node *nodeToSeparate = searchNode(key);
    
    if(this->isEmpty() || ((nodeToSeparate->next == head) && this->size() == 1))  // Verificação de apenas um nó válido ou vazio
        return list;
    
    else if(nodeToSeparate->next == head) { // Verificação se o proximo do nó buscado é o último nó
        Node *no = nodeToSeparate->next; 
        while(no != nodeToSeparate) {
            if(no == head) // 
                no = no->next;
            list->pushBack(no->key);
            no = no->next;
        }
    
    }else{
        Node *no = nodeToSeparate->next;
        while(no != head) {
            list->pushBack(no->key);
            no = no->next;
        }
    }
    return list;
}

void List::clear() {
    if(isEmpty()) {
        std::cout << "Sem nós para remover" << std::endl;
    }else{
        Node *aux = head->ant; // Crio um ponteiro para um nó que aponta para o último nó
        while(aux != head) {
            std::cout << "Removendo: " << popBack() << std::endl; // Chamo a função que remove o último nó
            aux = aux->ant; // Enquanto houver nó válido
        }
        head->next = head; // Faço o proximo da cabeça apontar para ele mesmo
        head->ant = head; // Faço o anterior da cabeça apontar para ele mesmo
    }
}

List::~List() {
    clear();
}