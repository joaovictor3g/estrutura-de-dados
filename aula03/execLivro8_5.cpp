#include <iostream>
#include <cmath>
#include "execLivro8_5.h"

using std::sqrt;
using std::pow;
using std::cout;
using std::cin;
using std::endl;

int main() {
    double x = 0, y = 0;
    int base = 0, potencia = 0;
    int raiz_quadrada = 0;

    cout << "Digite dois valores em ponto flutuante pra serem trocados " << endl;
    cin >> x >> y;
    cout << "Resultado da troca: ";
    exchange(&x, &y);
    cout << x << " " << y << endl;

    cout << "Digite uma base para ser elevada pela raiz da potencia: " << endl;
    cin >> base;
    cout << "O resultado é: "<< evaluate(base, elevar) << endl;

    return 0;
}

void exchange(double *x, double *y) {
    double aux = *x;
    *x = *y;
    *y = aux;
}

int evaluate(int x, int (*poly )( int )) {
    int y = 144;
    int elevado = pow(x, (*poly)(y));

    return elevado;
}

int elevar(int y) {
    

    return sqrt(y);
}