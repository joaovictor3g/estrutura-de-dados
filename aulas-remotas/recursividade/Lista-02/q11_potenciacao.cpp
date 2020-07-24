// Crie um programa em C++, que contenha uma fun¸c˜ao recursiva que receba dois
// inteiros positivos k e n e calcule k
// n
// . Utilize apenas multiplica¸c˜oes. O programa
// principal deve solicitar ao usu´ario os valores de k e n e imprimir o resultado da
// chamada da fun¸c˜ao.

#include <iostream>

using namespace std;

int evaluate(int base, int exponent) {
    if(exponent==0)
        return 1;
    if(base == 0)
        return 0;
    return base * evaluate(base, exponent-1);
}

int main() {
    int base = 0, exponent = 0;
    cin >> base >> exponent;
    cout << evaluate(base, exponent);

    return 0;
}