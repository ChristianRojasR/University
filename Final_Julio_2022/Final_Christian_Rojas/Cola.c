#include "Cola.h"

void crearCola(t_cola *pc)
{
    pc->prim = pc->cola;
    pc->ult = pc->cola;
    pc->tam = sizeof(pc->cola);
}

int acolar(t_cola *pc, const void *dat, unsigned tam)
{
    if(tam > pc->tam)
        return SALIO_MAL;

    pc->tam -= (tam + sizeof(unsigned));

    memcpy(pc->ult, dat, tam);

    pc->ult += tam;

    memcpy(pc->ult, &tam, sizeof(unsigned));

    pc->ult += sizeof(unsigned);

    return SALIO_BIEN;
}

int desacolar(t_cola *pc, void *dat, unsigned tam)
{
    if(tam == 0)
        return SALIO_MAL;

    pc->ult -= sizeof(unsigned);



    return SALIO_BIEN;
}

void verPrimero(const t_cola *pc, void *dat, unsigned tam)
{

}

void verUltimo(const t_cola *pc, void *dat, unsigned tam)
{

}

void eliminarCola(t_cola *pc)
{
    free(pc->cola);
    pc->prim = NULL;
    pc->ult = NULL;
    pc = NULL;
}

int hayCola(const t_cola *pc)
{
    return pc->prim != pc->ult;
}
