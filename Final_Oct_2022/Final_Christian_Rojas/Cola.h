#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define SALIO_BIEN 1
#define SALIO_MAL 0
#define TAM_COLA 300
#define MENOR(X,Y) ((X)<(Y))?(X):(Y)

typedef struct
{
    char cola[300];
    unsigned tamDisp,
             prim,
             ult;
}t_cola;

void crearCola(t_cola *pc);
int colaLlena(t_cola *pc, unsigned tam);
int acolar(t_cola *pc, const void *dat, unsigned tam);
int desacolar(t_cola *pc, void *dat, unsigned tam);
int colaVacia(const t_cola *pc);
void vaciarCola(t_cola *pc);

#endif // COLA_H_INCLUDED
