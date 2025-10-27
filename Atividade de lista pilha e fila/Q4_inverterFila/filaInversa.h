#define FILA_INVERSA_H

#define MAX 100  // tamanho máximo da fila

// Estrutura da fila
typedef struct fila {
    int dados[MAX];  // vetor que armazena os elementos
    int inicio;      // posição do início
    int fim;         // posição do fim
    int tamanho;     // quantidade de elementos
} Fila;

// Funções da fila
Fila* criar_fila();                // cria e inicializa a fila
int filaVazia(Fila *f);            // verifica se está vazia
int filaCheia(Fila *f);            // verifica se está cheia
int enfileirar(Fila *f, int valor);// insere elemento no fim
int desenfileirar(Fila *f, int *v);// remove elemento do início
void exibirFila(Fila *f);          // mostra os elementos
void reverso(Fila *f);             // inverte a fila
