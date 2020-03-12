#include <iostream>

using namespace std;

int soma_positivos(int *array, int size) {
    if(size == 1 && array[size-1] < 0)
        return 0;
    else if(size == 1 && array[size-1] >= 0)
        return array[size-1];

    if(array[size-1] > 0)  
        return array[size-1] + soma_positivos(array, size - 1);
    return soma_positivos(array, size-1); 
}

int main() {
    int size = 0;
    cin >> size;

    int *array = new int[size];
    for(int i = 0; i < size; i++)
        cin >> array[i];
    cout << soma_positivos(array, size);

    delete[] array;
    return 0;
}