#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncad.h" // Inclui os protótipos

// Definição do tipo nó (elemento da lista)
struct elemento {
    struct aluno dados;   // Dados do aluno
    struct elemento *prox; // Ponteiro para o próximo nó
};

typedef struct elemento Elem;

// Cria uma nova lista (ponteiro para o primeiro elemento)
Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL; // Inicializa como vazia
    return li;
}

// Libera todos os nós da lista
void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

// Retorna a quantidade de nós (O(n))
int tamanho_lista(Lista* li) {
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

// Lista dinâmica nunca "enche"
int lista_cheia(Lista* li) {
    return 0;
}

// ✅ Retorna 1 se a lista estiver vazia, 0 caso contrário
int lista_vazia(Lista* li) {
    if (li == NULL)
        return 1; // Ponteiro nulo: lista inválida (considera vazia)
    if (*li == NULL)
        return 1; // Nenhum elemento: lista vazia
    return 0;
}

// Insere um novo nó no início da lista
int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

// Insere um novo nó no final da lista
int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if ((*li) == NULL) { // Lista vazia: insere no início
        *li = no;
    } else {
        Elem *aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

// Insere de forma ordenada pela matrícula
int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    if ((*li) == NULL) { // Lista vazia: insere no início
        no->prox = NULL;
        *li = no;
        return 1;
    } else {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula) {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li) { // Insere no início
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

// Remove o primeiro nó da lista
int remove_lista_inicio(Lista* li) {
    if (li == NULL || *li == NULL)
        return 0;
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

// Remove o último nó da lista
int remove_lista_final(Lista* li) {
    if (li == NULL || *li == NULL)
        return 0;

    Elem *ant, *no = *li;
    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }
    if (no == (*li)) // Só um elemento
        *li = no->prox;
    else
        ant->prox = no->prox;

    free(no);
    return 1;
}

// Remove nó pela matrícula
int remove_lista(Lista* li, int mat) {
    if (li == NULL || *li == NULL)
        return 0;
    Elem *ant, *no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }
    if (no == NULL)
        return 0; // Não encontrado
    if (no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

// Busca elemento pela posição (1..n)
int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return 0;
    *al = no->dados;
    return 1;
}

// ✅ Busca elemento pela matrícula
int busca_lista_mat(Lista* li, int mat, struct aluno *al) {
    if (li == NULL)
        return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        no = no->prox;
    }
    if (no == NULL)
        return 0; // Não encontrado
    *al = no->dados;
    return 1;
}
