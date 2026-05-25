#include <stdio.h>
#include "lista.h"

int main(){

    Lista* l = criar_lista();
    float valor;
    int consulta;

    do{
        printf("Digite valor para lista: ");
        scanf("%f", &valor);
        if(valor != 0){
            inserir(l, valor);
        }
    }while(valor != 0);

    //removerPos(l, 0);

    //printf("Digite uma posicao que deseja acessar: ");
    //scanf("%d", &consulta);

    //consultar(l, consulta);

    //printf("Elementos contidos na lista: %d\n", size(l));
    //clear(l);
    ordenar(l);
    mostrar(l);


    return 0;
}