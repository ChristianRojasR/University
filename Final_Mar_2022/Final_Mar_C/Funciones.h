#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Pila_Dinamica.h"

typedef struct
{
    int num_pila,
        val;
}t_dat;

void crear_arch_prueba();
int abrir_arch(FILE **pf, const char *nom_arch, const char *t_apert);
int trabajar_pilas(FILE *pf, t_pila v[], const int tam);
int cierre_normal(const char *nom_arch, t_pila *p, const int *num_pila);

#endif // FUNCIONES_H_INCLUDED
