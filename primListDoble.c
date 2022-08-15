///Rojas Rodriguez_Christian Rodrigo_43181120
#include "primListDoble.h"
#include <string.h>

void crearList(tLista *pl)
{
    *pl = NULL;
}

int insertAlInicio(tLista *pl, const void *dat, unsigned tam)
{
    tNodo *nue;


    if(!(nue = malloc(sizeof(tNodo))))
        return SALIO_MAL;

    if(!(nue->dat = malloc(tam)))
        return SALIO_MAL;

    nue->sig = NULL;
    nue->ant = NULL;
    memcpy(nue->dat, dat, tam);
    nue->tam = tam;

    if(!*pl)
        *pl = nue;
    else
    {
        (*pl)->ant = nue;
        nue->sig = (*pl);
        *pl = nue;
    }

    return SALIO_BIEN;
}

int ordenarList(tLista *pl, const void *dat, unsigned tam, int compare(const void *dat1, const void *dat2));
int compare(const void *dat1, const void *dat2);
