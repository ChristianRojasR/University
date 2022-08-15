///Rojas Rodriguez_Christian Rodrigo_43181120
#include <stdio.h>
#include <stdlib.h>
#include "Parcial.h"
#include "primListDoble.h"

int main()
{
    FILE *archImp;
    tLista list;
    tImpuesto imp;

    if(!casePrueb())
        puts("Salio mal...");
    else
        puts("Se creo archivo de prueba...");

    abrirArch(&archImp, "impuestos.dat", "r+b");

    crearList(&list);

    fread(&imp, sizeof(tImpuesto), 1, archImp);

    while(feof(archImp))
    {
        insertAlInicio(&list, &imp, sizeof(tImpuesto));
        fread(&imp, sizeof(tImpuesto), 1, archImp);
    }

    validarArchivo(archImp);

    return 0;
}
