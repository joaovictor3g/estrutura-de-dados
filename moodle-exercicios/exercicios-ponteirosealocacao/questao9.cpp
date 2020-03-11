#include <iostream>

using namespace std;

void lerA(int *a, int n) {
    for(int i = 0; i < n; i++)
        cin >> a[i];

}

void lerB(int *b, int n) {
    for(int i = 0; i < n; i++)  
        cin >> b[i];
}

int *somaVetor(int *a, int *b, int n) {
    int *c = new (nothrow) int[n];
    
    if(c != nullptr) {
        for(int i = 0; i < n; i++)
            c[i] = a[i] + b[i];
    }
    return c;
}

int main() {
    cout << "Digite a quantidade de elementos "; 
    int n = 0;
    cin >> n;
    int *a = new ( nothrow ) int[n];
    int *b = new ( nothrow ) int[n];

    lerA(a, n);
    lerB(b, n);
    cout << "Vetor resultante: ";
    for(int i = 0; i < n; i++) 
        cout << *somaVetor(a+i, b+i, n) << " ";
    cout << endl;

    delete[] a;
    delete[] b;

    return 0;
}