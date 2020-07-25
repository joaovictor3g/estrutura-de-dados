#include <iostream>

using namespace std;

int soma_maior_e_menor(int *arr, int size) {
    if(size == 0)
        return 0;
    int menor = soma_maior_e_menor(arr, size-1);
    int maior = soma_maior_e_menor(arr, size-1);
    if(menor > arr[size-1])
        return arr[size-1];
    if(maior < arr[size-1])
        return arr[size-1];
}

int main() {
    int size = 0;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    delete[] arr;
    return 0;
}