#include <iostream>
#include <cstdlib>
#include "vetorOrdenado.h"
#include "listaOrdenada.h"
#define TAM 10

int main() {
    srand(time(NULL));

    int *vetor = new int[TAM];
    // List *list = new List();
        
    for(int i = 0; i < TAM; i++) { 
        vetor[i] = rand()%1000;
        // list->pushBack(vetor[i]);
    }

    std::cout << "Vetor original: ";
    for(int i = 0; i < TAM; i++) 
        std::cout << vetor[i] << " ";
    std::cout << std::endl;

    iteractive_bubble_sort(vetor, TAM);
    print(vetor, TAM, "iterativamente", "BubbleSort");
    
    int index = TAM;
    
    // recursive_bubble_sort(vetor, index, index);
    // print(vetor, TAM, "recursivamente", "BubbleSort");

    // iteractive_insertion_sort(vetor, TAM);
    // print(vetor, TAM, "iterativamente", "InsertionSort");

    

    delete[] vetor;

}