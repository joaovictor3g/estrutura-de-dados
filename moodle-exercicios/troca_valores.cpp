#include <iostream>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int x = 0, y = 0;
    std::cin >> x >> y;

    troca(&x, &y);
    std::cout << x << " " << y << std::endl;

    return 0;

}