#include <iostream>
#include "vetorOrdenado.h"

void iteractive_bubble_sort(int v[], int size) {
    bool ordenado = false; // flag que para a execução do while
    
    while(!ordenado) {
        ordenado = true; // Já recebe verdade
        for(int i = 0; i < size - 1; i++){
            if(v[i] > v[i+1]){ // Verifica uma posição com a sua subsequente
                ordenado = false; // Ainda há possíveis permutações
                std::swap(v[i], v[i+1]); // troca os valores contidos nas posições
                
            }
        }
    }
}

void recursive_bubble_sort(int* v, int size, int index) {
    if(size == 0 || size == 1) 
        return;

    if(v[size-1] < v[size-2]) // Comparando do ultimo com o seu anterior
        std::swap(v[size-1], v[size-2]); // Façõ a troca de valores

    if(!ascending_order(v, index) && size == 2) // Chamada da função q verifica se está ordenado em ordem crescente 
        recursive_bubble_sort(v, index, index); // chamo a recursão passando o tamanho original do vetor para size
            
    recursive_bubble_sort(v, size-1, index); // chamo a recursão
}

void iteractive_insertion_sort(int vet[], int size) {
    // 3, 5, 1, 0
    int i = 0, j = 0, key = 0, index = 0;
    
    for(i = 1; i < size; i++) {
        key = vet[i]; // Chave que guarda o valor que está sendo comparado
        index = i; // Guardando indice da chave inicial
        for(j = i - 1; j >= 0; j--) {  // For que começa de i e decrementa-o
            if(key < vet[j]) { // Comparo a chave com os valores a esquerda de key
                vet[j+1] = vet[j]; // Movo o valor de key para direita  
                index = j; // guardando os indices a esquerda se houver
            }
        }
        vet[index] = key; // ajusto a posição de key
    }
}

// Verifica se o vetor está totalmente ordenado em ordem crescente
bool ascending_order(int vet[], int size) {
    int counter = 0;
    for(int i = 0; i < size - 1; i++) {
        if(vet[i] <= vet[i+1])
            counter++;
    }

    return (counter+1 == size);
}