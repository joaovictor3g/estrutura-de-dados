#include <iostream>

struct Ponto {
    float x, y;

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
    Ponto a, b;
    std::cout << "Digite as coordenadas de a{x, y}" << std::endl;
    std::cin >> a.x >> a.y;

    std::cout << "Digite as coordenadas de b{x, y}" << std::endl;
    std::cin >> b.x >> b.y;

    troca(&a, &b);
    std::cout << "ponto A1: " << " " << a.x << " " << "ponto A2: " << " " << a.y << std::endl;
    std::cout << "ponto B1: " << " " << b.x << " " << "ponto B2: " << " " << b.y << std::endl;

    dobraCoordenadas(&b);
    std::cout << "ponto A1: " << " " << b.x << " " << "ponto A2: " << " " << b.y << std::endl;
    

    return 0;
}