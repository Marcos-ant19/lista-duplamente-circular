#include <stdio.h>
#include "lista.h"

int main(){

    Lista* l = criar_lista();
    float valor;
    int consulta;
    int opcao;
    int pos;

    do{

        printf("1-Inserir\n");
        printf("2-Inserir na posicao\n");
        printf("3-Remover na posicao\n");
        printf("4-Mostrar\n");
        printf("5-Consultar\n");
        printf("6-Size\n");
        printf("7-Clear\n");
        printf("8-Ordenar\n");
        printf("0-Sair\n");
        scanf("%d", &opcao);

        switch (opcao){

            case 0:

            printf("Saindo...\n");
            break;

            case 1: 
                do{
                    printf("Digite valor para lista: ");
                    scanf("%f", &valor);

                if(valor != 0){
                    inserir(l, valor);
                    }

                }while(valor != 0);

                break;

            case 2:
                
            if(isEmpty(l)){
                break;
            }
                printf("Digite valor para lista: ");
                scanf("%f", &valor);

                printf("Digite uma posicao para lista: ");
                scanf("%d", &pos);

                inserirPos(l, valor, pos);
            
                break;

            case 3:

                if(isEmpty(l)){
                    break;
                }

                printf("Digite uma posicao para remover na lista: ");
                scanf("%d", &pos);
                removerPos(l, pos);

                break;

                case 4:

                    if(isEmpty(l)){
                        break;
                    }

                    mostrar(l);
                    break;

                case 5:

                    if(isEmpty(l)){
                        break;
                    }

                    printf("Digite uma posicao que deseja acessar: ");
                    scanf("%d", &consulta);

                    consultar(l, consulta);
                    break;

                case 6:
                    if(isEmpty(l)){
                        break;
                    }
                    printf("Elementos contidos na lista: %d\n", size(l));
                    break;
                case 7:
                     clear(l);
                     break;

                case 8:
                 if(isEmpty(l)){
                        break;
                    }
                 ordenar(l);
                 break;

                 default:
                    printf("Erro, tente novamente\n");
                    break;
                }

            }while(opcao != 0);

    return 0;
}