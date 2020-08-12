#ifndef CIRCULO_H
#define CIRCULO_H
#include <iostream>
#include <cmath>

using namespace std;

struct Ponto {
    float x, y;
};

class Circulo {
    private:
        float raio, pi=3.14;
        Ponto p;
    public: 
        Circulo(float _raio, Ponto centro);

        void setRaio(float r);

        float getRaio();

        void setY(float v);

        void setX(float v);

        Ponto getCentro();

        float area();

        bool interior(Ponto p);

        ~Circulo();
};

#endif 