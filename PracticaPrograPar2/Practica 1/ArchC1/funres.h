#ifndef FUNRES_H_INCLUDED
#define FUNRES_H_INCLUDED

#include "tipos.h"

#define WENT_WRONG 0
#define WENT_GOOD 1

int crearLotePrueba_res(const char* filename);
int generarInforme_res(const char* filename, const char* output, const tsector* secs);

#endif // FUNRES_H_INCLUDED
