#include <iostream>
#include "List.h"

using namespace std;

List::List(int capacity) {
    this->capacity_vec = capacity;
    this->size = 0;

    vec = new (nothrow) int[capacity_vec];
    if(vec==nullptr) {
        cout << "Memória não alocada" << endl;
        exit(1);
    }
}

bool List::add(int element) {
    if(size < 0 || size > capacity_vec)
        return false;
    vec[size] = element;
    size++;
}

bool List::isFull() {
    return size==capacity_vec;
}


int List::getMinValue() {
    if( !isFull()) {
        int menor = vec[0];
        for(int i = 1; i < size; i++) {
            if(menor >= vec[i]) menor = vec[i];
        }
        return menor;
    }
}

int List::getMaxValueIndex() {
    if( !isFull()) {
        int maior = vec[0];
        int indice = 0;

        for(int i = 1; i < size; i++) {
            if(maior <= vec[i]) indice = i;
        }
        return indice;
    }
}

void List::removeMaxValue() {
    int index = getMaxValueIndex();

    while(index < capacity_vec) 
        vec[index++]=vec[index+1];
    size--;
    
}

int List::search(int element) {
    for(int i = 0; i < size; i++) {
        if(element == vec[i])   return i;
    } 
    return -1;
}

void List::remove(int element) {
    int index = search(element);

    if(index < 0) {
        cout << element << " inexistente" << endl;
        return;
    }
    while(index < size) 
        vec[index++] = vec[index+1];
    size--;
}

void List::removeAt(int element) {
    if(size <= 0) {
        cout << "Não foi possível remover" << endl;
        return;
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(vec[j]==element)
                remove(element);
        }
    }
}

int List::countElement(int element) {
    int cont = 0;
    for(int i = 0; i < size; i++) {
        if(element==vec[i])     cont++;
    }
    return cont;
    
}

void List::print() {
    for(int i = 0; i < size; i++)
        cout << vec[i] << " ";
    cout << endl;
}

List::~List() {
    if(vec != nullptr) 
        delete[] vec;
}