// Pila.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SALIO_BIEN 1
#define SALIO_MAL 0
#define MINIMO(X, Y) (X)<(Y) ? (X) : (Y)

typedef struct s_nodo
{
    void *dat;
    unsigned tam;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_pila;

// Pila.c
void crear_pila(t_pila *p)
{
    *p = NULL;
}

int pila_llena(const t_pila *p, unsigned tam)
{
    return SALIO_MAL;
}

int poner_pila(t_pila *p, const void *dat, unsigned tam)
{
    t_nodo *nue;

    if(!(nue = malloc(sizeof(t_nodo))))
        return SALIO_MAL;
    if(!(nue->sig = malloc(sizeof(tam))))
    {
        free(nue);
        return SALIO_MAL;
    }

    memcpy(nue->sig, dat, tam);
    nue->tam = tam;
    nue->sig = *p;

    *p = nue;
    return SALIO_BIEN;
}

int ver_tope(const t_pila *p, void *dat, unsigned tam)
{
    if(!*p)
        return SALIO_MAL;
    memcpy(dat, (*p)->dat, MINIMO(tam, (*p)->tam));
    return SALIO_BIEN;
}

int pila_vacia(const t_pila *p)
{
    return *p == NULL;
}

void vaciar_pila(t_pila *p)
{
    while(*p)
    {
        t_nodo *aux = *p;

        *p = aux->sig;
        free(aux->dat);
        free(aux);
    }
}

int sacar_pila(t_pila *p, void *dat, unsigned tam)
{
    t_nodo *aux = *p;

    if(aux == NULL)
        return SALIO_MAL;
    
    *p = aux->sig;
    memcpy(dat, aux->dat, MINIMO(tam, aux->tam));

    free(aux->dat);
    free(aux);
    return SALIO_BIEN;
}