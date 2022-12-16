#include "Circulo.h"

Circulo::Circulo(const char *nom, float rad) : FiguraGeometrica(nom)
{
    this->radio = rad;
}

float Circulo::area() const
{
    return this->radio * this->radio * 3.14;
}

float Circulo::perimetro() const
{
    return 2 * 3.14* this->radio;
}
