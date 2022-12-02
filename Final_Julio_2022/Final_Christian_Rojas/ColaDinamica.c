#include "ColaDinamica.h"
#include "stdio.h"

void crearCola(t_cola *pc)
{
    pc->pri = NULL;
    pc->ult = NULL;
}

int colaLlena(t_cola *pc, unsigned tam)
{
    t_nodo *aux = malloc(sizeof(t_nodo));
    void *info = malloc(tam);
    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int acolar(t_cola *pc, const void *dat, unsigned tam);
int desacolar(t_cola *pc, void *dat, unsigned tam);
int colaVacia(const t_cola *pc);
void vaciarCola(t_cola *pc);
