#include "Cadena.h"
#include "string.h"

Cadena::Cadena()
{
    cad = new char[10];
    tam = 10;
    cad[0] = '\0';
}

Cadena::Cadena(const char* s)
{
    tam = strlen(s);
    cad = new char[tam + 1];
    strcpy(cad, s);
}

Cadena::~Cadena()
{
    delete []cad;
}

Cadena &Cadena::operator+(const char *s)
{
    char *newCadena = cad;
    tam += strlen(s);
    cad = new char[tam+1];
    strcpy(cad, newCadena);
    strcpy(cad+strlen(s)-1, s);
    delete []newCadena;

    return *this;
}

//const Cadena &Cadena::operator=(const char* s)
//{
//
//    delete []cad;
//    tam = strlen(s);
//    cad = new char[tam + 1];
//    strcpy(cad, s);
//    return *this;
//}

const Cadena &Cadena::operator=(const Cadena &s)
{
    if(&s != this)
    {
        delete [] cad;
        tam = s.tam;
        cad = new char[tam + 1];
        strcpy(cad, s.cad);
    }
    return *this;
}

ostream &operator<<(ostream &os, const Cadena &cad)
{
    os << cad.cad;

    return os;
}
