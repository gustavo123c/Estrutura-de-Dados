#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó (cada elemento da lista)
struct elemento {
    int dado;               // valor armazenado no nó
    struct elemento *prox;  // ponteiro para o próximo nó
};

// Definições de tipos para facilitar o uso
typedef struct elemento Elem;
typedef Elem* Lista; // ponteiro para o primeiro nó

// -----------------------------------------------------------
// CRIA LISTA
// -----------------------------------------------------------
Lista* cria_lista() {
    Lista* li = malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL; // começa vazia
    return li;
}

// -----------------------------------------------------------
// LIBERA LISTA
// -----------------------------------------------------------
void libera_lista(Lista* li) {
    if (li != NULL && *li != NULL) {
        Elem* atual = *li;
        Elem* proxNo;
        do {
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;
        } while (atual != *li); // para quando der a volta
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
    if (li == NULL || *li == NULL)
        return 0;

    int count = 0;
    Elem* no = *li;
    do {
        count++;
        no = no->prox;
    } while (no != *li);
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

    if (*li == NULL) {
        *li = no;
        no->prox = no; // aponta para si mesmo
    } else {
        Elem* aux = *li;
        while (aux->prox != *li) // vai até o último nó
            aux = aux->prox;

        no->prox = *li; // novo nó aponta para o antigo primeiro
        aux->prox = no; // último nó aponta para o novo
        *li = no;       // o novo nó vira o primeiro
    }
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

    if (*li == NULL) {
        *li = no;
        no->prox = no; // lista circular de 1 elemento
    } else {
        Elem* aux = *li;
        while (aux->prox != *li)
            aux = aux->prox;

        aux->prox = no;
        no->prox = *li;
    }
    return 1;
}

// -----------------------------------------------------------
// REMOVE DO INÍCIO
// -----------------------------------------------------------
int remove_inicio(Lista* li) {
    if (li == NULL || *li == NULL)
        return 0;

    Elem* no = *li;

    if (no->prox == *li) { // só 1 elemento
        free(no);
        *li = NULL;
        return 1;
    }

    Elem* aux = *li;
    while (aux->prox != *li)
        aux = aux->prox; // acha o último nó

    aux->prox = no->prox; // último nó aponta para o segundo
    *li = no->prox;       // segundo nó vira o primeiro
    free(no);
    return 1;
}

// -----------------------------------------------------------
// REMOVE DO FINAL
// -----------------------------------------------------------
int remove_final(Lista* li) {
    if (li == NULL || *li == NULL)
        return 0;

    Elem* ant, *no = *li;

    // apenas um elemento
    if (no->prox == *li) {
        free(no);
        *li = NULL;
        return 1;
    }

    while (no->prox != *li) {
        ant = no;
        no = no->prox;
    }

    ant->prox = *li; // penúltimo aponta para o primeiro
    free(no);
    return 1;
}

// -----------------------------------------------------------
// IMPRIME LISTA
// -----------------------------------------------------------
void imprime_lista(Lista* li) {
    if (li == NULL || *li == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Elem* no = *li;
    printf("Lista: ");
    do {
        printf("%d ", no->dado);
        no = no->prox;
    } while (no != *li);
    printf("\n");
}

// -----------------------------------------------------------
// BUSCA VALOR NA LISTA
// -----------------------------------------------------------
int busca_valor(Lista* li, int valor) {
    if (li == NULL || *li == NULL)
        return 0;

    Elem* no = *li;
    do {
        if (no->dado == valor)
            return 1;
        no = no->prox;
    } while (no != *li);

    return 0;
}

// -----------------------------------------------------------
// CONSULTA POSIÇÃO
// -----------------------------------------------------------
int consulta_lista_posicao(Lista* li, int posicao, int* dado) {
    if (li == NULL || *li == NULL || posicao <= 0)
        return 0;

    Elem* no = *li;
    int count = 1;

    do {
        if (count == posicao) {
            *dado = no->dado;
            return 1;
        }
        count++;
        no = no->prox;
    } while (no != *li);

    return 0;
}
