#include <iostream>
#include <cstdlib>
#include "vetorOrdenado.h"
#define TAM 1000

int main() {
    srand(time(NULL));

    int *vetor = new int[TAM];
    for(int i = 0; i < TAM; i++) 
        vetor[i] = rand()%1000;
    

    std::cout << "Vetor original: ";
    for(int i = 0; i < TAM; i++) 
        std::cout << vetor[i] << " ";
    std::cout << std::endl;

    // iteractive_bubble_sort(vetor, TAM);
    // std::cout << "Vetor ordenado iterativamente: ";
    // for(int i = 0; i < TAM; i++)
    //     std::cout << vetor[i] << " ";
    // std::cout << std::endl;

    // int index = TAM;
    
    // recursive_bubble_sort(vetor, index, index);
    // std::cout << "Vetor ordenado recursivamente: ";
    // for(int i = 0; i < TAM; i++)
    //     std::cout << vetor[i] << " ";
    // std::cout << std::endl;

    iteractive_insertion_sort(vetor, TAM);
    std::cout << "Vetor ordenado iterativamente: ";
    for(int i = 0; i < TAM; i++)
        std::cout << vetor[i] << " ";
    std::cout << std::endl;

    delete[] vetor;

}