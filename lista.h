#ifndef LISTA_H
#define LISTA_h

#include <stdbool.h>

typedef struct No{
    float dados;
    struct No* prox;
    struct No* ant;
}No;

typedef struct Lista{
    No* inicio;
    No* fim;
    int qtd;
}Lista;

Lista* criar_lista();
bool isEmpty(Lista* l);
void inserir(Lista* l, float valor);
bool inserirPos(Lista* l, float valor, int pos);
bool removerPos(Lista* l, int pos);
void consultar(Lista* l, int pos);
void mostrar(Lista* l);
int size(Lista* l);
void clear(Lista* l);
void ordenar(Lista* l);


#endif