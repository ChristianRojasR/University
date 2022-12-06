#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    FILE *pf;
    t_lista lista;

    puts("--------Inicio-----------");
    crearArchPrueba();

    if(!abrirArch(&pf, "Archivo_Prueba.txt", "rt"))
        return SALIO_MAL;
    crearLista(&lista);
    resolver(pf, &lista);
    verLista(&lista, imprimirString);

    return 0;
}
