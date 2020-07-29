#include <iostream>

using namespace std;

void soma_maior_menor(int *arr, int size, int *max, int *min) {
    if(size == 0)
        return;
    if(arr[size-1] >= *max) 
        *max = arr[size-1];
    if(arr[size-1] < *min)
        *min = arr[size-1];
    soma_maior_menor(arr, size-1, max, min);
}

int main() {
    int size = 0, max = 0, min = 0;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    max = arr[0];
    min = arr[0];

    soma_maior_menor(arr, size, &max, &min);
    cout << max - min << endl;

    delete[] arr;
    return 0;
}