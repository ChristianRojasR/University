#ifndef CIRCULO_H
#define CIRCULO_H

#include "FiguraGeometrica.h"

class Circulo : public FiguraGeometrica
{
    public:
        Circulo(const char *nom, float rad);
        virtual float area() const;
        virtual float perimetro() const;
    private:
        float radio;
};

#endif // CIRCULO_H
