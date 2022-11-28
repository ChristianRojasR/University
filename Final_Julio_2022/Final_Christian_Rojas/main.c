#include <stdio.h>
#include <stdlib.h>

#include "Cola.h"
#include "Functions.h"

int main()
{
    t_cola cola;
    FILE *pf;

    puts("creando archivo...");
    generateFileDatos();

    crearCola(&cola);
    openFile(&pf, "datos.csv", "rt");
    PonerEnColaArch(pf, &cola);

    return 0;
}
