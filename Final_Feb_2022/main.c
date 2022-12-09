#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"
#include "Matriz.h"

int main()
{
    puts("----------inicia_prueba-------------\n");
    if(crear_arch_prueb())
        puts("Se creo el archivo...\n");

    FILE *pf_1, *pf_2;
    if(!abrir_arch(&pf_1, "mat1.txt", "rt"))
        return SALIO_MAL;
    if(!abrir_arch(&pf_2, "mat2.txt", "rt"))
    {
        fclose(pf_1);
        return SALIO_MAL;
    }

    t_tamanio tam_1, tam_2;
    cargar_tamanio(pf_1, &tam_1);
    cargar_tamanio(pf_2, &tam_2);
    if(verificar_mat(&tam_1, &tam_2))
        puts("Se pueden sumar las matrices...\n");

    t_lista mat_1, mat_2;
    puts("---------------mat_1----------------");
    crear_lista(&mat_1);
    cargar_mat(&mat_1, pf_1);
    imprimir_mat(&mat_1, &tam_1);
    puts("---------------mat_2----------------");
    crear_lista(&mat_2);
    cargar_mat(&mat_2, pf_2);
    imprimir_mat(&mat_2, &tam_2);

    t_lista sum;
    puts("---------------mat_sum----------------");
    crear_lista(&sum);
    sumar_mat(&mat_1, &mat_2, &sum);
    imprimir_mat(&sum, &tam_1);

    FILE *pf_sum;
    if(!abrir_arch(&pf_sum, "suma.txt", "wt"))
        return SALIO_MAL;
    guardar_mat(&sum, &tam_1, pf_sum);

    return 0;
}
