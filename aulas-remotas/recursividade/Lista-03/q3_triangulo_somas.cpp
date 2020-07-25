#include <iostream>

using namespace std;

void imprimir(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void triangulo_soma(int *arr, int size) {
    if(size == 0)
        return;
    int *new_arr = new int[size];
    for(int i = 0; i < size; i++) 
        new_arr[i] = arr[i]+arr[i+1];
    triangulo_soma(new_arr, size-1);
    imprimir(arr, size);
}

int main() {
    int size = 0;
    cin >> size;

    int *arr = new (nothrow) int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    triangulo_soma(arr, size);    

    delete[] arr;
    return 0;
}