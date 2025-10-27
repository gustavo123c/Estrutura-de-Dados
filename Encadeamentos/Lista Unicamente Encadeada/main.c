#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista* li = cria_lista();

    printf("Lista criada.\n");

    if (lista_vazia(li))
        printf("A lista esta vazia.\n");

    insere_inicio(li, 30);
    insere_inicio(li, 20);
    insere_inicio(li, 10);
    insere_final(li, 40);
    insere_final(li, 50);

    printf("\nLista normal:\n");
    imprime_lista(li);

    printf("\nLista reversa :\n");
    imprime_lista_reverso(*li);

    int valor_busca = 30;
    if (busca_valor(li, valor_busca))
        printf("\nValor %d encontrado.\n", valor_busca);

    int pos = 3, valor_pos;
    if (consulta_lista_posicao(li, pos, &valor_pos))
        printf("Valor na posicao %d: %d\n", pos, valor_pos);

    remove_inicio(li);
    remove_final(li);

    printf("\nLista apos remocoes:\n");
    imprime_lista(li);

    libera_lista(li);
    printf("\nLista liberada.\n");

    return 0;
}
