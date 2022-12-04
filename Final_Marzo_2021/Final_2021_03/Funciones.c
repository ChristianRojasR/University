#include "Funciones.h"

void crearArchPrueba()
{
    FILE *fText;
    char *text = "Es mas, es la hora de ir de paseo, cerca, a la playa.";

    if(!abrirArch(&fText, "Archivo_Prueba.txt", "wt"))
        return;

    fprintf(fText, "%s\n", text);

    fclose(fText);
}

int abrirArch(FILE **pf, const char *nombreArch, const char* tipoApertura)
{
    if(!(*pf = fopen(nombreArch, tipoApertura)))
        return SALIO_MAL;
    return SALIO_BIEN;
}

int resolver(FILE *pf, t_lista *pl)
{
    char linea[200];

    if(!fgets(linea, 200, pf))
        return SALIO_MAL;

    printf("%s", linea);

    return SALIO_BIEN;
}
