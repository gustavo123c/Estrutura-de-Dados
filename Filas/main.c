#include <stdio.h>
#include "filaEstatica.h"

int main(void){
    Fila *f = cria_Fila();
    if (f == NULL){
        printf("Erro ao criar fila.\n");
        return 1;
    }

    printf("Fila de produtos criada.\n");
    printf("Tamanho inicial: %d\n", tamanho_Fila(f));
    printf("Esta vazia? ");
    if (Fila_vazia(f)){
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    /* produtos de exemplo */
    Elemento p1  = {101, "Carne", 40.00f  };
    Elemento p2  = {202, "Cenoura", 2.50f };
    Elemento p3  = {303, "Ovo", 10.00f };

    Elemento frente;

    // Enfileirar 1 a 1
    printf("\nInserindo produto...\n");
    insere_Fila(f, p1);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Frente: Codigo %d, Desc: %s, Preco: R$%.2f\n", frente.codigo, frente.descricao, frente.preco);
    }

    printf("\nInserindo produto...\n");
    insere_Fila(f, p2);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Frente: Codigo %d, Desc: %s, Preco: R$%.2f\n", frente.codigo, frente.descricao, frente.preco);
    }

    printf("\nInserindo produto...\n");
    insere_Fila(f, p3);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Frente: Codigo %d, Desc: %s, Preco: R$%.2f\n", frente.codigo, frente.descricao, frente.preco);
    }

    printf("\nEsta vazia? ");
    if (Fila_vazia(f)){
        printf("Sim\n");
    } else {
        printf("Nao | Tamanho: %d\n", tamanho_Fila(f));
    }

    // Remover 1 a 1 (sempre remove do INICIO)
    printf("\nRemovendo do inicio...\n");
    if (consulta_Fila(f, &frente)){
        printf("Removendo: Codigo %d, Desc: %s, Preco: R$%.2f\n", frente.codigo, frente.descricao, frente.preco);
    }
    remove_Fila(f);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Novo frente: Codigo %d, Desc: %s, Preco: R$%.2f\n", frente.codigo, frente.descricao, frente.preco);
    }

    printf("\nRemovendo do inicio...\n");
    if (consulta_Fila(f, &frente)){
        printf("Removendo: Codigo %d, Desc: %s, Preco: R$%.2f\n", frente.codigo, frente.descricao, frente.preco);
    }
    remove_Fila(f);
    printf("Tamanho: %d\n", tamanho_Fila(f));
    if (consulta_Fila(f, &frente)){
        printf("Novo frente: Codigo %d, Desc: %s, Preco: R$%.2f\n", frente.codigo, frente.descricao, frente.preco);
    }

    printf("\nRemovendo do inicio...\n");
    if (consulta_Fila(f, &frente)){
        printf("Removendo: Codigo %d, Desc: %s, Preco: R$%.2f\n", frente.codigo, frente.descricao, frente.preco);
    }
    remove_Fila(f);
    printf("Tamanho: %d\n", tamanho_Fila(f));

    printf("\nEsta vazia? ");
    if (Fila_vazia(f)){
        printf("Sim\n");
    } else {
        printf("Nao | Tamanho: %d\n", tamanho_Fila(f));
    }

    libera_Fila(f);
    printf("\nFila liberada.\n");
    return 0;
}