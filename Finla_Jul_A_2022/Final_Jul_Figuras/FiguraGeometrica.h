#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include <iostream>
using namespace std;

class FiguraGeometrica
{
    public:
        FiguraGeometrica(const char *nom);
        ~FiguraGeometrica();
        const char* get_nombre() const;
        virtual float area() const = 0;
        virtual float perimetro() const = 0;
    private:
       char *nombre;
};

#endif // FIGURAGEOMETRICA_H
