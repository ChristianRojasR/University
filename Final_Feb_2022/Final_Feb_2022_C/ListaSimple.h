#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define SALIO_BIEN 1
#define SALIO_MAL 0

#define MENOR(X, Y) (X)<(Y)?(X):(Y)

typedef struct s_nodo
{
    void *dat;
    unsigned tam;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_lista;

void crear_lista(t_lista *p);
int cargar_lista(t_lista *p, const void *dat, unsigned tam);
int cargar_lista_prioridad(t_lista *p, const void *dat, unsigned tam,
                            int comparacion(const void *dat1, const void *dat2));
int sacar_lista(t_lista *p, void *dat, unsigned tam);

void ver_lista(const t_lista *p, void imprimir(const void *dat));
void imprimir_int(const void *dat);

#endif // LISTASIMPLE_H_INCLUDED
