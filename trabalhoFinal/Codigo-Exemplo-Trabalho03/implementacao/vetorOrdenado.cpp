#include <iostream>
#include "vetorOrdenado.h"

int ind = 5;

void iteractive_bubble_sort(int v[], int size) {
    bool ordenado = false;
    
    while(!ordenado) {
        ordenado = true;
        for(int i = 0; i < size - 1; i++){
            if(v[i] > v[i+1]){
                ordenado = false;
                std::swap(v[i], v[i+1]);
                
            }
        }
    }
}

void recursive_bubble_sort(int* v, int size, int index) {
    if(size == 0 || size == 1) 
        return;

    if(v[size-1] < v[size-2]) {
        // std::cout << "Trocando: " << v[size-1] << " por: " << v[size-2] << std::endl;
        std::swap(v[size-1], v[size-2]);

        // std::cout << size << std::endl;
        
        // if(size == 2) {
        //     std::cout << "entrou aqui" << std::endl;
        //     size = index;
        //     recursive_bubble_sort(v, size, index);
        
        // }
    }

    if(!ascending_order(v, index) && size == 2)
        recursive_bubble_sort(v, index, index);
            
    recursive_bubble_sort(v, size-1, index);
}

bool ascending_order(int vet[], int size) {
    int counter = 0;
    for(int i = 0; i < size - 1; i++) {
        if(vet[i] <= vet[i+1])
            counter++;
    }

    return (counter+1 == size);
}