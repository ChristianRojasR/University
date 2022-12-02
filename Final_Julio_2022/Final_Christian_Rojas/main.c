#include <stdio.h>
#include <stdlib.h>

#include "Cola.h"
#include "Functions.h"

int main()
{
    t_cola cola;
    FILE *pf;

    puts("\n--------Inicio la prueba-----------\n");
    generateFileDatos();

    crearCola(&cola);
    openFile(&pf, "datos.csv", "rt");
    ponerEnColaArch(pf, &cola);
    sacarDeColaYMostrar(&cola, imprimirAlumno);
    vaciarCola(&cola);
    if(colaVacia(&cola))
        puts("\n--------Termino la prueba-----------\n");

    return 0;
}
