#include <iostream>

using namespace std;

void insertionSort(int* v, int tam){
    int i, j, aux = 0;
    for(i = 1; i < tam; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--)
            v[j] = v[j-1];
        v[j] = aux;
    }
    for(int k = 0; k < tam; k++)    cout << v[k] << " ";
    cout << endl;
}

int main() {
    int tamanho = 0;
    int *vetor;

    cin >> tamanho;
    vetor = new int[tamanho];

    for(int i = 0; i < tamanho; i++)    cin >> vetor[i];

    insertionSort(vetor, tamanho);
    delete[] vetor;

    return 0;
}
