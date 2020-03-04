#include <iostream>

using namespace std;

//Preencher array que já foi alocado
void preencheArray(int *A, int n);

//imprimir vetor lido
void imprimeArray(int *A, int n);

//liberar região de memória apontada
void liberar(int *A);

int  main() {
    int tamanho = 0;
    cin >> tamanho;
    int *array = new int[tamanho];

    preencheArray(array, tamanho);
    imprimeArray(array, tamanho);
    liberar(array);
    array = nullptr;

    return 0;
}

void preencheArray(int *A, int n) {
    if(A != nullptr) {
        for(int i = 0; i < n; i++)
            cin >> A[i];
    
    } else 
        cout << "Array Nulo" << endl;
    
}

void imprimeArray(int *A, int n) {
    if(A != nullptr) {
        for(int i = 0; i < n; i++) 
            cout << A[i] << " ";
        cout << "\n";
        
    }
}

void liberar(int *A) {
    delete[]  A;
}