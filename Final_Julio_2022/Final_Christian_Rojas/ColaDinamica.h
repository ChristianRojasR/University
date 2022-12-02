#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

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

typedef struct
{
    t_nodo *pri,
           *ult;
}t_cola;

void crearCola(t_cola *pc);
int colaLlena(t_cola *pc, unsigned tam);
int acolar(t_cola *pc, const void *dat, unsigned tam);
int desacolar(t_cola *pc, void *dat, unsigned tam);
int colaVacia(const t_cola *pc);
void vaciarCola(t_cola *pc);

#endif // COLADINAMICA_H_INCLUDED
