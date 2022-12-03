#ifndef MYFUN_H_INCLUDED
#define MYFUN_H_INCLUDED

#define ERROR_MEM 0
#define ERROR_DUPLICATE 0
#define WENT_WRONG 0
#define WENT_GOOD 1

typedef struct sNodo
{
    void *dat;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo *tList;


void newList(tList *pl);

// all functions are recursive
int rInsertNoDuplicate(tList *pl, const void *dat, unsigned tam, int compare(const void *dat1, const void *dat2));
int cmpIntAndOut(const void *dat1, const void *dat2);

int rCountByClass(const tList *pl, const void *dat, int compare(const void *dat1, const void *dat2));
int cmpByClass(const void *dat1, const void *dat2);

int rSearch(const tList *pl, const void *dat, int compare(const void *dat1, const void *dat2));

int rDelete(tList *pl, void *dat, unsigned tam);

int rRemoveFirst(tList *pl, void *dat, unsigned tam);

#endif // MYFUN_H_INCLUDED
