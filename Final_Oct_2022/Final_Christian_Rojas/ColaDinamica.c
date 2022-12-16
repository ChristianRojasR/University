#include "ColaDinamica.h"
#include <string.h>

void crearCola(t_cola *pc)
{
    pc->pri = NULL;
    pc->ult = NULL;
}

int colaLlena(t_cola *pc, unsigned tam)
{
    return SALIO_MAL;
}

int acolar(t_cola *pc, const void *dat, unsigned tam)
{
    t_nodo *nue;

    // Guardo la memoria
    if(!(nue = malloc(sizeof(t_nodo))))
        return SALIO_MAL;
    if(!(nue->dat = malloc(sizeof(tam))))
    {
        free(nue);
        return SALIO_MAL;
    }

    // Copio el dato y el tamanio
    memcpy(nue->dat, dat, tam);
    nue->tam = tam;
    nue->sig = NULL;

    // Ubico mi nuevo dependiendo del caso
    if(pc->ult)
        pc->ult->sig = nue;
    else
        pc->pri = nue;

    // El nuevo es el nuevo ultimo
    pc->ult = nue;

    return SALIO_BIEN;
}
int desacolar(t_cola *pc, void *dat, unsigned tam)
{
    t_nodo *aux = pc->pri;

    // Reservamos la memoria
    if(aux == NULL)
        return SALIO_MAL;

    // Asigno el nuevo primero
    pc->pri = aux->sig;
    // Recupero el dato
    memcpy(dat, aux->dat, MENOR(aux->tam, tam));
    // Libero la memoria
    free(aux->dat);
    free(aux);

    // Si la cola queda vacia...
    if(pc->pri == NULL)
        pc->ult = NULL;

    return SALIO_BIEN;
}
int colaVacia(const t_cola *pc)
{
    return pc->pri == NULL;
}
void vaciarCola(t_cola *pc)
{
    while(pc->pri)
    {
        t_nodo *aux = pc->pri;
        pc->pri = aux->sig;
        free(aux->dat);
        free(aux);
    }
    pc->ult = NULL;
}
