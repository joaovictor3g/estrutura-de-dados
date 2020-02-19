#include <iostream>

using namespace std;

void bubbleSort(int* v, int tamanho){
    int ordenado = 0;

    while(!ordenado){
        ordenado = 1;
        for(int i = 0; i < tamanho - 1; i++){
            if(v[i] > v[i+1]){
                ordenado = 0;
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
    }
    for(int i = 0; i < tamanho; i++)     
        cout << v[i] << " ";
    cout << endl;
    for(int i = tamanho - 1; i >= 0; i--)     
        cout << v[i] << " ";
    cout << endl;
}

int main(){
    int tam = 0;
    int *vet;

    cin >> tam;
    vet = (int *) malloc (tam * sizeof(int));

    for(int i = 0; i < tam; i++) cin >> vet[i];

    bubbleSort(vet, tam);
    
    

    return 0;
}