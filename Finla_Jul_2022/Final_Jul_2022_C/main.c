#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Lista_Simple.h"

int main()
{
    crear_arch_prueba();

    FILE *pf;
    if(!abrir_arch(&pf, "prueba.bin", "rb"))
        return SALIO_MAL;

    t_lista lista;
    crear_lista(&lista);
    t_prod aux;
    fread(&aux, sizeof(t_prod), 1, pf);
    while(!feof(pf))
    {
        cargar_lista_sin_repetidos(&lista, &aux, sizeof(aux), cmp_prod, repetidos_prod);
        fread(&aux, sizeof(t_prod), 1, pf);
    }
    fclose(pf);
    ver_lista(&lista, ver_prod);

    grabar_lista_arch(&lista, grabar_prod);
    return 0;
}
