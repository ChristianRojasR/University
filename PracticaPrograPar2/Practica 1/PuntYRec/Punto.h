#ifndef PUNTO_H
#define PUNTO_H

#include "iostream"

using namespace std;


class Punto
{

    public:
        Punto(double = 0, double = 0);
        //~Punto();

        //Setters
        void setPunto(const double xx,const double yy);
        void setX(const double xx);
        void setY(const double yy);
        //Getter
        double getX() const;
        double getY() const;


    private:
        double x;
        double y;
};

#endif // PUNTO_H
