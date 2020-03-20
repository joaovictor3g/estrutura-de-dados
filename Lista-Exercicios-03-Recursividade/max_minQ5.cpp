#include <iostream>

using namespace std;

int menor=0;

int max_min(int *vetor, int size) {
    if(size == 0) 
        return 0;

    int maior = max_min(vetor, size-1);

    if(maior < vetor[size-1]) {
        menor = maior;
        return vetor[size-1];
    
    }else {
        menor = vetor[size-1]; 
        return maior;
    
    }

}
/*
    -1
    2
    4
    6
    5

*/
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


    cout << max_min(vetor, size) << " " <<  menor << endl;


    return 0;
}