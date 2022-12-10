#ifndef LLAMADA_H
#define LLAMADA_H

#include <iostream>
#include <string.h>
using namespace std;

class Llamada
{
    friend ostream& operator<<(ostream &os, Llamada &obj);
    public:
        Llamada(const char *orig, const char *dest, int seg);
        Llamada(Llamada& obj);
        ~Llamada();
        Llamada& operator+(Llamada& obj);
        Llamada& operator+(int val);

    private:
        char *origen;
        char *destino;
        int segundos;
};

#endif // LLAMADA_H
