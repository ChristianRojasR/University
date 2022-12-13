#include <stdio.h>
#include <stdlib.h>
#include "Pila_Dinamica.h"
#include "Funciones.h"

int main()
{
    // Resolviendo el problema
    crear_arch_prueba();

    FILE *pf;
    if(!abrir_arch(&pf, "datos.txt", "rt"))
        return SALIO_MAL;

    int tam;
    fscanf(pf, "%d\n", &tam);
    t_pila v_pila[tam];

    if(!trabajar_pilas(pf, v_pila, tam))
    {
        for(int i=0; i<tam; i++)
            vaciar_pila(&v_pila[i]);
    }
    else
    {
        char nom_arch[50];
        for(int i=0; i<tam; i++)
        {
            sprintf(nom_arch, "pila%d.txt", i);
            cierre_normal(nom_arch, &v_pila[i], &i);
        }
    }
    fclose(pf);
    remove("datos.txt");
    /*
    //Prueba de pila
    int vec[5] = {1, 2, 3, 4, 5};
    t_pila pila;

    crear_pila(&pila);
    for(int i=0; i<5; i++)
        poner_pila(&pila, &vec[i], sizeof(int));
    if(pila_llena(&pila, sizeof(int)))
        puts("Se lleno la pila...");

    int aux;
    ver_tope(&pila, &aux, sizeof(int));
    printf("%d ", aux);
    for(int i=0; i<5; i++)
    {
        sacar_pila(&pila, &aux, sizeof(int));
        printf("%d ", aux);
    }
    if(!pila_vacia(&pila))
        puts("Se vacio la pila...");
    */
    return 0;
}
