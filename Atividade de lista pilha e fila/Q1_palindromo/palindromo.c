#include <stdio.h>      // Adicionado para a função printf()
#include <string.h>     // Adicionado para a função strlen()
#include "palindromo.h" // Inclui nosso header com todas as definições

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, char c) {
    if (pilhaCheia(p)) {
        printf("Erro: tentativa de empilhar em pilha cheia\n");
    } else {
        p->topo++;
        p->itens[p->topo] = c;
    }
}
    
char desempilhar(Pilha *p) {
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
    Pilha p;
    inicializarPilha(&p);
    int tamanho = strlen(palavra); // Agora o compilador conhece strlen()

    // Etapa 1: Empilhar
    for (int i = 0; i < tamanho; i++) {
        empilhar(&p, palavra[i]);
    }

    // Etapa 2: Desempilhar e comparar
    for (int i = 0; i < tamanho; i++) {
        char charDaPilha = desempilhar(&p);
        if (palavra[i] != charDaPilha) {
            return 0; // Falso
        }
    }
    
    return 1; // Verdadeiro
}