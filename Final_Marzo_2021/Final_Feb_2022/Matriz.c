#include "Matriz.h"

void imprimir_mat(const void *dat)
{
    printf("[%d, %d] %d\n", ((t_matriz*)dat)->fil, ((t_matriz*)dat)->col, ((t_matriz*)dat)->dat);
}

int comparacion_mat(const void *dat1, const void *dat2)
{
    if((((t_matriz*)dat1)->fil - ((t_matriz*)dat2)->fil) == 0)
        return ((t_matriz*)dat1)->col - ((t_matriz*)dat2)->col;
    return ((t_matriz*)dat1)->fil - ((t_matriz*)dat2)->fil;
}
