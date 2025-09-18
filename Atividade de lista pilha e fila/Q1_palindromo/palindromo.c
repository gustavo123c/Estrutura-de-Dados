#include <stdio.h>
#include <stdlib.h>     // Para malloc e free
#include <string.h>
#include "palindromo.h"

Pilha* cria_Pilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha)); // aloca dinamicamente
    if (p != NULL) {
        p->topo = -1; // inicializa a pilha
    }
    return p;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, char c) { //O nome tambem poderia ser inserir
    if (pilhaCheia(p)) {
        printf("Erro: tentativa de empilhar em pilha cheia\n");
    } else {
        p->topo++;
        p->itens[p->topo] = c;
    }
}
    
char desempilhar(Pilha *p) { // o nome tambem poderia ser remover
    if (pilhaVazia(p)) {
        printf("Erro: tentativa de desempilhar de pilha vazia\n");
        return '\0';
    } else {
        char c = p->itens[p->topo];
        p->topo--;
        return c;
    }
}

int ehPalindromo(const char *palavra) {
    // Passo 1: Criar a pilha dinamicamente
    Pilha *p = cria_Pilha();  
    if (p == NULL) { // Se malloc falhar
        printf("Erro: nao foi possivel criar a pilha!\n");
        return 0; // Consideramos que nao eh palindromo
    }

    // Passo 2: Calcular o tamanho manualmente (sem strlen)
    int tamanho = 0;
    while (palavra[tamanho] != '\0') {
        tamanho++;
    }

    // Passo 3: Empilhar todos os caracteres da palavra
    for (int i = 0; i < tamanho; i++) {
        empilhar(p, palavra[i]);
    }

    // Passo 4: Desempilhar e comparar
    for (int i = 0; i < tamanho; i++) {
        char doTopo = desempilhar(p);   // pega o caractere do final
        char doOriginal = palavra[i];   // pega o caractere do inicio

        if (doOriginal != doTopo) {
            libera_Pilha(p); // liberar antes de sair
            return 0;        // nao eh palindromo
        }
    }

    // Passo 5: Liberar memoria e retornar verdadeiro
    libera_Pilha(p);
    return 1;
}