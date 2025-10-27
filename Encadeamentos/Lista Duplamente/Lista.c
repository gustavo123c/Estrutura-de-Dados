#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista duplamente encadeada
struct elemento {
    int dado;                 // valor armazenado no nó
    struct elemento *prox;    // ponteiro para o próximo nó
    struct elemento *ant;     // ponteiro para o nó anterior
};

// Definições de tipos para facilitar o uso
typedef struct elemento Elem;
typedef Elem* Lista;  // ponteiro para o primeiro nó

// -----------------------------------------------------------
// CRIA LISTA
// -----------------------------------------------------------
Lista* cria_lista() {
    Lista* li = malloc(sizeof(Lista));  // aloca espaço para o ponteiro da lista
    if (li != NULL)
        *li = NULL;  // lista começa vazia
    return li;
}

// -----------------------------------------------------------
// LIBERA LISTA
// -----------------------------------------------------------
void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;
        while (*li != NULL) {
            no = *li;
            *li = no->prox;  // avança para o próximo
            free(no);
        }
        free(li);
    }
}

// -----------------------------------------------------------
// VERIFICA SE A LISTA ESTÁ VAZIA
// -----------------------------------------------------------
int lista_vazia(Lista* li) {
    if (li == NULL || *li == NULL)
        return 1;
    return 0;
}

// -----------------------------------------------------------
// RETORNA TAMANHO DA LISTA
// -----------------------------------------------------------
int tamanho_lista(Lista* li) {
    if (li == NULL)
        return -1;

    int count = 0;
    Elem* no = *li;
    while (no != NULL) {
        count++;
        no = no->prox;
    }
    return count;
}

// -----------------------------------------------------------
// INSERE NO INÍCIO
// -----------------------------------------------------------
int insere_inicio(Lista* li, int dado) {
    if (li == NULL)
        return 0;

    Elem* no = malloc(sizeof(Elem));
    if (no == NULL)
        return 0;

    no->dado = dado;
    no->prox = *li;
    no->ant = NULL;

    if (*li != NULL)
        (*li)->ant = no;  // o antigo primeiro agora aponta para o novo
    *li = no;             // o novo nó vira o primeiro
    return 1;
}

// -----------------------------------------------------------
// INSERE NO FINAL
// -----------------------------------------------------------
int insere_final(Lista* li, int dado) {
    if (li == NULL)
        return 0;

    Elem* no = malloc(sizeof(Elem));
    if (no == NULL)
        return 0;

    no->dado = dado;
    no->prox = NULL;

    if (*li == NULL) {
        no->ant = NULL;
        *li = no;
        return 1;
    }

    Elem* aux = *li;
    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = no;
    no->ant = aux;
    return 1;
}

// -----------------------------------------------------------
// REMOVE DO INÍCIO
// -----------------------------------------------------------
int remove_inicio(Lista* li) {
    if (li == NULL || *li == NULL)
        return 0;

    Elem* no = *li;
    *li = no->prox;

    if (*li != NULL)
        (*li)->ant = NULL;  // o novo primeiro não tem anterior

    free(no);
    return 1;
}

// -----------------------------------------------------------
// REMOVE DO FINAL
// -----------------------------------------------------------
int remove_final(Lista* li) {
    if (li == NULL || *li == NULL)
        return 0;

    Elem* no = *li;

    // apenas 1 elemento
    if (no->prox == NULL) {
        free(no);
        *li = NULL;
        return 1;
    }

    // vai até o último
    while (no->prox != NULL)
        no = no->prox;

    no->ant->prox = NULL;
    free(no);
    return 1;
}

// -----------------------------------------------------------
// IMPRIME LISTA DO INÍCIO AO FIM
// -----------------------------------------------------------
void imprime_lista(Lista* li) {
    if (li == NULL || *li == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Elem* no = *li;
    printf("Lista: ");
    while (no != NULL) {
        printf("%d ", no->dado);
        no = no->prox;
    }
    printf("\n");
}

// -----------------------------------------------------------
// IMPRIME LISTA DO FIM AO INÍCIO
// -----------------------------------------------------------
void imprime_lista_reverso(Lista* li) {
    if (li == NULL || *li == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Elem* no = *li;
    // vai até o último nó
    while (no->prox != NULL)
        no = no->prox;

    printf("Lista reversa: ");
    // volta imprimindo
    while (no != NULL) {
        printf("%d ", no->dado);
        no = no->ant;
    }
    printf("\n");
}

// -----------------------------------------------------------
// BUSCA UM VALOR NA LISTA
// -----------------------------------------------------------
int busca_valor(Lista* li, int valor) {
    if (li == NULL || *li == NULL)
        return 0;

    Elem* no = *li;
    while (no != NULL) {
        if (no->dado == valor)
            return 1;
        no = no->prox;
    }
    return 0;
}

// -----------------------------------------------------------
// CONSULTA UM ELEMENTO PELA POSIÇÃO
// -----------------------------------------------------------
int consulta_lista_posicao(Lista* li, int posicao, int* dado) {
    if (li == NULL || *li == NULL || posicao <= 0)
        return 0;

    Elem* no = *li;
    int count = 1;

    while (no != NULL && count < posicao) {
        no = no->prox;
        count++;
    }

    if (no == NULL)
        return 0;

    *dado = no->dado;
    return 1;
}
