#include "funres.h"
#include "tipos.h"
#include <stdio.h>

int crearLotePrueba_res(const char* filename)
{
    FILE *pf;
    int i;

    if(!(pf = fopen(filename, "wb")))
    {
        return WENT_WRONG;
    }

    tentradaSalida prueb[] = {{0, "YAENTRO", 'E', 'A'},
                              {0, "MAS1", 'E', 'B'},
                              {0, "YAENTRO", 'E', 'A'}, //ERROR
                              {0, "MAS2", 'E', 'B'},
                              {0, "MAS3", 'E', 'B'}, //ERROR
                              {0, "OTCEC", 'E', 'A'},
                              {0, "OTSEC", 'S', 'C'}, //ERROR
                              {0, "NOSAL", 'E', 'A'}, //ERROR
                              {0, "MAS1", 'S', 'B'},
                              {0, "MAS2", 'S', 'B'},
                              {0, "MAS3", 'S', 'B'},
                              {0, "YAENTRO", 'S', 'A'},
                              {0, "OTSEC", 'S', 'A'}};

    for(i=0; i < sizeof(prueb)/sizeof(tentradaSalida); i++)
        fprintf(pf, "%13ld%10s%c%c\n", prueb[i].timestamp, prueb[i].dominio, prueb[i].tipo, prueb[i].sector);

    return WENT_GOOD;
};

int generarInforme_res(const char* filename, const char* output, const tsector* secs)
{
    return WENT_GOOD;
}
