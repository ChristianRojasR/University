#include "Functions.h"
#include "string.h"

void generateFileDatos()
{
    int i;
    FILE *fDatos;
    t_alumno vDatos [] = {{11111, "prueba", "uno", 4.0},
                          {22222, "prueba", "dos", 7.0},
                          {33333, "prueba", "tres", 10.0}};

    if(!openFile(&fDatos, "datos.csv", "wt"))
        return;

    for(i=0; i<3; i++)
        fprintf(fDatos, "%d;%s;%s;%.2f\n", vDatos[i].dni, vDatos[i].ape,
                                         vDatos[i].nombre, vDatos[i].promedio);

    fclose(fDatos);
}

int openFile(FILE **pf, char *name, char *typeOpen)
{
    if(!(*pf = fopen(name, typeOpen)))
        return SALIO_MAL;

    return SALIO_BIEN;
}

int ponerEnColaArch(FILE *pf, t_cola *pc)
{
    t_alumno al;
    char linea[200];

    while(!colaLlena(pc, sizeof(t_alumno)) && fgets(linea, 200, pf))
    {
        //printf("%s", linea);
        trozarLinea(&al, linea);
        //imprimirAlumno(&al);
        acolar(pc, &al, sizeof(t_alumno));
    }
    return SALIO_BIEN;
}

int sacarDeColaYMostrar(t_cola *pc, void imprimir(const void* dat))
{
    t_alumno al;

    while(!colaVacia(pc))
    {
        if(!desacolar(pc, &al, sizeof(t_alumno)))
            puts("ERROR: fallo al desacolar");
        else
            imprimir(&al);
    }

    return SALIO_BIEN;
}

void imprimirAlumno(const void* dat)
{
    printf("%d %s %s %.2f\n", ((t_alumno*)dat)->dni, ((t_alumno*)dat)->ape,
                              ((t_alumno*)dat)->nombre, ((t_alumno*)dat)->promedio);
}

void trozarLinea(t_alumno *d, char *s)
{
    char *aux = strchr(s, '\n');
    *aux = '\0';

    // Promedio
    aux = strrchr(s, ';');
    sscanf(aux+1, "%f", &d->promedio);
    *aux = '\0';

    // Nombre
    aux = strrchr(s, ';');
    strcpy(d->nombre, aux+1);
    *aux = '\0';

    // Apellido
    aux = strrchr(s, ';');
    strcpy(d->ape, aux+1);
    *aux = '\0';

    // Dni
    sscanf(s, "%d", &d->dni);
}
