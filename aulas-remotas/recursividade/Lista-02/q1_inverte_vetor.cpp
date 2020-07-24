#include <iostream>

using namespace std;

void inverte_vetor(int *arr, int size) {
    if(size==0) 
        return;

    cout << arr[size-1] << " ";
    inverte_vetor(arr, size-1);
    
}

// Crie um programa em C++ que receba um vetor de n´umeros reais com n elementos.
// Escreva uma fun¸c˜ao recursiva que inverta a ordem dos elementos presentes no vetor.

int main() {
    int size = 0;
    cin >> size;
    int *arr = new int[size];

    for(int i = 0; i < size; i++)
        cin >> arr[i];

    inverte_vetor(arr, size);

    delete[] arr;

    return 0;
}