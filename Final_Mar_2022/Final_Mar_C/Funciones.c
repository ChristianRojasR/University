#include "Funciones.h"

void crear_arch_prueba()
{
    int tam_fil = 2;
    t_dat vec[7] = {{1, 1},
                    {1, 0}, // Se elimina la pila 1
                    {2, 1},
                    {2, 2},
                    {-2, 2}, // Se desapila el tope
                    {-1, 0}, // Se quiere desapilar de una pila que no existe
                    {1, 1}}; // Se quiere apilar en una pila que no existe
    FILE *pf;

    if(!abrir_arch(&pf, "datos.txt", "wt"))
        return;

    fprintf(pf, "%d\n", tam_fil);
    for(int i=0; i<7; i++)
        fprintf(pf, "(%d,%d)\n", vec[i].num_pila, vec[i].val);
    fclose(pf);
}

int abrir_arch(FILE **pf, const char *nom_arch, const char *t_apert)
{
    if(!(*pf = fopen(nom_arch, t_apert)))
        return SALIO_MAL;
    return SALIO_BIEN;
}

int trabajar_pilas(FILE *pf, t_pila v[], const int tam)
{
    for(int i=0; i<tam; i++)
        crear_pila(&v[i]);

    t_dat aux;
    //int ind_pila = 0;
    while(fscanf(pf, "(%d,%d)\n", &aux.num_pila, &aux.val) != EOF)
    {

        // printf("%d %d\n", aux.num_pila, aux.val);
        if(aux.num_pila > 0)
        {
            if(!aux.val)
                vaciar_pila(&v[aux.num_pila-1]);
            poner_pila(&v[aux.num_pila-1], &aux.val, sizeof(aux.val));
        }
        if(aux.num_pila < 0)
        {
            int ele_pila;
            sacar_pila(&v[(-1*aux.num_pila)-1], &ele_pila, sizeof(ele_pila));
        }
        if(!aux.num_pila)
            return SALIO_MAL;
    }
    return SALIO_BIEN;
}

int cierre_normal(const char *nom_arch, t_pila *p, const int *num_pila)
{
    FILE *pf;
    if(!abrir_arch(&pf, nom_arch, "wt"))
        return SALIO_MAL;

    if(pila_vacia(p))
    {
        fclose(pf);
        return SALIO_BIEN;
    }

    int aux;
    fprintf(pf, "%d\n", *num_pila);
    while(sacar_pila(p, &aux, sizeof(aux)))
        fprintf(pf, "(%d,%d)\n", *num_pila, aux);

    fclose(pf);
    return SALIO_BIEN;
}
