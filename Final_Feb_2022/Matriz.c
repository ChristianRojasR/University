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
    int fil_ant = 0,
        col_ant = 0,
        es_primero = 0;

    while(*p)
    {
        t_nodo *aux = *p;

        int fil_act = ((t_matriz*)aux->dat)->fil;
        // Verifico si es una nueva fila
        if(fil_ant != fil_act)
        {
            // Completo con cero la anterior fila
            for(int i=col_ant; i < tam->cant_col-1; i++)
                printf("0 ");
            printf("\n");
            // Si hay mas de una fila de diferencia la lleno con cero
            for(int i=fil_ant; i<fil_act-1; i++)
            {
                for(int j=0; j<tam->cant_fil; j++)
                    printf("0 ");
                printf("\n");
            }
            es_primero = 0;
        }


        int col_act = ((t_matriz*)aux->dat)->col;

        // Verifico si es el primer elemento de la fila
        if(!es_primero)
        {
            col_ant = 0;
            // Si es asi lo lleno con cero hasta ese elemento
            for(int i=col_ant; i < col_act; i++)
                printf("0 ");
            es_primero = 1;
        }
        else
        {
            // Sino, lleno con 0 entre el elemento anterior y el nuevo
            for(int i=col_ant; i < col_act-1; i++)
                printf("0 ");
        }


        // Imprimo el elemento
        printf("%d ", ((t_matriz*)aux->dat)->dat);

        // Actualizo los anteriores
        col_ant = col_act;
        fil_ant = fil_act;

        p = &(*p)->sig;

        // Si se termino la lista lleno con ceros los espacios y filas que queden
        if(!(*p))
        {
            for(int i=col_ant; i < tam->cant_col-1; i++)
                printf("0 ");
            printf("\n");
            for(int i=fil_ant; i < tam->cant_fil-1; i++)
            {
                for(int i=0; i < tam->cant_col; i++)
                    printf("0 ");
                printf("\n");
            }
        }
    }
}

int comparacion_mat(const void *dat1, const void *dat2)
{
    if((((t_matriz*)dat1)->fil - ((t_matriz*)dat2)->fil) == 0)
        return ((t_matriz*)dat1)->col - ((t_matriz*)dat2)->col;
    return ((t_matriz*)dat1)->fil - ((t_matriz*)dat2)->fil;
}

void cargar_tamanio(FILE *pf, t_tamanio *tam)
{
    // Obtengo primero el tamanio de la matriz
    fscanf(pf, "[%d][%d]\n", &tam->cant_fil, &tam->cant_col);
}

void cargar_mat(t_lista *p, FILE *pf)
{
    // Luego los elementos no nulos
    t_matriz aux;
    while(fscanf(pf, "[%d][%d]%d\n", &aux.fil, &aux.col, &aux.dat) != EOF)
        cargar_lista_prioridad(p, &aux, sizeof(t_matriz), comparacion_mat);

    fclose(pf);
}

int verificar_mat(const t_tamanio *tam_1, const t_tamanio *tam_2)
{
    return tam_1->cant_fil == tam_2->cant_fil && tam_1->cant_col == tam_2->cant_col;
}

void sumar_mat(const t_lista *mat_1, t_lista *mat_2, t_lista *sum)
{
    t_matriz *aux;
    t_lista *copia = mat_2;

    while(*mat_1)
    {
        aux = (*mat_1)->dat;

        while(*copia && comparacion_mat(&aux, (*copia)->dat) == 0)
            copia = &(*copia)->sig;

        if(*copia)
        {
            t_matriz suma;
            suma.col = aux->col;
            suma.fil = aux->fil;
            suma.dat = aux->dat + ((t_matriz*)(*copia)->dat)->dat;
            cargar_lista_prioridad(sum, &suma, sizeof(suma), comparacion_mat);
        }

        copia = &(*mat_2)->sig;
        mat_1 = &(*mat_1)->sig;
    }
}
