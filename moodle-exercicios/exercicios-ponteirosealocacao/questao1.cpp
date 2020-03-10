#include <iostream>

using namespace std;

void ler(int *array, int n) {
    for(int i = 0; i < n; i++)
        cin >> array[i];
}

void imprimir(int *array, int n) {
    for(int i = 0; i < n; i++) 
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    int n = 0;
    cin >> n;
    int *array = new int[n];

    ler(array, n);
    imprimir(array, n);

    delete[] array;
    return 0;
}