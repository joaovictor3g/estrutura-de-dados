#include <iostream>
#include <cstring>

using namespace std;

char *invertida(char *palavra, int n) {
    char *aux = new char[n];
    int cont = 0;
    for(int i = n - 1; i >= 0; i--) {
        aux[cont] = palavra[i];
        cont++;
    }
    return aux;
}

int main() {
    int n = 0;
    cin >> n;
    char *arrChar = new char[n];
    for(int i = 0; i < n; i++)
        cin >> arrChar[i];
        
    for(int i = 0; i < n; i++)
        cout << invertida(arrChar + i, n);

    return 0;
}