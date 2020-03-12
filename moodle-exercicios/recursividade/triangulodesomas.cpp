#include <iostream>

using namespace std;

void print_vet(int *vet, int size) {
    cout << "[";
    for(int i = 0; i < size - 1; i++) {
        cout << vet[i];

        if(i < size-2)
            cout << ", ";
    }
    cout << "]\n";
}

void triangulo_de_somas(int *vetor, int size) {
    if(size == 1) 
        return;
    
    int novo_vet[size];
    for(int i = 0; i < size - 1; i++)
        novo_vet[i] = vetor[i] + vetor[i+1];
    triangulo_de_somas(novo_vet, size - 1);
    print_vet(novo_vet, size);
    
}

int main() {
    int size = 0;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    triangulo_de_somas(arr, size);
    cout << "[";
    for(int i = 0; i < size; i++) {
        cout << arr[i];
        if(i < size-1)
            cout <<", ";
    }
    cout << "]" << endl;
    
    
    delete[] arr;
    return 0;
} 