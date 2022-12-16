#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Lista_Simple.h"

#define SALIO_BIEN 1
#define SALIO_MAL 0
#define MENOR(X, Y) ((X)<(Y) ? (X) :(Y))

typedef struct
{
    char cod[6];
    char sector;
    int cant;
}t_prod;

void crear_arch_prueba();
int abrir_arch(FILE **pf, const char *nom_arch, const char *tipo_apert);

int cmp_prod(const void *dat_1, const void *dat_2);
void ver_prod(const void *dat);
void repetidos_prod(void *dat_1, const void *dat_2);
void grabar_prod(FILE *pf, const void *dat);
int grabar_lista_arch(t_lista *p, void grabar(FILE *pf, const void *dat));

#endif // FUNCIONES_H_INCLUDED
