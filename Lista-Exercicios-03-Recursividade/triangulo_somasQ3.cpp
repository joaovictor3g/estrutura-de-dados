#include <iostream>

using namespace std;

void imprimir(int *array, int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i];
        if(i < size-1)
            cout << ", ";
    }
    cout << endl;
}

void triangulo_soma(int *array, int size) {
    if(size == 0) 
        return; 
    
    int novo_vetor[size];
    for(int i = 0; i < size-1; i++)
        novo_vetor[i] = array[i]+array[i+1];
    
    triangulo_soma(novo_vetor, size-1);
    imprimir(array, size);
}

int main() {
    int size = 0;
    cin >> size;

    int *vetor = new int[size];
    for(int i = 0; i < size; i++)
        cin >> vetor[i];

    triangulo_soma(vetor, size);

    delete[] vetor;
}