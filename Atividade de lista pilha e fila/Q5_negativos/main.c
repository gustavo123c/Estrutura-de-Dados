#include <stdio.h>
#include "filaNegativos.h"

int main() {
    Fila f;              // cria a fila
    inicializar(&f);     // inicializa a fila (vazia)

    // Inserindo elementos na fila
    enfileirar(&f, 5);   // insere 5
    enfileirar(&f, -3);  // insere -3
    enfileirar(&f, 8);   // insere 8
    enfileirar(&f, -1);  // insere -1
    enfileirar(&f, 10);  // insere 10

    printf("Fila original:\n");
    mostrarFila(&f);     // mostra a fila antes da remoção dos negativos

    excluirNegativos(&f); // remove os números negativos

    printf("Fila sem negativos:\n");
    mostrarFila(&f);     // mostra a fila final

    return 0; // fim do programa
}