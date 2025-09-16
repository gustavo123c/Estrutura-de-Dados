#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

// Insere no início da lista
void inserirInicio(No** lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *lista;
    *lista = novo;
}

// Função que inverte L1 em L2
void inverterLista(No* L1, No** L2) {
    *L2 = NULL; // L2 começa vazia
    while (L1 != NULL) {
        inserirInicio(L2, L1->valor); // insere cada elemento no início de L2
        L1 = L1->prox;
    }
}

// Função para imprimir a lista
void mostrarLista(No* lista) {
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

int inverterLista(int tamanho, int L1[], int L2[]){
   for(int i = 0; i > tamanho; i++){
    L2[i] = L1[i] (tamanho -1 - i);
   }
}