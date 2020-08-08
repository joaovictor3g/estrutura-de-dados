#ifndef CIRCULO_H
#define CIRCULO_H
#include <iostream>
#include <cmath>

using namespace std;

struct Ponto {
    float x, y, a, b;
};


class Circulo {
    private:
        float raio, pi=3.14;
       
    public: 
        Circulo(float _raio, Ponto centro) {
            Ponto p;
            p.a = centro.a;
            p.b = centro.b;
            raio = _raio;
        }

        void setRaio(float r) {
            raio = r;
        }

        float getRaio() {
            return raio;
        }

        void setY(float v) {
            Ponto p;
            p.y = v;
        }

        void setX(float v) {
            Ponto p;
            p.x = v;
        }

        Ponto getCentro() {
            Ponto p{ p.a, p.b };

            return p;   
        }

        float area() {
            return pi*raio*raio;
        }

        ~Circulo() {
            cout << "Memória liberada" << endl; 
        }
};

#endif 