#define PILHA_H

#define MAX 100

typedef struct{
    char itens[MAX];
    int topo;
}Pilha;

Pilha* cria_Pilha();
int pilhaVazia (Pilha *p);
int pilhaCheia (Pilha *p);
void empilhar (Pilha *p, char c);
char desempilhar(Pilha *p);
int verificarExpressao(const char *expr);
