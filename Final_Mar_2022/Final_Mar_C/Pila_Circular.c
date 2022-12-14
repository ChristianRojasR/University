#include "Pila_Circular.h"
#include <string.h>

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
    if(!(nue->dat = malloc(tam)))
    {
        free(nue);
        return SALIO_MAL;
    }

    memcpy(nue->dat, dat, tam);
    nue->tam = tam;

    if(!*p)
    {
        nue->sig = nue;
        *p = nue;
    }
    else
    {
        nue->sig = (*p)->sig;
        (*p)->sig = nue;
    }

    return SALIO_BIEN;
}

int ver_tope(const t_pila *p, void *dat, unsigned tam)
{
    if(*p == NULL)
        return SALIO_MAL;
    memcpy(dat, (*p)->sig->dat, MINIMO(tam, (*p)->sig->tam));
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
        t_nodo *aux = (*p)->sig;

        if(*p == aux)
            *p = NULL;
        else
            (*p)->sig = aux->sig;

        free(aux->dat);
        free(aux);
    }
}

int sacar_pila(t_pila *p, void *dat, unsigned tam)
{
    t_nodo *aux;

    if(!*p)
        return SALIO_MAL;
    aux = (*p)->sig;

    memcpy(dat, aux->dat, MINIMO(tam, aux->tam));
    if(aux == *p)
        *p = NULL;
    else
        (*p)->sig = aux->sig;

    free(aux->dat);
    free(aux);
    return SALIO_BIEN;
}
