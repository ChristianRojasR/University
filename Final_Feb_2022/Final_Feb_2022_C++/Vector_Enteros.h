#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <iostream>

using namespace std;

class VectorEnteros
{
    friend ostream& operator<< (ostream &os, VectorEnteros &obj);
    public:
        VectorEnteros();
        VectorEnteros(int* v, int t);
        VectorEnteros(VectorEnteros &nue);
        ~VectorEnteros();
        VectorEnteros& agregar(int *v, int t);
        VectorEnteros& operator+(VectorEnteros& v);
        VectorEnteros& operator+(int val);
        VectorEnteros& operator=(VectorEnteros& v);

    private:
        int *vec;
        int tam;
};

#endif // VECTOR_ENTEROS_H
