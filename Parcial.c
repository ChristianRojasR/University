///Rojas Rodriguez_Christian Rodrigo_43181120
#include "Parcial.h"

int casePrueb()
{
    FILE *pf;

    if(!(pf = fopen("impuestos.dat", "wb")))
        return SALIO_MAL;

    tImpuesto prueb[] = {{"AA111AA", 7, "ERRORDOS", 1111111,{2000, 1, 1}, 10100.1},
        {"aa111aa", 1, "ERRORUNO", 1112222,{2000, 1, 1}, 10100.1},
        {"AA222AA", 2, "ERRORtres", 1113333,{2000, 1, 1}, 10100.1}, //se soluciona y va a impuestos.dat
        {"AA333AA", 8, "ERRORdosTRES", 1114444,{2000, 1, 1}, 10100.1},
        {"aa444aa", 3, "ERRORunoTRES", 1115555,{2000, 1, 1}, 10100.1},
        {"AA555AA", 3, "ERROR3", 1116666,{2000, 1, 1}, 10100.1},
        {"BB111BB", 7, "PERSONAUNO", 2221111,{2000, 1, 1}, 10100.1},
        {"BB222BB", 7, "PERSONADOS", 2222222,{2000, 1, 1}, 10100.1},
        {"BB333BB", 7, "PERSONATRES", 2223333,{2000, 1, 1}, 10100.1},
        {"BB444BB", 7, "PERSONACUATRO", 2224444,{2000, 1, 1}, 10100.1}
    };

    fwrite(prueb, sizeof(prueb), 1, pf);

    fclose(pf);

    return SALIO_BIEN;
}

int abrirArch(FILE **pf, const char *nombre, const char *moodOpen)
{
    if(!(*pf = fopen(nombre, moodOpen)))
        return SALIO_MAL;

    return SALIO_BIEN;
}

int validarArchivo(FILE *pf)
{
    FILE *archError;
    tImpuesto imp;

    rewind(pf);

    abrirArch(&archError, "datosIncorrectos.txt", "w+t");

    fread(&imp, sizeof(tImpuesto), 1, pf);

    while(!feof(pf))
    {
        if(verificarNombre(imp.titular) == 3)
            fread(&imp, sizeof(tImpuesto), 1, pf);
        else if(verificarNombre(imp.titular) == 4)
            fprintf(archError, "%s%d%s%d%d%d%d%.2f%s\n", imp.patente, imp.nroCuota, imp.titular, imp.dni,
                                                  imp.vto.a, imp.vto.m, imp.vto.d, imp.importeMax, "ERROR3");

        fread(&imp, sizeof(tImpuesto), 1, pf);
    }

    return SALIO_BIEN;
}

int verificarNombre(char *nombre)
{
    if(!nombre)
    {
        if(*nombre >= 'A' && *nombre <= 'Z')
            return verificarNombre(nombre + 1);

        if(*nombre >= 'a' && *nombre <= 'Z')
        {
            *nombre += 32;
            return verificarNombre(nombre + 1);
        }

        return ERROR_4;
    }

    return ERROR_4;
}

int verificaNroCuota(int nCuota)
{
    if(nCuota < 0 && nCuota > 6)
        return SALIO_MAL;

    return SALIO_BIEN;
}

int verificaPatente(char *patente)
{
    return SALIO_BIEN;
}
