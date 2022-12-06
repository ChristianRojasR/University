#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define SALIO_BIEN 1
#define SALIO_MAL 0
#define SON_IGUALES 0
#define ES_MAYOR 1
#define ES_MENOR -1

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
int ponerEnLista(t_lista *pl, const void *dat, unsigned tam, int comparacion(const void *dat1, const void *dat2));
int compararString(const void *dat1, const void *dat2);
void verLista(const t_lista *pl, void imprimir(const void *dat));
void imprimirString(const void *dat);

#endif // LISTASIMPLE_H_INCLUDED
