#include "Functions.h"

void generateFileDatos()
{
    int i;
    FILE *fDatos;
    t_alumno vDatos [] = {{11111, "prueba", "01", 4.0},
                          {22222, "prueba", "02", 7.0},
                          {33333, "prueba", "03", 10.0}};

    if(!openFile(&fDatos, "datos.csv", "wt"))
        return;

    for(i=0; i<3; i++)
        fprintf(fDatos, "%d-%s-%s-%f\n", vDatos[i].dni, vDatos[i].ape,
                                         vDatos[i].nombre, vDatos[i].promedio);

    fclose(fDatos);
}

int openFile(FILE **pf, char *name, char *typeOpen)
{
    if(!(*pf = fopen(name, typeOpen)))
        return SALIO_MAL;

    return SALIO_BIEN;
}

int PonerEnColaArch(FILE *pf, t_cola *pc)
{
    t_alumno al;

    while(fscanf(pf, "%d-%s-%s-%f\n", &(al.dni), al.ape,
                                      al.nombre, &(al.promedio)))
    {
        acolar(pc, &al, sizeof(t_alumno));
    }

    return SALIO_BIEN;
}
