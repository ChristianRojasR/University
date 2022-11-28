#include "Cadena.h"
#include "string.h"

Cadena::Cadena()
{
    this->cad = new char[1000];
}

Cadena &Cadena::operator+(char *cad)
{
    strcat(this->cad, cad);

    return *this;
}

Cadena& Cadena::operator=(const char *s)
{
    memcpy(this->cad, s,sizeof(s));

    return *this;
}

ostream &operator<<(ostream &os, Cadena &cad)
{
    os << cad.cad;

    return os;
}
