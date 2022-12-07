#include "Matriz.h"

int crear_arch_prueb()
{
    FILE *pf_1, *pf_2;
    t_matriz mat_1[] = {{4, 1, 4},
        {1, 1, 1},
        {1, 2, 2},
        {1, 3, 3},
        {0, 1, 5}
    },
    mat_2[] = {{4, 2, 4},
        {1, 2, 1},
        {2, 1, 2},
        {3, 1, 3},
        {0, 1, 5}
    };

    abrir_arch(&pf_1, "mat1.txt", "wt");
    abrir_arch(&pf_2, "mat2.txt", "wt");

    fprintf(pf_1, "[%d][%d]\n", 5, 5);
    for(int i=0; i<sizeof(mat_1)/sizeof(t_matriz); i++)
        fprintf(pf_1, "[%d][%d]%d\n", mat_1[i].fil, mat_1[i].col, mat_1[i].dat);

    fprintf(pf_2, "[%d][%d]\n", 5, 5);
    for(int i=0; i<sizeof(mat_2)/sizeof(t_matriz); i++)
        fprintf(pf_2, "[%d][%d]%d\n", mat_2[i].fil, mat_2[i].col, mat_2[i].dat);

    fclose(pf_1);
    fclose(pf_2);

    return SALIO_BIEN;
}

int abrir_arch(FILE **pf, const char *nom_arch, const char *t_apert)
{
    if(!(*pf = fopen(nom_arch, t_apert)))
        return SALIO_MAL;
    return SALIO_BIEN;
}

void imprimir_elemento(const void *dat)
{
    printf("[%d, %d] %d\n", ((t_matriz*)dat)->fil, ((t_matriz*)dat)->col, ((t_matriz*)dat)->dat);
}

void imprimir_mat(const t_lista *p, const t_tamanio *tam)
{
    int fil = 0,
        col_ant = 0,
        es_primero = 0;

    while(*p)
    {
        t_nodo *aux = *p;

        if(fil != ((t_matriz*)aux->dat)->fil)
        {
            fil = ((t_matriz*)aux->dat)->fil;
            puts("\n");
        }

        int col_act = ((t_matriz*)aux->dat)->col;

        if(!es_primero)
        {
            col_ant = col_act;
            es_primero = 1;
        }

        for(int i=col_ant; col_ant < col_act; i++)
            puts("0 ");

        col_ant = col_act;

        p = &(*p)->sig;
    }
}

int comparacion_mat(const void *dat1, const void *dat2)
{
    if((((t_matriz*)dat1)->fil - ((t_matriz*)dat2)->fil) == 0)
        return ((t_matriz*)dat1)->col - ((t_matriz*)dat2)->col;
    return ((t_matriz*)dat1)->fil - ((t_matriz*)dat2)->fil;
}

int cargar_mat(t_lista *p, FILE **pf)
{
    return SALIO_BIEN;
}
