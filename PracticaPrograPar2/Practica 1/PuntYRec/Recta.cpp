#include "Recta.h"

Recta::Recta(Punto pOne, Punto pTwo)
{
    setRecta(pOne, pTwo);
}
//Recta::~Recta()
//{
//    //dtor
//}
//setter
void Recta::setRecta(const Punto pOne, const Punto pTwo)
{
    p1 = pOne;
    p2 = pTwo;
}
//getter
Punto Recta::getPunto1() const { return p1; }
Punto Recta::getPunto2() const { return p2; }

//friend
ostream &operator<<(ostream &output, const Recta r)
{
    output << "[(" << r.p1.getX() << "," << r.p1.getY()<<"),"
           << "(" << r.p2.getX() << "," << r.p2.getY() << ")]";

    return output;
}
istream &operator>>(istream &input, const Recta r)
{
    Punto p1, Punto p2;
    input.ignore();
    input.getline(r.p1.setX, 1);
    input.ignore();
    input.getline(r.p2.setY)
}
