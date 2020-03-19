#include <iostream>

using namespace std;

int main() {
    int size = 10, i = 0;
    int *vetor = new (nothrow) int[size];

    if(vetor == nullptr) {
        cout << "Alocação mal-sucedida" << endl;
        exit(1);
    }
    
    vetor[0] = 1;

    while(vetor[i] != 0) {
        cin >> vetor[i+1];
        i++;

        if(i == size - 1) {
            size+=10;
            int *aux = new (nothrow) int[size];

            for(int j = 0; j < size - 10; j++) 
                aux[j] = vetor[j];
            delete[] vetor;

            vetor = new int[size];
            for(int j = 0; j < size - 10; j++)
                vetor[j] = aux[j];
            
            delete[] aux;
        }
    }
    for(int j = 1; j < i; j++) {
        cout << vetor[j] << " ";
    }
    cout << endl;

    delete[] vetor;
    return 0;
}