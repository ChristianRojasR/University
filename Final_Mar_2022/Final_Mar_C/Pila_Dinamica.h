#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

// Pila.h
#include <stdio.h>
#include <stdlib.h>

#define SALIO_BIEN 1
#define SALIO_MAL 0
#define MINIMO(X, Y) ((X)<(Y)) ? (X) : (Y)

typedef struct s_nodo
{
    void *dat;
    unsigned tam;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_pila;

void crear_pila(t_pila *p);
int pila_llena(const t_pila *p, unsigned tam);
int poner_pila(t_pila *p, const void *dat, unsigned tam);
int ver_tope(const t_pila *p, void *dat, unsigned tam);
int pila_vacia(const t_pila *p);
void vaciar_pila(t_pila *p);
int sacar_pila(t_pila *p, void *dat, unsigned tam);

#endif // PILA_DINAMICA_H_INCLUDED
