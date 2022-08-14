#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#include "headAtoi.h"

int main()
{
    char cadena[TAM] ="  aaa ";
    int res;

    res = miAtoi(cadena);

    printf("\nATOI: %d", atoi(cadena));

    if(res)
        printf("\nmiATOI = %d",res);
    else
        printf("\nSalioMal = %d\n", res);

    return 0;
}
