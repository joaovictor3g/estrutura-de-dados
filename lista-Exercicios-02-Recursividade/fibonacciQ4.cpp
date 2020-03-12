#include <iostream>

using namespace std;

int fib(int num) {
    if(num == 0 || num == 1) return num;

    return fib(num-1)+fib(num-2);
}

int main() {
    int numero = 0;
    cin >> numero;
    cout << fib(numero) << endl;

    return 0;
}