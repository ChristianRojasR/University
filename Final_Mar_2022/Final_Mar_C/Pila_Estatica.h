#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED

// Pila.h
#include <stdio.h>
#include <stdlib.h>

#define SALIO_BIEN 1
#define SALIO_MAL 0
#define MINIMO(X, Y) ((X)<(Y)) ? (X) : (Y)
#define TAM_PILA 340

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
}t_pila;

void crear_pila(t_pila *p);
int pila_llena(const t_pila *p, unsigned tam);
int poner_pila(t_pila *p, const void *dat, unsigned tam);
int ver_tope(const t_pila *p, void *dat, unsigned tam);
int pila_vacia(const t_pila *p);
void vaciar_pila(t_pila *p);
int sacar_pila(t_pila *p, void *dat, unsigned tam);

#endif // PILA_ESTATICA_H_INCLUDED
