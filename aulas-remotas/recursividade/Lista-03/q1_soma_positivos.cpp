#include <iostream>

using namespace std;

int soma_positivos(int *arr, int size) {
    if(size == 0)
        return 0;

    if(arr[size-1]>0)
        return arr[size-1] + soma_positivos(arr, size-1);
    return soma_positivos(arr, size-1);
}

int main() {
    int size = 0;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    cout << soma_positivos(arr, size) << endl;

    delete[] arr;

    return 0;
}