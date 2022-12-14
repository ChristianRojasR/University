#ifndef LLAMADA_H
#define LLAMADA_H

#include <iostream>
#include <string.h>
using namespace std;

class Llamada
{
    friend ostream& operator<<(ostream &os, const Llamada &obj);

    public:
        Llamada(const char *orig, const char *dest, int seg);
        Llamada(const Llamada &obj);
        ~Llamada();
        Llamada operator+(const Llamada &obj);
        Llamada operator+(const int val);

    private:
        char *origen;
        char *destino;
        int segundos;
};

#endif // LLAMADA_H
