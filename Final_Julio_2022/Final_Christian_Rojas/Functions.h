#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"
#include "Cola.h"

#define SALIO_BIEN 1
#define SALIO_MAL 0

typedef struct
{
    int dni;
    char ape[21];
    char nombre[21];
    float promedio;
}t_alumno;

void generateFileDatos();
int openFile(FILE **pf, char *name, char *typeOpen);
int PonerEnColaArch(FILE *pf, t_cola *pc);

#endif // FUNCTIONS_H_INCLUDED
