#include <stdio.h>
#include "Ponto.h"

int main() {
    float d;
    Ponto *p1, *q1;

    p1 = pto_cria(10, 21);
    q1 = pto_cria(7, 25);

    d = pto_distancia(p1, q1);
    printf("A distância é: %f", d);
    pto_libera(p1);
    pto_libera(q1);

    return 0;
}