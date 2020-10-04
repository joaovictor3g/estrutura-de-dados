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

// a imlementare
void recursive_insertion_sort(int vet[], int size, int index) {
    if(size == 0)
        return;
    if(vet[size-1] < vet[size-2]) {
        vet[size-1] = vet[size-2];
        recursive_insertion_sort(vet, size-1, index--);
    }   
         
}

void iteractive_selection_sort(int vet[], int size) {
    int menor = 0; // varivel q vai guardar o menor valor do vetor
    int index = 0; // variavel q vai guardar o indice do menro valor do vetor
    // 1, 5, 3, 4, 2
    for(int i = 0; i < size; i++) {
        index = i; // indice recebe o i da iteração atual
        menor = vet[i];
        for(int j = i; j < size; j++) {
            if(menor > vet[j]) {  
                menor = vet[j]; // Atribuo o valor do menor, se houver menor q a varivel menor
                index = j; // indice do menor é atualizado
            }
        }
        int tmp = vet[i]; // guardo o valor do vetor atual
        vet[i] = vet[index]; // troco
        vet[index] = tmp; // ajusto os valores
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

void print(int vet[], int size, std::string typing, std::string method) {
    std::cout << "Vetor ordenado " << typing << " usando método " << method << ": ";
    std::cout << "[";
    for(int i = 0; i < size; i++) {
        std::cout << vet[i];
        if(i != size-1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}