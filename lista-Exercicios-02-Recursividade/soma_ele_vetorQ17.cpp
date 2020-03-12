#include <iostream>

using namespace std;

int soma_elementos_vetor(int *vet, int size) {
    if(size == 1)
        return vet[size-1];
    return vet[size-1] + soma_elementos_vetor(vet, size-1);

}

int main() {
    int size = 0;
    cin >> size;
    
    int *array = new (nothrow) int[size];
    for(int i = 0; i < size; i++)
        cin >> array[i];

    cout << soma_elementos_vetor(array, size);

    delete[] array;
    return 0;
}