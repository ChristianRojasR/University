#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define SALIO_BIEN 1
#define SALIO_MAL 0

typedef struct
{
    char cola[100];
    unsigned tam;
    void *prim;
    void *ult;
}t_cola;

void crearCola(t_cola *pc);
int acolar(t_cola *pc, const void *dat, unsigned tam);
int desacolar(t_cola *pc, void *dat, unsigned tam);
void verPrimero(const t_cola *pc, void *dat, unsigned tam);
void verUltimo(const t_cola *pc, void *dat, unsigned tam);
void eliminarCola(t_cola *pc);
int hayCola(const t_cola *pc);

#endif // COLA_H_INCLUDED
