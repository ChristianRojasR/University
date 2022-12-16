#include "Lista_Simple.h"
#include <string.h>

void crear_lista(t_lista *p)
{
    *p = NULL;
}

int cargar_lista_sin_repetidos(t_lista *p, const void *dat, unsigned tam,
                            int cmp(const void *dat_1, const void *dat_2),
                            void procesar_repetidos(void *dat_1, const void *dat_2))
{
    while(*p && cmp((*p)->dat, dat) != 0)
        p = &(*p)->sig;

    if(*p)
    {
        procesar_repetidos((*p)->dat, dat);
        return SALIO_BIEN;
    }

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
    nue->sig = *p;

    *p = nue;
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

int sacar_lista(t_lista *p, void *dat, unsigned tam)
{
    if(!*p)
        return SALIO_MAL;

    t_nodo *elim = *p;
    memcpy(dat, elim->dat, MENOR(tam, elim->tam));

    *p = elim->sig;

    free(elim->dat);
    free(elim);
    return SALIO_BIEN;
}
