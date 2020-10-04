#ifndef VETOR_ORDENADO_H
#define VETOR_ORDENADO_H

// Bubble sort recursivo
void recursive_bubble_sort(int vet[], int size, int index);

// Bubble sort iterativo
void iteractive_bubble_sort(int vet[], int size);

// Insertion Sort recursivo
void recursive_insertion_sort(int vet[], int size, int index);

// Insertion Sort iterativo
void iteractive_insertion_sort(int vet[], int size);

// Selection sort iterativo
void iteractive_selection_sort(int vet[], int size);

// verifica se vetor esta ordenado em ordem crescente
bool ascending_order(int vet[], int size);

// Imprime o vetor
// typing: recursivamente ou iterativamente
// method: metodo de ordenação usado
void print(int vet[], int size, std::string tying, std::string method);

#endif