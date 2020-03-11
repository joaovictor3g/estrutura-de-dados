#include <iostream>

using namespace std;

int busca_simples(int *v, int n, int x) {
    if(n == 0)
        return 0;
    else if(v[n-1] == x)
        return 1;
    return busca_simples(v, n - 1, x);

}

int main() {
    int n = 0;
    cin >> n;
    int *vet = new int[n];

    for(int i = 0; i < n; i++)
        cin >> vet[i];
    int x = 0;
    cin >> x;

    if(busca_simples(vet, n, x))
        cout << "SIM" << endl;
    else 
        cout << "NÃO" << endl;

    return 0;
}