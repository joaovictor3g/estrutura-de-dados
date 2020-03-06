#include <iostream>

void troca (int *i, int *j) {
    int *temp = nullptr; //Ponteiro deve sempre ser iniciado com: NULL, nullptr, 0 ou um endereço de outa variavel.
    *temp = *i;
    *i = *j;
    *j = *temp;
}

int main() {
    int i = 0, j = 0;
    std::cin >> i >> j;
    troca(&i, &j);
    std::cout << i << " " << j;

    

    return 0;
}