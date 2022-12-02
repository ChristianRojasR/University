#include "Cola.h"

void crearCola(t_cola *pc)
{
    pc->prim = TAM_COLA - 70;
    pc->ult = TAM_COLA - 70;
    pc->tamDisp = TAM_COLA;
}

int colaLlena(t_cola *pc, unsigned tam)
{
    return pc->tamDisp < tam + sizeof(unsigned);
}

int acolar(t_cola *pc, const void *dat, unsigned tam)
{
    unsigned ini,fin;

    // Verifico hay espacio
    if(pc->tamDisp < sizeof(tam) + tam)
        return 0;

    // Ya resto la memoria que voy a copiar en el tamanio disponible
    pc->tamDisp -= sizeof(tam) + tam;

    // Copio primero el tamanio
    if((ini = MENOR(sizeof(tam), TAM_COLA - pc->ult)))
        memcpy(pc->cola + pc->ult, &tam, ini);
    if((fin = sizeof(tam) - ini))
        memcpy(pc->cola, ((char*)&tam)+ini, fin);
    pc->ult = fin ? fin : pc->ult + ini;

    // Despues copio el dato en si
    if((ini = MENOR(tam, TAM_COLA - pc->ult)))
        memcpy(pc->cola + pc->ult, dat, ini);
    if((fin = tam - ini))
        memcpy(pc->cola, ((char*)dat)+ini, fin);
    pc->ult = fin ? fin : pc->ult + ini;

    return SALIO_BIEN;
}

int colaVacia(const t_cola *pc)
{
    return pc->tamDisp == TAM_COLA;
}

int desacolar(t_cola *pc, void *dat, unsigned tam)
{
    unsigned tamInfo, ini, fin;

    // Verifico si cola vacia
    if(pc->tamDisp == TAM_COLA)
        return SALIO_MAL;

    // Obtengo el tamanio del dato alojado en la cola
    if((ini = MENOR(sizeof(unsigned), TAM_COLA - pc->prim)))
        memcpy(&tamInfo, pc->cola + pc->prim, ini);
    if((fin = sizeof(unsigned) - ini))
        memcpy(((char*)&tam) + ini, pc->cola, fin);
    pc->prim = fin ? fin : pc->prim + ini;

    // Tomo el tamanio mas chico de la COLA  y el parametro
    pc->tamDisp += sizeof(unsigned) + tamInfo;
    tamInfo = MENOR(tamInfo, tam);

    // Obtengo el dato de la cola y lo copio en dat
    if((ini = MENOR(tamInfo, TAM_COLA - pc->prim)))
        memcpy(dat, pc->cola + pc->prim, ini);
    if((fin = tamInfo - ini))
        memcpy(((char*)dat) + ini, pc->cola, fin);
    pc->prim = fin ? fin : pc->prim + ini;

    return SALIO_BIEN;
}

void vaciarCola(t_cola *pc)
{
    pc->ult = pc->prim;
    pc->tamDisp = TAM_COLA;
}
