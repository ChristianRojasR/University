#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"
#include "Matriz.h"

int main()
{
    puts("----------inicia_prueba-------------");
    if(crear_arch_prueb())
        puts("Se creo el archivo...\n");
    t_lista lista;

    FILE *pf_1, *pf_2;
    if(!abrir_arch(&pf_1, "mat1.txt", "rt"))
        return SALIO_MAL;
    if(!abrir_arch(&pf_2, "mat2.txt", "rt"))
    {
        fclose(pf_1);
        return SALIO_MAL;
    }



    /*
    crear_lista(&lista);

    int i;
    for(i=0; i<5; i++)
        cargar_lista_prioridad(&lista, &mat[i], sizeof(t_matriz), comparacion_mat);

    ver_lista(&lista, imprimir_mat);
    puts("\n------------sacar_list-------------");
    t_matriz aux;
    while(sacar_lista(&lista, &aux, sizeof(t_matriz)))
        imprimir_mat(&aux);
    */

    return 0;
}
