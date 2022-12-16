#include "FiguraGeometrica.h"
#include <string.h>

FiguraGeometrica::FiguraGeometrica(const char *nom)
{
    this->nombre = new char[strlen(nom)+1];
    strcpy(this->nombre, nom);
}

FiguraGeometrica::~FiguraGeometrica()
{
    delete [] this->nombre;
}

const char* FiguraGeometrica::get_nombre() const
{
    return this->nombre;
}
