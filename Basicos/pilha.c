#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int topo;
    char itens[MAX];
}Pilha;

Pilha* criar_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(pilha));
    if (pi != NULL){
        pi -> topo -1;
    }
    return pi;
}

void libera_Pilha(Pilha *p){
    free(p);
}

int pilhaVazia(Pilha *p){
    return p->topo == -1;
}

int pilhaCheia(Pilha *p){
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int valor){
    if (pilhaCheia(p)){
        printf("Pilha cheia.\n");
        return '\0';
    }
    p->itens[p->topo] = valor
    p->topo++;
}

void desempilhar(Pilha *p){
    if(pilhaVazia(p)){
        printf("Pilha vazia.\n");
        return;
    }
    int valor = (p->itens[p->topo]);
    p->topo--;
    return c;
}