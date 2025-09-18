#include <stdio.h>
#include "filaNegativos.h"

void inicializar(Fila* f){
    f->inicio = 0;
    f->fim = 0; 
    f->qtd = 0;
}

int vazia(Fila* f){
    return (f->qtd == 0);
}

int cheia(Fila* f){
    return (f->qtd == MAX);
}

void enfileirar(Fila* f, int valor){
    if (cheia(f)){
        printf("A fila esta cheia.\n");
        return;
    }
    f->dados[f->fim] = valor;            // coloca o valor na posição fim
    f->fim = (f->fim + 1) % MAX;         // deixa a posição em modo circular
    f->qtd++;
}

int desenfileirar(Fila* f){
    if(vazia(f)){
        printf("A fila esta vazia.\n");
        return -1;
    }
    int valor = f->dados[f->inicio];     // pega o valor da frente  
    f->inicio = (f->inicio + 1) % MAX;   // avança o início
    f->qtd--;                            // diminui a quantidade
    return valor;                        // devolve o valor removido
}

void excluirNegativos(Fila* f) {
    int tamanho = f->qtd; // guarda a quantidade atual

    // Processa todos os elementos uma vez
    for (int i = 0; i < tamanho; i++) {
        int valor = desenfileirar(f); // remove da frente
        if (valor >= 0) {             // só reinsere se for >= 0
            enfileirar(f, valor);
        }
        // se for negativo, descartamos
    }
}

void mostrarFila(Fila* f) {
    printf("Fila: ");
    int idx = f->inicio; // começa no início
    for (int i = 0; i < f->qtd; i++) { // percorre qtd elementos
        printf("%d ", f->dados[idx]);  // imprime o valor
        idx = (idx + 1) % MAX;         // avança circularmente
    }
    printf("\n");
}
