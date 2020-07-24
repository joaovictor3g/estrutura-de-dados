#include <iostream>

using namespace std;

int menor=0;

int max_max(int *vetor, int size) {
    if(size == 0) 
        return 0;

    int maior = max_max(vetor, size-1);

    if(maior < vetor[size-1]) {
        return vetor[size-1];
    
    }else {
        return maior;
    
    }
}

int min_min(int *vetor, int size) {
    if(size == 0) 
        return 0;

    int menor = min_min(vetor, size-1);

    if(menor > vetor[size-1]) 
        return vetor[size-1];
    
    else    return menor;
    
}

int main() {
    int size = 0;
    cin >> size;

    int *vetor = new (nothrow) int[size];
    if(vetor == nullptr) {
        cout << "Erro\n";
        exit(1); 
    }

    for(int i = 0; i < size; i++)
        cin >> vetor[i];


    cout << max_max(vetor, size) - min_min(vetor, size)<< endl;


    return 0;
}