#include "ListaSimple.h"

void crearLista(t_lista *pl)
{
    *pl = NULL;
}

int listaVacia(const t_lista *pl)
{
    return *pl == NULL;
}

void vaciarLista(t_lista *pl)
{
    while(*pl)
    {
        t_nodo *aux = *pl;

        *pl = aux->sig;
        free(aux->dat);
        free(aux);
    }
}
