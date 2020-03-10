#include <iostream>

using namespace std;

int *aloc(int n) {
   
    int *array = new ( nothrow ) int[n];

    if(array == nullptr) {
        cout << "Array não alocado." << endl;
        exit(1);
    }
    return array;
}

void ler(int *array, int n) {
    for(int i = 0; i < n; i++)
        cin >> array[i];
}

void imprimirArray(int *array, int n) {
    for(int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}

void liberar(int *array) {
    delete[] array;
}

int main() {
    int n = 0;
    cin >> n;
    int *arr = aloc(n);
    
    ler(arr, n);
    imprimirArray(arr, n);
    liberar(arr);
    
    return 0;
}