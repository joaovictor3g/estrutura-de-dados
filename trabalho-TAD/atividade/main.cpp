#include <iostream>
#include "Circulo.h"

using namespace std;

int main() {
    Ponto coords{ 3, 6 };
    // Instanciando a classe Circulo    
    Circulo circ{ 2, coords };

    // Impressão do cálculo da área
    cout << circ.area() << endl;
    // Modificando o raio
    circ.setRaio(6);

    // Imprimindo área
    cout << circ.area() << endl;
    // Imprimindo o raio
    cout << circ.getRaio() << endl;
    // Modificando a coordenada x
    circ.setX(7);
    // Modificando a coordenada y
    circ.setY(8);

    Ponto point{ 5, 7 };
    Circulo circ2{ 4, point };
    cout << "CENTRO: (" << point.x << ", " << point.y << ")" << endl;

    if(circ2.interior({ 1, 1 })) 
        cout << "Pertence ao circulo" << endl;
    else
        cout<< "Não pertence" << endl; 

    return 0;
}