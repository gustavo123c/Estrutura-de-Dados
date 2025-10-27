#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Defini tamanho máximo da fila

// Estrutura da fila
struct fila {
    int inicio, final, qtd;
    int dados[MAX];   // faltava o array para armazenar os elementos
};

typedef struct fila Fila;

// Função para criar fila
Fila* criar_fila() {
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if (fi != NULL) {   // antes estava invertido (checando NULL errado)
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

// Verifica se está vazia
int filaVazia(Fila *f) {
    return (f->qtd == 0);
}

// Verifica se está cheia
int filaCheia(Fila *f) {
    return (f->qtd == MAX);
}

// Inserir elemento
int enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Nao e possivel pois a fila esta cheia.\n");
        return -1;
    }
    f->dados[f->final] = valor;              // salva o valor
    f->final = (f->final + 1) % MAX;         // avança o índice circular
    f->qtd++;                                // aumenta qtd
    return 0;
}

// Remover elemento
int desenfileirar(Fila *f, int valor) {
    if (filaVazia(f)) {
        printf("Nao e possivel pois a fila esta vazia.\n");
        return -1;
    }
    valor = f->dados[f->inicio];                // pega valor
    f->inicio = (f->inicio + 1) % MAX;       // avança início circular
    f->qtd--;                                // reduz qtd
    return 0;
}

// Exibir fila
void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0; i < f->qtd; i++) {
        int idx = (f->inicio + i) % MAX;    
    }
    printf("\n");
}

    
