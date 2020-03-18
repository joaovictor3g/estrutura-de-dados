#include <iostream>

using namespace std;

int cont = 0;

int fib(int num) {
    if(num == 0 || num == 1) return num;
    cont++;
    return fib(num-1)+fib(num-2);
}

int main() {
    int numero = 0;
    cin >> numero;
    cout << fib(numero) << endl;
    cout << cont;
    
    return 0;
}