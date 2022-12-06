#include "ListaSimple.h"
#include <string.h>

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

int ponerEnLista(t_lista *pl, const void *dat, unsigned tam, int comparacion(const void *dat1, const void *dat2))
{
    t_nodo *nue;

    if(!(nue = malloc(sizeof(t_nodo))))
        return SALIO_MAL;
    if(!(nue->dat = malloc(tam)))
    {
        free(nue);
        return SALIO_MAL;
    }

    // Verifico si existe la lista, sino comparo string con NULL
    while(*pl && comparacion(dat, (*pl)->dat) != ES_MAYOR)
        pl = &(*pl)->sig;

    memcpy(nue->dat, dat, tam);
    nue->tam = tam;

    if(*pl)
        nue->sig = *pl;
    else
        nue->sig = NULL;

    *pl = nue;

    return SALIO_BIEN;
}

int compararLetras(const void *dat1, const void *dat2)
{
    // Resto los char con la asignacion en ASCII
    return *(char*)dat1 - *(char*)dat1;
}

int compararString(const void *dat1, const void *dat2)
{
    int comp,
        tam1 = strlen((char*)dat1),
        tam2 = strlen((char*)dat2);

    // Verifico si tienen el mismo tamanio, si es asi tiene orden alfabetico
    if(tam1 == tam2)
    {
        while((char*)dat1 && (char*)dat2)
        {
            if((comp=compararLetras(dat1, dat2)))
                return comp;
            (char*)dat1++;
            (char*)dat2++;
        }
    }
    // En caso contrario entran a la lista por tamanio
    return tam1 > tam2 ? ES_MAYOR : ES_MENOR;
}

void verLista(const t_lista *pl, void imprimir(const void *dat))
{
    while(*pl)
    {
        imprimir(*pl);
        pl = &(*pl)->sig;
    }
}

void imprimirString(const void *dat)
{
    printf("%s\n", (char*)dat);
}
