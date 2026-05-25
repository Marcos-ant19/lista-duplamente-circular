# Lista Duplamente Circular em Linguagem C

## Descrição

Este projeto apresenta a implementação de uma Lista Duplamente Circular utilizando a linguagem C e conceitos fundamentais de Estrutura de Dados.

A aplicação foi desenvolvida com o objetivo de aprofundar os conhecimentos em:

- Alocação dinâmica de memória
- Manipulação de ponteiros
- Estruturas encadeadas
- Organização de dados em memória
- Algoritmos de ordenação

A estrutura implementada permite navegação bidirecional entre os elementos, além da característica circular, em que o último nó aponta para o primeiro elemento da lista.

---

## Funcionalidades Implementadas

- Criação da lista
- Inserção de elementos
- Inserção em posição específica
- Remoção de elementos
- Consulta de valores
- Verificação de lista vazia
- Ordenação utilizando Bubble Sort
- Limpeza completa da lista
- Contagem de elementos
- Percurso circular da estrutura

---

## Estrutura Utilizada

Cada nó da lista possui:

```c
typedef struct No{
    float dados;
    struct No* prox;
    struct No* ant;
}No;
