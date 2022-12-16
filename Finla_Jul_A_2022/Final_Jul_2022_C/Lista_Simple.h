#ifndef LISTA_SIMPLE_H_INCLUDED
#define LISTA_SIMPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define SALIO_BIEN 1
#define SALIO_MAL 0
#define MENOR(X, Y) ((X)<(Y) ? (X) :(Y))

typedef struct s_nodo
{
    void *dat;
    unsigned tam;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_lista;

void crear_lista(t_lista *p);
int cargar_lista_sin_repetidos(t_lista *p, const void *dat, unsigned tam,
                            int cmp(const void *dat_1, const void *dat_2),
                            void procesar_repetidos(void *dat_1, const void *dat_2));
void ver_lista(const t_lista *p, void imprimir(const void *dat));
int sacar_lista(t_lista *p, void *dat, unsigned tam);

#endif // LISTA_SIMPLE_H_INCLUDED
