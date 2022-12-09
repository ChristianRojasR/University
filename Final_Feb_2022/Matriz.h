#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include "ListaSimple.h"

typedef struct
{
    unsigned fil,
             col;
    int dat;
}t_matriz;

typedef struct
{
    unsigned cant_fil,
             cant_col;
}t_tamanio;

int crear_arch_prueb();
int abrir_arch(FILE **pf, const char *nom_arch, const char *t_apert);

void cargar_mat(t_lista *p, FILE *pf);
void cargar_tamanio(FILE *pf, t_tamanio *tam);
int verificar_mat(const t_tamanio *tam_1, const t_tamanio *tam_2);
void guardar_mat(const t_lista *p, const t_tamanio *tam, FILE *pf);
void sumar_mat(const t_lista *mat_1, t_lista *mat_2, t_lista *sum);
void imprimir_mat(const t_lista *p, const t_tamanio *tam);

void imprimir_elemento(const void *dat);
int comparacion_mat(const void *dat1, const void *dat2);

#endif // MATRIZ_H_INCLUDED
