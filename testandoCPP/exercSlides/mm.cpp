#include <iostream>

void mm(int *A, int n, int *min, int *max) {
    A = new int[n];
    *min = 1000;
    *max = -1000;

    for(int i = 0; i < n; i++) 
        std::cin >> A[i];
    

    for(int i = 0; i < n; i++) {
        if(*min > A[i])     *min = A[i];

        if(*max < A[i])     *max = A[i];
        
    }

}   

int main() {
    int *vetor;
    int tam = 0;
    int minimo = 0, maximo = 0;

    std::cin >> tam;

    mm(vetor, tam, &minimo, &maximo);
    std::cout << "Mínimo é: " << minimo << " Máximo é: " << maximo << std::endl;

    return 0;
}