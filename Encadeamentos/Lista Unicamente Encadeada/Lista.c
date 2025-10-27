#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó (cada elemento da lista)
struct elemento{
    int dado;                // valor armazenado no no
    struct elemento *prox;   // ponteiro para o proximo no
};

// Definicoes de tipos para facilitar o uso
typedef struct elemento Elem;   // apelido para struct elemento
typedef Elem* Lista;            // Lista e um ponteiro para o primeiro no

// -----------------------------------------------------------
// CRIA LISTA
// -----------------------------------------------------------
Lista* cria_lista (){
    Lista *li = malloc(sizeof(Lista)); // aloca espaco para um ponteiro para o primeiro no
    if (li != NULL)
        *li = NULL; // lista comeca vazia (sem elementos)
    return li;      // retorna o endereco da lista criada
}


void libera_lista (Lista *li){
    if (li != NULL){ 
        Elem *no;
        while (*li != NULL){      // enquanto existir no na lista
            no = *li;             // guarda o endereco do primeiro no
            *li = no->prox;       // avanca para o proximo no
            free(no);             // libera o no atual
        }
        free(li); // libera o ponteiro principal da lista
    }
}

// -----------------------------------------------------------
// VERIFICA SE A LISTA ESTA VAZIA
// -----------------------------------------------------------
int lista_vazia (Lista *li){
    if (li == NULL || *li == NULL) // se a lista nao foi criada ou nao tem elementos
        return 1;   // lista vazia
    return 0;       // lista contem elementos
}


int tamanho_lista (Lista *li){
    if (li == NULL) // se a lista nao existe
        return -1;

    int count = 0;       // cria um contador
    Elem *no = *li;      // aponta para o primeiro elemento da lista
    while (no != NULL){  // enquanto nao chegar ao fim
        count++;          // incrementa o contador
        no = no->prox;    // passa para o proximo elemento
    }
    return count; // retorna o total de elementos
}


int insere_inicio (Lista *li, int dado){
    if (li == NULL)       // verifica se a lista foi criada
        return 0;

    Elem *no = malloc(sizeof(Elem)); // aloca um novo no
    if (no == NULL)       // verifica se a alocacao deu certo
        return 0;

    no->dado = dado;  // armazena o valor no campo dado
    no->prox = *li;   // o novo no aponta para o antigo primeiro
    *li = no;         // atualiza o inicio da lista
    return 1;         // sucesso
}


int insere_final (Lista *li, int dado){
    if (li == NULL) 
        return 0;

    Elem *no = malloc(sizeof(Elem)); // cria um novo no
    if (no == NULL)
        return 0;

    no->dado = dado;  // armazena o valor
    no->prox = NULL;  // ultimo no sempre aponta para NULL

    if (*li == NULL){  // se a lista estiver vazia
        *li = no;      // o novo no vira o primeiro
        return 1;
    }

    // percorre ate o ultimo no existente
    Elem *aux = *li;
    while (aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = no; // o ultimo elemento agora aponta para o novo
    return 1;
}


int remove_inicio (Lista *li){
    if (li == NULL || *li == NULL){ // verifica se a lista existe e nao esta vazia
        return 0;
    }

    Elem *no = *li;   // guarda o endereco do primeiro no
    *li = no->prox;   // faz o inicio apontar para o segundo no
    free(no);         // libera o antigo primeiro no
    return 1;         // sucesso
}


int remove_final (Lista *li){
    if (li == NULL || *li == NULL)
        return 0; // lista nao existe ou esta vazia

    Elem *ant, *no = *li;

    // Caso especial: apenas 1 elemento
    if (no->prox == NULL){
        free(no);
        *li = NULL; // lista agora fica vazia
        return 1;
    }

    // percorre ate o ultimo, guardando o anterior
    while (no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    ant->prox = NULL; // o penultimo agora e o ultimo
    free(no);         // libera o antigo ultimo no
    return 1;
}


void imprime_lista(Lista *li){
    if (li == NULL || *li == NULL){
        printf("Lista vazia.\n");
        return;
    }

    Elem *no = *li;
    printf("Lista: ");
    while(no != NULL){
        printf("%d ", no->dado);
        no = no->prox;
    }
    printf("\n");
}


void imprime_lista_reverso(Lista* li){
    if(li == NULL || *li == NULL){
        printf("Lista vazia.\n");
        return;
    }

    Elem* no = *li;
    int tamanho = 0;

    // Primeiro, contamos quantos elementos tem
    while(no != NULL){
        tamanho++;
        no = no->prox;
    }

    // Criamos um vetor temporario para guardar os dados
    int* dados = malloc(tamanho * sizeof(int));

    // Voltamos ao inicio e armazenamos os valores no vetor
    no = *li;
    for(int i = 0; i < tamanho; i++){
        dados[i] = no->dado;
        no = no->prox;
    }

    // Agora imprimimos o vetor de tras pra frente
    printf("Lista reversa: ");
    for(int i = tamanho - 1; i >= 0; i--){
        printf("%d ", dados[i]);
    }
    printf("\n");

    free(dados); // liberamos o vetor temporario
}


int busca_valor (Lista *li, int valor){
    if (li == NULL || *li == NULL)
        return 0;

    Elem* no = *li;
    while (no != NULL){
        if (no->dado == valor) // achou o valor
            return 1;
        no = no->prox; // avanca para o proximo
    }
    return 0; // nao encontrou
}


int consulta_lista_posicao(Lista* li, int posicao, int *dado){
    if(li == NULL || *li == NULL || posicao <= 0)
        return 0;

    Elem* no = *li; // guarda o primeiro no
    int count = 1;  // contador de posicao

    while (no != NULL && count < posicao){
        no = no->prox; // avanca
        count++;
    }

    if (no == NULL) // posicao invalida
        return 0;

    *dado = no->dado; // retorna o valor encontrado
    return 1;
}
