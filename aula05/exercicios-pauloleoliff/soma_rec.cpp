#include <iostream>

using namespace std;

int soma_rec(int *v, int n) {
    if(n == 1)
        return v[0];
    return v[n-1] + soma_rec(v, n-1);
}

int main() {
    int n = 0;
    cin >> n;
    int *vet = new int[n];
    for(int i = 0; i < n; i++)
        cin >> vet[i];
    cout << soma_rec(vet, n);

    delete[] vet;
    
    return 0;
}