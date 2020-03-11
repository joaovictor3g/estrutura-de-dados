#include <iostream>

using namespace std;

int iguais_rec(int *a, int *b, int n) {
    if(n == 0)
        return 0;
    if(a[n-1] == b[n-1]) 
        return 1;
    return iguais_rec(a, b, n-1);
}

int main() {
    int n = 0;
    cin >> n;
    int *a = new (nothrow) int[n];
    int *b = new (nothrow) int[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    if(iguais_rec(a, b, n))
        cout << "SIM" << endl;
    else cout << "NÃO" << endl;

    delete[] a;
    delete[] b;

    return 0;
}