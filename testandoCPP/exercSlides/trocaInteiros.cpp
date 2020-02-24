#include <iostream>

void troca(int *v1, int *v2) {
    int aux;
    aux = *v1;
    *v1 = *v2;
    *v2 = aux;
    std::cout << "valor 1: " << *v1 << " valor 2: " << *v2 << std::endl;
}

int main() {
    int valor1 = 0, valor2 = 0;
    std::cin >> valor1 >> valor2;

    troca(&valor1, &valor2);
    

    return 0;
}