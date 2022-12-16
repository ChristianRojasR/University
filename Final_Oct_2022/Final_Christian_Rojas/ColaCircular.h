#ifndef COLACIRCULAR_H_INCLUDED
#define COLACIRCULAR_H_INCLUDED

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define SALIO_BIEN 1
#define SALIO_MAL 0
#define MENOR(X, Y) (X)<(Y) ? (X) : (Y)

typedef struct sNodo
{
    void *dat;
    unsigned tam;
    struct sNodo *sig;
}t_nodo;

typedef t_nodo *t_cola;

void crearCola(t_cola *pc);
int colaLlena(t_cola *pc, unsigned tam);
int acolar(t_cola *pc, const void *dat, unsigned tam);
int desacolar(t_cola *pc, void *dat, unsigned tam);
int colaVacia(const t_cola *pc);
void vaciarCola(t_cola *pc);
int verPrimero(const t_cola *pc, void *dat, unsigned tam);

#endif // COLACIRCULAR_H_INCLUDED
