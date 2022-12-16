#include "Funciones.h"
#include <string.h>

void crear_arch_prueba()
{
    FILE *pf;
    t_prod v[]={{"11111", 'A', 1},
                {"22222", 'B', 2},
                {"11111", 'B', 1},
                {"33333", 'D', 2},
                {"33333", 'B', 4},
                {"22222", 'A', 2}};

    if(!abrir_arch(&pf, "prueba.bin", "wb"))
        return;

    fwrite(v, sizeof(v), 1, pf);
    fclose(pf);
}

int abrir_arch(FILE **pf, const char *nom_arch, const char *tipo_apert)
{
   if(!(*pf = fopen(nom_arch, tipo_apert)))
        return SALIO_MAL;
   return SALIO_BIEN;
}

int cmp_prod(const void *dat_1, const void *dat_2)
{
    return strcmp(((t_prod*)dat_1)->cod, ((t_prod*)dat_2)->cod);
}

void ver_prod(const void *dat)
{
    printf("%s %c %d\n", ((t_prod*)dat)->cod, ((t_prod*)dat)->sector, ((t_prod*)dat)->cant);
}

void repetidos_prod(void *dat_1, const void *dat_2)
{
    ((t_prod*)dat_1)->cant += ((t_prod*)dat_2)->cant;
}

void grabar_prod(FILE *pf, const void *dat)
{
    fprintf(pf, "%s|%c|%d\n", ((t_prod*)dat)->cod, ((t_prod*)dat)->sector, ((t_prod*)dat)->cant);
}

int grabar_lista_arch(t_lista *p, void grabar(FILE *pf, const void *dat))
{
    FILE *pf;
    if(!abrir_arch(&pf, "productos_sin_repetidos.txt", "wt"))
        return SALIO_MAL;

    while(*p)
    {
        t_prod aux;
        sacar_lista(p, &aux, sizeof(t_prod));
        grabar(pf, &aux);
    }
    fclose(pf);
    return SALIO_BIEN;
}
