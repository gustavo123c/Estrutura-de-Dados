#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int dado;
    struct elemento *prox;
};
typedef struct elemento Elem;
typedef Elem* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int lista_vazia(Lista* li);
int tamanho_lista(Lista* li);
int insere_inicio(Lista* li, int dado);
int insere_final(Lista* li, int dado);
int remove_inicio(Lista* li);
int remove_final(Lista* li);
void imprime_lista(Lista* li);
void imprime_lista_reverso(Elem* no);
int busca_valor(Lista* li, int valor);
int consulta_lista_posicao(Lista* li, int posicao, int *dado);