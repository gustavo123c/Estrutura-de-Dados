#define FILA_H

#define MAX 100 // tamanho máximo da fila

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int qtd;
} Fila;

// Funções da fila
void inicializar(Fila* f);
int vazia(Fila* f);
int cheia(Fila* f);
void enfileirar(Fila* f, int valor);
int desenfileirar(Fila* f);
void mostrarFila(Fila* f);

// Função pedida: excluir negativos
void excluirNegativos(Fila* f);