#include "myFun.h"
#include "tipos.h"
#include <stdlib.h>
#include <string.h>

void newList(tList *pl)
{
    *pl = NULL;
}

// all functions are recursive
int rInsertNoDuplicate(tList *pl, const void *dat, unsigned tam, int compare(const void *dat1, const void *dat2))
{
    tNodo *newNodo;

    if(*pl)
    {
        if(!compare(dat, (*pl)->dat))
            return ERROR_DUPLICATE;

        return rInsertNoDuplicate(&(*pl)->sig, dat, tam, compare); //loop to null

        if(!(newNodo = malloc(sizeof(tNodo))))
            return ERROR_MEM;

        if(!(newNodo->dat = malloc(tam)))
        {
            free(newNodo);
            return ERROR_MEM;
        }

        memcpy(newNodo->dat, dat, tam);
        newNodo->tam = tam;
        newNodo->sig = NULL;

        (*pl)->sig = newNodo;
    }

    return WENT_GOOD;
}

int cmpIntAndOut(const void *dat1, const void *dat2)
{
    int cmp;

    if((cmp = strcmp(((tentradaSalida*)dat1)->dominio, ((tentradaSalida*)dat2)->dominio)) == 0)
        return ((tentradaSalida*)dat1)->sector - ((tentradaSalida*)dat2)->sector;

    return cmp;
}

int rCountByClass(const tList *pl, const void *dat, int compare(const void *dat1, const void *dat2))
{
    if(*pl)
    {
        if(!compare((*pl)->dat, dat))
            return rCountByClass(&(*pl)->sig, dat, compare) + 1;
        else
            return rCountByClass(&(*pl)->sig, dat, compare);
    }

    return 0;
}

int cmpByClass(const void *dat1, const void *dat2)
{
    return ((tentradaSalida*)dat1)->sector - ((tentradaSalida*)dat2)->sector;
}

int rSearch(const tList *pl, const void *dat, int compare(const void *dat1, const void *dat2))
{
    if(*pl)
    {
        if(!(compare((*pl)->dat, dat)))
            return rSearch(&(*pl)->sig, dat, compare);

        return WENT_GOOD;
    }

    return WENT_WRONG;
}

int rDelete(tList *pl, void *dat, unsigned tam);
int rRemoveFirst(tList *pl, void *dat, unsigned tam);
