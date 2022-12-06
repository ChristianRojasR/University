#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"
#include "Matriz.h"

int main()
{
    t_lista lista;
    t_matriz mat[] = {{4, 1, 4},
                          {1, 1, 1},
                          {2, 1, 2},
                          {3, 1, 3},
                          {0, 1, 0}};

    puts("----------inicia_prueba-------------");
    crear_lista(&lista);

    int i;
    for(i=0; i<5; i++)
        cargar_lista_prioridad(&lista, &mat[i], sizeof(t_matriz), comparacion_mat);

    ver_lista(&lista, imprimir_mat);
    puts("\n------------sacar_list-------------");
    t_matriz aux;
    while(sacar_lista(&lista, &aux, sizeof(t_matriz)))
        imprimir_mat(&aux);

    return 0;
}
