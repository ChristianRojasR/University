#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define SALIO_BIEN 1
#define SALIO_MAL 0

typedef struct sNodo
{
    void *dat;
    unsigned tam;
    struct sNodo *sig;
}t_nodo;

typedef t_nodo *t_lista;

void crearLista(t_lista *pl);
int listaVacia(const t_lista *pl);
void vaciarLista(t_lista *pl);

#endif // LISTASIMPLE_H_INCLUDED
