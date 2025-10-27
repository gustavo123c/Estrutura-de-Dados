#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main() {
    Lista* li = cria_lista();
    int valor;

    insere_inicio(li, 10);
    insere_inicio(li, 5);
    insere_final(li, 20);
    insere_final(li, 25);

    printf("Depois das insercoes:\n");
    imprime_lista(li);

    printf("Tamanho: %d\n", tamanho_lista(li));

    remove_inicio(li);
    remove_final(li);

    printf("\nDepois das remocoes:\n");
    imprime_lista(li);

    if (busca_valor(li, 10))
        printf("\nValor 10 encontrado na lista.\n");
    else
        printf("\nValor 10 nao encontrado.\n");

    if (consulta_lista_posicao(li, 2, &valor))
        printf("Elemento na posicao 2: %d\n", valor);
    else
        printf("Posicao invalida.\n");

    libera_lista(li);
    return 0;
}
