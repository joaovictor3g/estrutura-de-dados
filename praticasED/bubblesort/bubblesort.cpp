#include <iostream>
#include <cstdlib>

using namespace std;

void bubbleSort(int *v, int N){
    int i, continua, aux, fim = N;
    do {
        for(i = 0; i < fim - 1; i++){
            if(v[i] > v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);

    for(int j = 0; j < N; j++)  cout << v[j] << " ";
    cout << endl;
}

void liberar(int *vetor){
    free(vetor);
} 

int main() {
    int *vetor;
    int tamanho = 0;
    cin >> tamanho;

    vetor = (int *) malloc (tamanho * sizeof(int));
    for(int i = 0; i < tamanho; i++)    cin >> vetor[i];

    bubbleSort(vetor, tamanho);
    liberar(vetor);


    return 0;
}