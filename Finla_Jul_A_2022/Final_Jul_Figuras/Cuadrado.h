#ifndef CUADRADO_H
#define CUADRADO_H

#include "FiguraGeometrica.h"

class Cuadrado : public FiguraGeometrica
{
    public:
        Cuadrado(const char *nom, float lon);
        virtual float area() const;
        virtual float perimetro() const;
    private:
        float lado;
};

#endif // CUADRADO_H
