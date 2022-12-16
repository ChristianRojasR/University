#include "Cuadrado.h"

Cuadrado::Cuadrado(const char *nom, float lon) : FiguraGeometrica(nom)
{
    this->lado = lon;
}

float Cuadrado::area() const
{
    return this->lado * this->lado;
}

float Cuadrado::perimetro() const
{
    return 4 * this->lado;
}
