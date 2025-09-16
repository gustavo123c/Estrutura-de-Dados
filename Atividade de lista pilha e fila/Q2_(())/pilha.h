#define PILHA_H

#define MAX_TAM 100

typedef struct{
    char itens[MAX_TAM];
    int topo;
}Pilha;

void inicializarPilha(Pilha *p);
int pilhaVazia (Pilha *p);
int pilhaCheia (Pilha *p);
void empilhar (Pilha *p, char c);
char desempilhar(Pilha *p);