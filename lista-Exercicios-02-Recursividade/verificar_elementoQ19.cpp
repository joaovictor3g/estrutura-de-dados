#include <iostream>

using namespace std;

int verificar_se_contem(int *array, int size, int elemento) {
    if(size == 0)
        return 0;
    if(array[size-1] == elemento)
        return 1;
    return verificar_se_contem(array, size-1, elemento);
}

int main() {
    int size = 0;
    cin >> size;

    int *array = new (nothrow) int[size];
    for(int i = 0; i < size; i++)
        cin >> array[i];
    
    int elemento = 0;
    cin >> elemento;

    cout << verificar_se_contem(array, size, elemento);

    delete[] array;
    return 0;
}