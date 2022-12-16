#ifndef CADENA_H
#define CADENA_H

#include "iostream"
using namespace std;

class Cadena
{
    friend ostream &operator<<(ostream &os, const Cadena &cad);
public:
        Cadena();
        Cadena(const char* s);
        ~Cadena();
        Cadena &operator+(const char *cad);
//        const Cadena &operator=(const char* s);
        const Cadena &operator=(const Cadena &cad);

    private:
        char *cad;
        int tam;
};

#endif // CADENA_H
