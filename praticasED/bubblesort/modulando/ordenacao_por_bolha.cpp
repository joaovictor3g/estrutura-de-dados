#include <iostream>
#include "ordenacao_por_bolha.h"

using namespace std;

void bubbleSort(int *vetor, int n){
    bool ordenado = false;

    while( !ordenado ){
        ordenado = true;
        for(int i = 0; i < n - 1; i++){
            if(vetor[i] > vetor[i+1]){
                ordenado = false;
                int aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
    for(int i = 0; i < n; i++) 
        cout << vetor[i] << " ";
    cout << endl;
}

void liberar(int *vet){
    free(vet);
}

int main() {
    int n{0};
    cin >> n;
    int *vet = (int *) malloc (n * sizeof(int));

    for(int i = 0; i < n; i++)
        cin >> vet[i];

    bubbleSort(vet, n);
    liberar(vet);

    return 0;
}