#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

Pilha* criar_pilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = -1;
    }
    return p;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, char c) {
    if (!pilhaCheia(p)) {
        p->itens[++p->topo] = c;
    }
}

char desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->itens[p->topo--];
    } else {
        printf("A pilha esta vazia\n");
        return '\0';
    }
}

int verificarExpressao(const char *expr) {
    Pilha *p = criar_pilha();
    if (p == NULL) {
        printf("Erro ao criar a pilha!\n");
        return 0;
    }

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            empilhar(p, '(');
        } else if (expr[i] == ')') {
            if (pilhaVazia(p)) {
                free(p);
                return 0; // encontrou ')' sem par
            }
            desempilhar(p);
        }
    }

    int resultado = pilhaVazia(p); // só é válido se no fim a pilha estiver vazia
    free(p);
    return resultado;
}
