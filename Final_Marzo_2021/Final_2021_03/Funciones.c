#include "Funciones.h"
#include <string.h>

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

    cargarLista(linea, pl);

    return SALIO_BIEN;
}

void cargarLista(char *s, t_lista *pl)
{
    char *aux = s+1;
    int band = 0;

    // uso un while con es_letra para ir contando y luego cuando deje de serlo guardo la palabra
    while(*aux)
    {
        if(!ES_LETRA(*aux))
        {
            if(ES_LETRA(*(aux+1)))
            {
                if(band)
                {
                    *(aux-1) = '\0';
                    band = 0;
                }
                else
                    *aux = '\0';
                ponerEnLista(pl, s, sizeof(*s), compararString);
                s=aux+1;
            }
            else
                band =1;
        }
        aux++;
    }
}
