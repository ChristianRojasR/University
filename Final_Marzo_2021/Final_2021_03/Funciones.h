#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

#define SALIO_BIEN 1
#define SALIO_MAL 0

void crearArchPrueba();
int abrirArch(FILE **pf, const char *nombreArch, const char* tipoApertura);
int resolver(FILE *pf, t_lista *pl);

#endif // FUNCIONES_H_INCLUDED
