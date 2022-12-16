#include "ColaCircular.h"
#include <string.h>

void crearCola(t_cola *pc)
{
    *pc = NULL;
}

int colaLlena(t_cola *pc, unsigned tam)
{
    return SALIO_MAL;
}

int acolar(t_cola *pc, const void *dat, unsigned tam)
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

    if(!(*pc))
        nue->sig = nue;
    else
    {
        nue->sig = (*pc)->sig;
        (*pc)->sig = nue;
    }
    *pc = nue;

    return SALIO_BIEN;
}

int desacolar(t_cola *pc, void *dat, unsigned tam)
{
    t_nodo *aux;

    if(!(*pc))
        return SALIO_MAL;

    aux = (*pc)->sig;
    memcpy(dat, aux->dat, MENOR(aux->tam, tam));

    if(aux == *pc)
        *pc = NULL;
    else
        (*pc)->sig = aux->sig;

    free(aux->dat);
    free(aux);

    return SALIO_BIEN;
}

int colaVacia(const t_cola *pc)
{
    return *pc == NULL;
}

void vaciarCola(t_cola *pc)
{
    if(!(*pc))
        return;

    t_nodo *aux = (*pc)->sig;

    while(*pc)
    {
        if(*pc == aux)
            *pc = NULL;
        else
            (*pc)->sig = aux->sig;

        free(aux->dat);
        free(aux);
    }
}

int verPrimero(const t_cola *pc, void *dat, unsigned tam)
{
    if(!(*pc))
        return SALIO_MAL;

    memcpy(dat, (*pc)->sig->dat, MENOR(tam, (*pc)->sig->tam));
    return SALIO_BIEN;
}
