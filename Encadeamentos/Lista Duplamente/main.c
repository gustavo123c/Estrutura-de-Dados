#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main() {
    Lista* li = cria_lista(); // cria lista vazia
    int valor;

    // Inserindo no início e no final
    insere_inicio(li, 10);
    insere_inicio(li, 5);
    insere_final(li, 20);
    insere_final(li, 25);

    printf("Depois das insercoes:\n");
    imprime_lista(li);
    imprime_lista_reverso(li);

    // Removendo início e final
    remove_inicio(li);
    remove_final(li);
    printf("\nDepois das remocoes:\n");
    imprime_lista(li);

    // Consultando elemento
    if (consulta_lista_posicao(li, 2, &valor))
        printf("\nElemento na posicao 2: %d\n", valor);
    else
        printf("\nPosicao invalida!\n");

    // Buscando valor
    if (busca_valor(li, 10))
        printf("Valor 10 encontrado na lista!\n");
    else
        printf("Valor 10 nao encontrado!\n");

    // Tamanho da lista
    printf("Tamanho da lista: %d\n", tamanho_lista(li));

    // Liberando memória
    libera_lista(li);
    return 0;
}
