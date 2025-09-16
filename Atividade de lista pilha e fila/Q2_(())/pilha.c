#include <stdio.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
    p->topo = -1; // pilha começa vazia
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1; // se topo = -1, está vazia
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX_TAM - 1; // pilha cheia
}

void empilhar(Pilha *p, char c) {
    if (pilhaCheia(p)) {
        printf("Nao e possivel empilhar em uma pilha cheia.\n");
    } else {
        p->topo++;
        p->itens[p->topo] = c;
    }
}

char desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Nao e possivel desempilhar de uma pilha vazia.\n");
        return '\0'; // retorna caractere nulo
    } else {
        char c = p->itens[p->topo];
        p->topo--;
        return c;
    }
}
