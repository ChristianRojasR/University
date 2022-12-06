#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

#define SALIO_BIEN 1
#define SALIO_MAL 0
#define ES_LETRA(X) ((X)>='a' && (X)<='z') || ((X)>='A' && (X)<='Z') ? 1 : 0
#define ES_ESPACIO(X) ((X)==' ') ? 1 : 0
#define ES_COMA(X) ((X)==',') ? 1 : 0

void crearArchPrueba();
int abrirArch(FILE **pf, const char *nombreArch, const char* tipoApertura);
int resolver(FILE *pf, t_lista *pl);
void cargarLista(char *s, t_lista *pl);

#endif // FUNCIONES_H_INCLUDED
