#include <string.h>
#include "Pila_Estatica.h"

void crear_pila(t_pila *p)
{
    p->tope = TAM_PILA;
}

int pila_llena(const t_pila *p, unsigned tam)
{
    return p->tope < tam + sizeof(unsigned);
}

int poner_pila(t_pila *p, const void *dat, unsigned tam)
{
    if(p->tope < tam+sizeof(unsigned))
        return SALIO_MAL;

    p->tope -= tam;
    memcpy(p->pila + p->tope, dat, tam);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &tam, sizeof(unsigned));

    return SALIO_BIEN;
}

int ver_tope(const t_pila *p, void *dat, unsigned tam)
{
    unsigned tam_info;

    if(p->tope == TAM_PILA)
        return SALIO_MAL;

    memcpy(&tam_info, p->pila + p->tope, sizeof(unsigned));
    memcpy(dat, p->pila + p->tope + sizeof(unsigned), MINIMO(tam, tam_info));

    return SALIO_BIEN;
}

int pila_vacia(const t_pila *p)
{
    return p->tope == TAM_PILA;
}

void vaciar_pila(t_pila *p)
{
    p->tope = TAM_PILA;
}

int sacar_pila(t_pila *p, void *dat, unsigned tam)
{
    unsigned tam_info;

    if(p->tope == TAM_PILA)
        return SALIO_MAL;

    memcpy(&tam_info, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(dat, p->pila + p->tope, MINIMO(tam, tam_info));
    p->tope += tam_info;

    return SALIO_BIEN;
}
