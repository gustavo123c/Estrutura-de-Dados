#include <stdio.h>
#include <stdlib.h>
#include "filaInversa.h"

// Cria e inicializa a fila
Fila* criar_fila() {
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if (fi == NULL) return NULL;   // falha de alocação

    fi->inicio = 0;   // início começa em 0
    fi->fim = -1;     // fim em -1 (fila vazia)
    fi->tamanho = 0;  // nenhum elemento ainda

    return fi;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->tamanho == MAX;
}

// Insere um valor no fim da fila
int enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) return 0; // falha: cheia
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = valor;
    f->tamanho++;
    return 1;
}

// Remove um valor do início da fila
int desenfileirar(Fila *f, int *valor) {
    if (filaVazia(f)) return 0; // falha: vazia
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

// Mostra os elementos da fila
void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila: ");
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->inicio + i) % MAX;
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}

// Inverte os elementos da fila
void reverso(Fila *f) {
    if (filaVazia(f)) return;

    int i = 0;
    int j = f->tamanho - 1;
    while (i < j) {
        int idx_i = (f->inicio + i) % MAX;
        int idx_j = (f->inicio + j) % MAX;

        int temp = f->dados[idx_i];
        f->dados[idx_i] = f->dados[idx_j];
        f->dados[idx_j] = temp;

        i++;
        j--;
    }
}
