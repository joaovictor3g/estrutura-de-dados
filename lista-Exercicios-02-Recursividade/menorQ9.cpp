#include <iostream>

using namespace std;

int menor_elemento(int *vetor, int size) {
    if(size == 0)   return 0;
    
    if(size == 1)
        return vetor[size-1];

    int menor = menor_elemento(vetor, size-1);
    if(vetor[size-1] < menor)
        return vetor[size-1];
    return menor;
}

int main() {
    int size = 0;
    cin >> size;

    int array[size];
    for(int i = 0; i < size; i++)
        cin >> array[i];

    cout << menor_elemento(array, size);

    return 0;
}