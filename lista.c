#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

Lista* criar_lista(){
    Lista* l = malloc(sizeof(Lista));

    if(l == NULL){
        return NULL;
    }

    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;

    return l;
}

bool isEmpty(Lista* l){
    return l->inicio == NULL;
}

void inserir(Lista* l, float valor){
    No* novo = malloc(sizeof(No));

    if(novo == NULL){
        return;
    }

    novo->dados = valor;

    if(isEmpty(l)){
        novo->prox = novo;
        novo->ant = novo;
        l->inicio = novo;
        l->fim = novo;
    }else{
        novo->prox = l->inicio;    //o novo nó aponta para antigo inicio
        novo->ant = l->fim;      //o novo nó aponta para atrás do fim
        l->fim->prox = novo;     //o nó aponta para fim matendo a lista circular
        l->inicio->ant = novo;  //o novo no aponta para o inicio matendo a lista circular
        l->inicio = novo;      //o novo vira o novo inicio
    }

    l->qtd++;
    return;
}

bool inserirPos(Lista* l, float valor, int pos){
    if(pos < 0 || pos > l->qtd){
        return false;
    }

    No* novo = malloc(sizeof(No));

    if(novo == NULL){
        return false;
    }

    novo->dados = valor;
    printf("%.2f\n", valor);
    
    if(isEmpty(l)){
        novo->prox = novo;
        novo->ant = novo;
        l->inicio = novo;
        l->fim = novo;
        l->qtd++;
        return true;
    }

    No* aux = l->inicio;
    int cont = 0;

    while(cont < pos){
        aux = aux->prox;
        cont++;
    }

    novo->prox = aux;
    novo->ant = aux->ant;
    aux->ant->prox = novo;
    aux->ant = novo;

    if(pos == 0){
        l->inicio = novo;
    }
    if(pos == l->qtd){
        l->fim = novo;
    }


    l->qtd++;
    return true;
}

bool removerPos(Lista* l, int pos){
    if(isEmpty(l)){
        return false;
    }

    if(pos < 0 || pos >= l->qtd){
        return false;
    }

    No* temp;

    if(l->qtd == 1){
        temp = l->inicio;
        l->inicio = NULL;
        l->fim = NULL;
        l->qtd--;
        free(temp);
        return true;
    }

    No* aux = l->inicio;

    for(int i = 0;i < pos;i++){
        aux = aux->prox;
    }

    if(pos == 0){
     l->inicio = aux->prox;
     l->fim->prox = l->inicio;
     l->inicio->ant = l->fim;
    }else if(pos == l->qtd -1){
        l->fim = aux->ant;
        l->inicio->ant = l->fim;
        l->fim->prox = l->inicio;
    }else{
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;   
    }


    l->qtd--;
    free(aux);
    return true;
}

void mostrar(Lista* l){
    No* aux = l->inicio;

    if(isEmpty(l)){
        return;
    }

    printf("Valores contindo na lista\n");
    do{

        printf("%.2f\n", aux->dados);
        aux = aux->prox;

    }while(aux != l->inicio);
    printf("------------------------------\n");

}

void consultar(Lista* l, int pos){
    if(isEmpty(l)){
        return;
    }

    if(pos < 0 || pos >= l->qtd){
        return;
    }

    No* aux = l->inicio;

    for(int  i = 0;i < pos;i++){
        aux = aux->prox;
    }

    printf("%.2f\n", aux->dados);
}

int size(Lista* l){
    if(isEmpty(l)){
        return 0;
    }


    No* aux = l->inicio;

    for(int i = 0;i < l->qtd;i++){
        aux = aux->prox;
    }

}

void clear(Lista* l){
    No* aux = l->inicio;
    No* temp;
    
    for(int i = 0;i < l->qtd;i++){
        temp = aux;
        aux = aux->prox;
        free(temp);
    }

    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

void ordenar(Lista* l){
    if(isEmpty(l)){
        return;
    }

    No* aux;
    float temp;

    for(int i = 0;i < l->qtd - 1;i++){
        aux = l->inicio;

        for(int j = 0;j < l->qtd - 1;j++){
            if(aux->dados > aux->prox->dados){
                temp = aux->dados;
                aux->dados = aux->prox->dados;
                aux->prox->dados = temp;
            }
                aux = aux->prox;
        }
    }
}