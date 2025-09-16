#ifndef PALINDROMO_H
#define PALINDROMO_H

// A constante e a struct que definem a Pilha
#define MAX 100

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

// Protótipos (a "interface pública" da sua biblioteca)
void inicializarPilha(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
void empilhar(Pilha *p, char c);
char desempilhar(Pilha *p);
int ehPalindromo(const char *palavra);

#endif // PALINDROMO_H