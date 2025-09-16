#include <stdio.h>  // Biblioteca padrão de entrada e saída
#include "filaInversa.h"   // Inclui o cabeçalho da fila

// Inicializa a fila (coloca valores padrão)
void inicializarFila(Fila *f) {
    f->inicio = 0;   // O início começa em 0
    f->fim = -1;     // O fim começa em -1 (fila vazia)
    f->tamanho = 0;  // Nenhum elemento no começo
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->tamanho == 0;  // Retorna 1 se vazia, 0 se não
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->tamanho == MAX;  // Retorna 1 se cheia
}

// Adiciona um valor no final da fila
int enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) return 0;              // Se cheia, não insere
    f->fim = (f->fim + 1) % MAX;             // Avança o índice do fim
    f->dados[f->fim] = valor;                // Coloca o valor no vetor
    f->tamanho++;                            // Aumenta o tamanho
    return 1;                                // Sucesso
}

// Remove um valor do início da fila
int desenfileirar(Fila *f, int *valor) {
    if (filaVazia(f)) return 0;              // Se vazia, não remove
    *valor = f->dados[f->inicio];            // Pega o valor do início
    f->inicio = (f->inicio + 1) % MAX;       // Avança o índice do início
    f->tamanho--;                            // Diminui o tamanho
    return 1;                                // Sucesso
}

// Mostra todos os elementos da fila
void exibirFila(Fila *f) {
    if (filaVazia(f)) {                      // Se a fila estiver vazia
        printf("Fila vazia!\n");             // Mostra mensagem
        return;                              // Sai da função
    }

    printf("Fila: ");                        // Texto inicial
    for (int i = 0; i < f->tamanho; i++) {   // Percorre a fila
        int indice = (f->inicio + i) % MAX;  // Calcula posição no vetor
        printf("%d ", f->dados[indice]);     // Mostra o valor
    }
    printf("\n");                            // Quebra de linha
}

// Inverte os elementos da fila
void reverso(Fila *f) {
    if (filaVazia(f)) return;                // Se vazia, não faz nada

    int i = 0;                               // Índice inicial
    int j = f->tamanho - 1;                  // Índice final
    while (i < j) {                          // Enquanto não se cruzarem
        int idx_i = (f->inicio + i) % MAX;   // Índice do elemento da frente
        int idx_j = (f->inicio + j) % MAX;   // Índice do elemento do fim

        // Troca os dois valores
        int temp = f->dados[idx_i];
        f->dados[idx_i] = f->dados[idx_j];
        f->dados[idx_j] = temp;

        i++;  // Avança para frente
        j--;  // Avança para trás
    }
}