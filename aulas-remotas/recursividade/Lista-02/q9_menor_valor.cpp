//  Crie um programa em C++, que contenha uma fun¸c˜ao recursiva para encontrar o
// menor elemento em um vetor. A leitura dos elementos do vetor e impress˜ao do menor
// elemento devem ser feitas no programa principal.


#include <iostream>

using namespace std;

int lesser_value(int *arr, int size) {
    if(size == 1)
        return arr[size-1];

    int menor = lesser_value(arr, size-1);
    if(menor > arr[size-1]) 
        return arr[size-1];
    return menor;
}

int main() {
    int size = 0;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    cout << lesser_value(arr, size);
    delete[] arr;

    return 0;
}