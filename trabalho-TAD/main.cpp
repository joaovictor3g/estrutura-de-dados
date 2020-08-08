#include <iostream>
#include "circulo.h"

using namespace std;

int main() {    
    Circulo circ{ 2, { 3, 6 } };

    cout << circ.area() << endl;
    circ.setRaio(6);
    cout << circ.area() << endl;
    cout << circ.getRaio() << endl;
    circ.setX(7);
    circ.setY(8);

    return 0;
}