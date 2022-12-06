#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include "ListaSimple.h"

typedef struct
{
    unsigned fil,
             col;
    int dat;
}t_matriz;

void imprimir_mat(const void *dat);
int comparacion_mat(const void *dat1, const void *dat2);

#endif // MATRIZ_H_INCLUDED
