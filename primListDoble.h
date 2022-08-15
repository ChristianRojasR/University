#ifndef PRIMLISTDOBLE_H_INCLUDED
#define PRIMLISTDOBLE_H_INCLUDED

///Rojas Rodriguez_Christian Rodrigo_43181120
#include <stdio.h>
#include <stdlib.h>
#define SALIO_MAL 0;
#define SALIO_BIEN 1;

typedef struct sNodo
{
    void *dat;
    unsigned tam;
    struct sNodo *sig,
                 *ant;
}tNodo;

typedef tNodo *tLista;


void crearList(tLista *pl);

int insertAlInicio(tLista *pl, const void *dat, unsigned tam);

int ordenarList(tLista *pl, const void *dat, unsigned tam, int compare(const void *dat1, const void *dat2));
int compare(const void *dat1, const void *dat2);


#endif // PRIMLISTDOBLE_H_INCLUDED
