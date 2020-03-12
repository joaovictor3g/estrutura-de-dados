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

void triangulo_de_somas(int *v, int n) {
    if(n == 1) 
        return;
    
    int novo_vet[n];
    for(int i = 0; i < n - 1; i++)
        novo_vet[i] = v[i] + v[i+1];
    triangulo_de_somas(novo_vet, n - 1);
    print_vet(novo_vet, n);
    
}

int main() {
    int n = 0;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    triangulo_de_somas(arr, n);
    cout << "[";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1)
            cout <<", ";
    }
    cout << "]" << endl;
    
    
    delete[] arr;
    return 0;
} 