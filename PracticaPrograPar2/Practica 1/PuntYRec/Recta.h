#ifndef RECTA_H
#define RECTA_H

#include "Punto.h"
#include "iostream"

using namespace std;

class Recta
{
    friend ostream &operator<<(ostream &output, const Recta r);
    friend istream &operator>>(istream &input, const Recta r);

    public:
        Recta();
        Recta(Punto, Punto);
        //~Recta();

        //setter
        void setRecta(const Punto pOne, const Punto pTwo);
        //getter
        Punto getPunto1() const;
        Punto getPunto2() const;

    private:
        Punto p1;
        Punto p2;
};

#endif // RECTA_H
