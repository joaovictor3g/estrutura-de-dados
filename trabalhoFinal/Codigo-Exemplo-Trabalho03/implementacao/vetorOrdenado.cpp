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

// a imlementar
// 3, 5, 1, 9, 0
void recursive_insertion_sort(int vet[], int size, int index, int key, int current) {
    while(index >= 0 && key < vet[index]) {
        vet[index+1] = vet[index]; // Valores maiores q a chave vão sendo deslocados a direita
        index--; // index decrementado
    }
    vet[index+1] = key; // valor atualizado com a chave
    if(current < size-1) {  
        // valor q key vai receber q é o próximo a direita dele
        recursive_insertion_sort(vet, size, current, vet[current+1], current+1);
    }else return; // Caso base
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


void print(int vet[], int size) {
    std::cout << "Vetor ordenado : ";
    std::cout << "[";
    for(int i = 0; i < size; i++) {
        std::cout << vet[i];
        if(i != size-1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
void insertionSortRecursive(int arr[], int n) 
{ 
    // Base case 
    if (n <= 1) 
        return; 
  
    // Sort first n-1 elements 
    insertionSortRecursive( arr, n-1 ); 
  
    // Insert last element at its correct position 
    // in sorted array. 
    int last = arr[n-1]; 
    int j = n-2; 
  
    /* Move elements of arr[0..i-1], that are 
      greater than key, to one position ahead 
      of their current position */
    while (j >= 0 && arr[j] > last) 
    { 
        arr[j+1] = arr[j]; 
        j--; 
    } 
    arr[j+1] = last; 
} 