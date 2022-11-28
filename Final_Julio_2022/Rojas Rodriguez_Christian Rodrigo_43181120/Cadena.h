#ifndef CADENA_H
#define CADENA_H

#include "iostream"
using namespace std;

class Cadena
{
    friend ostream &operator<<(ostream &os, Cadena &cad);
public:
        Cadena();
        Cadena &operator+(char *cad);
        Cadena &operator=(const char *s);
        Cadena &operator=(Cadena &cad);

    private:
        char *cad;
};

#endif // CADENA_H
