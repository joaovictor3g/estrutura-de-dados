#include <iostream>

using namespace std;

int menorV(int *arr, int size) {
    if(size == 0)
        return 0;
    int menor = menorV(arr, size-1);
    
    if(menor > arr[size-1])
        return arr[size-1];
    return menor;
}

int maiorV(int *arr, int size) {
    if(size == 0)
        return 0;
    int maior = maiorV(arr, size-1);
    
    if(maior < arr[size-1])
        return arr[size-1];
    return maior;
}

int main() {
    int size = 0;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    cout << maiorV(arr, size) - menorV(arr, size) << endl;

    delete[] arr;
    return 0;
}