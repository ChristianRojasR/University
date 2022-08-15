#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED

///Rojas Rodriguez_Christian Rodrigo_43181120
#include <stdio.h>
#include <stdlib.h>

#define SALIO_MAL 0;
#define SALIO_BIEN 1;
#define ERROR_1 1;
#define ERROR_2 2
#define ERROR_3 3
#define ERROR_4 4

typedef struct
{
    int a,
        m,
        d;

}tFecha;

typedef struct
{
    char patente[8];
    int nroCuota;
    char titular[21];
    int dni;
    tFecha vto;
    float importeMax;

}tImpuesto;

int casePrueb();
int abrirArch(FILE **pf, const char *nombre, const char *moodOpen);

int validarArchivo(FILE *pf);
int verificarNombre(char *nombre);
int verificaPatente(char *patente);
int verificaNroCuota(int nCuota);


#endif // PARCIAL_H_INCLUDED
