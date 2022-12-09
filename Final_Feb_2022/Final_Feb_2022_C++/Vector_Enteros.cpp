#include "Vector_Enteros.h"

VectorEnteros::VectorEnteros()
{
    this->vec = new int[1];
    this->vec[0]=0;
    this->tam = 1;
}

VectorEnteros::VectorEnteros(int* v, int t)
{
    //this->vec = new int[tam];
    this->vec = v;
    this->tam = t;
}

VectorEnteros::VectorEnteros(VectorEnteros &nue)
{
    this->vec = nue.vec;
    this->tam = nue.tam;
}

VectorEnteros::~VectorEnteros()
{
    delete [] this->vec;
}

ostream& operator<< (ostream &os, VectorEnteros &obj)
{
    os << "[";
    if(obj.tam == 1)
        os << obj.vec[0];
    else
    {
        for(int i=0; i<obj.tam-1 ; i++)
            os << obj.vec[i] << ", ";
        os << obj.vec[obj.tam-1];
    }
    os << "]";
    return os;
}

VectorEnteros& VectorEnteros::agregar(int *v, int t)
{
    this->vec = v;
    this->tam = t;
    return *this;
}

VectorEnteros& VectorEnteros::operator+(VectorEnteros& v)
{
    // Creo nuevas variables para no perder la info de this
    int nue_tam = this->tam + v.tam;
    int *nue_vec = new int[nue_tam];

    // Asigno primero this y luego el que se suma, en nue_vec
    for(int i=0; i<this->tam; i++)
        nue_vec[i] = this->vec[i];
    for(int i=this->tam; i<nue_tam; i++)
        nue_vec[i] = v.vec[i-this->tam];

    // Le asigno los nuevos valores a this y lo retorno
    this->tam = nue_tam;
    this->vec = nue_vec;
    return *this;
}

VectorEnteros& VectorEnteros::operator+(int val)
{
    int *nue_vec = new int[this->tam+1];
    for(int i=0; i<this->tam; i++)
        nue_vec[i] = this->vec[i];
    nue_vec[this->tam++] = val; // Uso el pos incremento por lo que no asigno nue_tam a tam
    this->vec = nue_vec;
    return *this;
}

VectorEnteros& VectorEnteros::operator=(VectorEnteros& v)
{
    this->vec = v.vec;
    this->tam = v.tam;
    return *this;
}
