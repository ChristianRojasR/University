#include "Llamada.h"
#include <string.h>
#include <stdexcept>

Llamada::Llamada(const char *orig, const char *dest, int seg)
{
    this->origen = new char[strlen(orig+1)];
    strcpy(this->origen, orig);
    this->destino = new char[strlen(dest+1)];
    strcpy(this->destino, dest);
    this->segundos = seg;
}

Llamada::Llamada(Llamada& obj)
{
    this->origen = new char[strlen(obj.origen+1)];
    strcpy(this->origen, obj.origen);
    this->destino = new char[strlen(obj.destino+1)];
    strcpy(this->destino, obj.destino);
    this->segundos = obj.segundos;
}

Llamada::~Llamada()
{
    delete [] this->origen;
    delete [] this->destino;
}

ostream& operator<<(ostream &os, Llamada &obj)
{
    os << "( " << obj.origen
       << ", " << obj.destino
       << ", " << obj.segundos << ")";
    return os;
}

Llamada& Llamada::operator+(Llamada& obj)
{
    if(strcmp(this->origen, obj.origen) != 0)
        throw exception();
    //Llamada nue (*this);
    //nue.segundos = this->segundos + obj.segundos;
    this->segundos += obj.segundos;
    return *this;
}

Llamada& Llamada::operator+(int val)
{
    this->segundos += val;
    return *this;
}
