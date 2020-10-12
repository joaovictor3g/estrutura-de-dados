#ifndef VETOR_ORDENADO_H
#define VETOR_ORDENADO_H

// Bubble sort recursivo
void recursive_bubble_sort(int vet[], int size, int index);

// Bubble sort iterativo
void iteractive_bubble_sort(int vet[], int size);

// Insertion Sort recursivo
void recursive_insertion_sort(int vet[], int size, int index, int key, int current);

// Insertion Sort iterativo
void iteractive_insertion_sort(int vet[], int size);

// Selection sort iterativo
void iteractive_selection_sort(int vet[], int size);

// Selection Sort recursivo
void recursive_selection_sort(int vet[], int size, int index, int min, int current);

// Mescla os vetores
void merge(int vet[], int begin, int middle, int end);

// Merge sort iterativo
void iteractive_merge_sort(int vet[], int begin, int end);

// Merge Sort recursivo
void recursive_merge_sort(int vet[], int begin, int end);

// verifica se vetor esta ordenado em ordem crescente
bool ascending_order(int vet[], int size);

// Imprime o vetor
// typing: recursivamente ou iterativamente
// method: metodo de ordenação usado
void print(int vet[], int size);

#endif