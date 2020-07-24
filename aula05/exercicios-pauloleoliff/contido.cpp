#include <iostream>

using namespace std;

int buscaSublista(int *a, int k, int *b, int n) {
    if(n == 0 || k == 0)
        return 0;
    else if(a[k-1] == b[n-1])
        return buscaSublista(a, k - 1, b, n) + 1;
    return buscaSublista(a, k, b, n - 1);
    /*
        (5, 6, 4) está em (9, 5, 6, 3, 9, 6, 4, 7)
    */
}

int main() {
    int n = 0, k = 0;
    cin >> k;

    int *a = new (nothrow) int[k];
    for(int i = 0; i < k; i++) 
        cin >> a[i];

    cin >> n;
    int *b = new (nothrow) int[n];
    for(int i = 0; i < n; i++)
        cin >> b[i];
        
    if(buscaSublista(a, k, b, n) == k) 
        cout << "Está contido" << endl;
    else 
        cout << "Não está contido" << endl;

    delete[] a;
    delete[] b;

    return 0;
}