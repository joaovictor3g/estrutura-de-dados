#include <iostream>
#include <climits>
#include "SeqList.h"

using std::cout;
using std::cin;
using std::endl;

SeqList::SeqList(int n) {
    size_vec = 0;
    capacity_vec = n;

    vec = new (std::nothrow) int[capacity_vec];
    if(vec == nullptr) {
        cout << "Memória insuficiente" << endl;
        exit(1);
    }  
}

bool SeqList::isFull() {
    return size_vec==capacity_vec;
}

bool SeqList::add(int x) {
    if(!isFull()) {
        vec[size_vec] = x;
        size_vec++;
        return true;
    }
    return false;
}

int SeqList::search(int x) {
    for(int i = 0; i < size(); i++) {
        if(vec[i]==x)
            return i;
    }
    return -1;
}
//1, 2

void SeqList::remove(int x) {
    int index = search(x);
    if(index > -1) {
        while(index != size_vec-1) {
            vec[index++] = vec[index+1];
        }   
        size_vec--;
    }
}

int SeqList::at(int k) {
    if(k < 0) 
        return INT_MIN;
    return vec[k];
}

int SeqList::size() {
    return size_vec;
}

void SeqList::print() {
    for(int i = 0; i < size(); i++) 
        cout << vec[i] << " ";
    cout << endl;
}

void SeqList::clear() {
    size_vec = 0;
}

bool SeqList::replaceAt(int x, int k) {
    if(k < 0 || k > size_vec - 1)
        return false;
    vec[k] = x;
    return true;
}

void SeqList::removeAt(int k) {
    if(k < 0 || k > size_vec - 1)
        cout << "Remoção mal sucedida" << endl;
    while(k != size_vec-1) 
        vec[k++] = vec[k+1];  
    size_vec--;
}

// 1, 2, 3, 4 eu quero colocar 5 na posicao 1 = [1, 5, 2, 3, 4]
bool SeqList::insertAt(int x, int k) {
    if((k < 0 || k > size_vec) && size_vec > capacity_vec)
        return false;
    
    size_vec++;
    while(k < size_vec) {
        int aux = vec[k];
        vec[k] = x;
        x = aux;
        k++;
         
    }
    return true;
  
}

// 8, 8, 9, -1, -1, -1, 9
// 8, 8, 9, -1, -1, 9
// 8, 8, 9, -1, 9
void SeqList::removeAll(int elem) {
    for(int i = 0; i < size(); i++) {
        for(int j = 0; j < size(); j++) {
            if(elem == vec[j])
                remove(elem);
        }
    }      
}

SeqList::~SeqList() {
    if(vec != nullptr) {
        cout << "Memória desalocada" << endl;
        delete[] vec;
    }
}