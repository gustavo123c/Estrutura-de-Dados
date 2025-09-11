// Arquivo: filaEstatica.h

#define MAX 100

// 1. A ESTRUTURA PRECISA ESTAR DEFINIDA AQUI
struct produto {
    int codigo;
    char descricao[50];
    float preco;
};

// 2. O TYPEDEF PRECISA ESTAR AQUI, ASSOCIANDO 'Elemento' À ESTRUTURA
typedef struct produto Elemento;


// Protótipos das funções
typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, Elemento *el); // Usando Elemento
int insere_Fila(Fila* fi, Elemento el);   // Usando Elemento
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
