#define FILAINVERSA_H

#define MAX 100  // Define o tamanho máximo da fila

// Estrutura que representa a fila
typedef struct {
    int dados[MAX];  // Vetor que guarda os elementos
    int inicio;      // Índice do primeiro elemento
    int fim;         // Índice do último elemento
    int tamanho;     // Quantidade de elementos na fila
} Fila;

// Funções da fila
void inicializarFila(Fila *f);   // Inicializa a fila
int filaVazia(Fila *f);          // Verifica se a fila está vazia
int filaCheia(Fila *f);          // Verifica se a fila está cheia
int enfileirar(Fila *f, int v);  // Insere um valor no final
int desenfileirar(Fila *f, int *v); // Remove um valor do início
void exibirFila(Fila *f);        // Mostra os elementos da fila
void reverso(Fila *f);           // Inverte a ordem da fila
