#include <iostream>

using namespace std;

void imprimir_pares(int nLimite) {
    if(nLimite == 0){    
        cout << nLimite;
        return;
    }
    else if(nLimite % 2 == 0) {
        cout << nLimite << " ";
        imprimir_pares(nLimite - 2);
    } 
    else imprimir_pares(nLimite - 1);
}

int main() {
    int num = 0;
    cin >> num;
    imprimir_pares(num);

    return 0;
}