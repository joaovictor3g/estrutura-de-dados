#include <iostream>

using namespace std;

void imprimir_naturais(int nLimite) {
    if(nLimite == 0) {
        cout << nLimite;   
        return;
    }
    cout << nLimite << " ";
    imprimir_naturais(nLimite - 1);
    
}

int main() {
    int num = 0;
    cin >> num;
    imprimir_naturais(num);

    return 0;
}