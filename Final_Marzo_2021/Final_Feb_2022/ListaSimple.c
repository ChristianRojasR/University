#include "ListaSimple.h"
#include <string.h>

void crear_lista(t_lista *p)
{
    *p = NULL;
}

int cargar_lista(t_lista *p, const void *dat, unsigned tam)
{
    t_nodo *nue;

    if(!(nue = malloc(sizeof(t_nodo))))
        return SALIO_MAL;
    if(!(nue->dat = malloc(sizeof(tam))))
    {
        free(nue);
        return SALIO_MAL;
    }

    memcpy(nue->dat, dat, tam);
    nue->tam = tam;
    nue->sig = *p;

    *p = nue;

    return SALIO_BIEN;
}

int cargar_lista_prioridad(t_lista *p, const void *dat, unsigned tam, int comparacion(const void *dat1, const void *dat2))
{
    t_nodo *nue;

    while(*p && comparacion((*p)->dat, dat) < 0)
        p = &(*p)->sig;

    if(!(nue = malloc(sizeof(t_nodo))))
        return SALIO_MAL;
    if(!(nue->dat = malloc(sizeof(tam))))
    {
        free(nue);
        return SALIO_MAL;
    }

    memcpy(nue->dat, dat, tam);
    nue->tam = tam;
    nue->sig = *p;

    *p = nue;

    return SALIO_BIEN;
}

int sacar_lista(t_lista *p, void *dat, unsigned tam)
{
    t_nodo *aux = *p;

    if(aux == NULL)
        return SALIO_MAL;

    *p = aux->sig;

    memcpy(dat, aux->dat, MENOR(tam, aux->tam));

    free(aux->dat);
    free(aux);

    return SALIO_BIEN;
}

void ver_lista(const t_lista *p, void imprimir(const void *dat))
{
    while(*p)
    {
        imprimir((*p)->dat);
        p = &(*p)->sig;
    }
}

void imprimir_int(const void *dat)
{
    printf("%d ", *(int*)dat);
}
