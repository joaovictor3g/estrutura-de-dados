#include <iostream>

struct Ponto {
    float x, y;    
};

void trocaPonto(Ponto *p1, Ponto *p2) {
    Ponto aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;

}

void dobrarValor(Ponto *coordenada) {
    coordenada->x *= 2;
    coordenada->y *= 2;
}

int main() {
    Ponto a{2, 3}, b{4, 4};
    trocaPonto(&a, &b);
    
    std::cout << "a = ( " << a.x << ", " << a.y << " )\n";
    std::cout << "b = ( " << b.x << ", " << b.y << " )\n";

    dobrarValor(&a);
    std:: cout << "a = ( " << a.x <<", " << a.y << " )\n";

    dobrarValor(&b);
    std:: cout << "b = ( " << b.x <<", " << b.y << " )\n";

    return 0;
}