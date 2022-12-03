#include "Punto.h"

Punto::Punto(double xx, double yy)
{
    setPunto(xx, yy);
}
//Punto::~Punto()
//{
//    //dtor
//}
//Setters
void Punto::setPunto(const double xx,const double yy)
{
    x = (xx >= 0) ? xx : 0;
    y = (yy >= 0) ? yy : 0;
}
void Punto::setX(const double xx)
{
    x = (xx >= 0) ? xx : 0;
}
void Punto::setY(const double yy)
{
    y = (yy >= 0) ? yy : 0;
}
//Getter
double Punto::getX() const { return x; }
double Punto::getY() const { return y; }
