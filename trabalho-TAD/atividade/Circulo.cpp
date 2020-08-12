#include <iostream>
#include <cmath>
#include "Circulo.h"
using namespace std;

Circulo::Circulo(float _raio, Ponto centro) {
    p.x = centro.x;
    p.y = centro.y;
    raio = _raio;
    cout << "Círculo criado" << endl;
            
}

void Circulo::setRaio(float r) {
    raio = r;
}
float Circulo::getRaio() {
    return raio;
}

void Circulo::setY(float v) {
    p.y = v;

}
void Circulo::setX(float v) {
    p.x = v;

}
Ponto Circulo::getCentro() {
    return { p.x, p.y };    

}
float Circulo::area() {
    return pi*raio*raio;
} 

bool Circulo::interior(Ponto ponto) {
    float distanciaPontoAoRaio = sqrt(pow((ponto.x-p.x), 2) + pow((ponto.y-p.y), 2));
    return distanciaPontoAoRaio <= raio;
}

Circulo::~Circulo() {
    cout << "Memória liberada" << endl; 
    
}