#define PALINDROMO_H

// Constante para definir o tamanho máximo da pilha
#define MAX 100

// Definição da struct Pilha
typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

// Protótipos das funções
Pilha* cria_Pilha();
void libera_Pilha(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
void empilhar(Pilha *p, char c);
char desempilhar(Pilha *p);
int ehPalindromo(const char *palavra);