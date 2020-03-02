#include <iostream>

struct Ponto {
    int x, y;

};

void dobraCoordenadas(Ponto *coo) {
    coo->x *= 2;
    coo->y *= 2;
}

void troca(Ponto *p1, Ponto *p2) {
    Ponto aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main() {
    Ponto a{2, 4}, b{4, 5};

    troca(&a, &b);
    std::cout << "ponto A1: " << " " << a.x << " " << "ponto A2: " << " " << a.y << std::endl;
    std::cout << "ponto B1: " << " " << b.x << " " << "ponto B2: " << " " << b.y << std::endl;

    dobraCoordenadas(&a);
    std::cout << "ponto A1: " << " " << a.x << " " << "ponto A2: " << " " << a.y << std::endl;
    

    return 0;
}