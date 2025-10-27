#include <stdio.h>   // Biblioteca padrão
#include "filaInversa.h"   // Inclui a fila

int main() {
    Fila *f = criar_fila();        // Cria e inicializa a fila dinamicamente
    if (f == NULL) {
        printf("Erro ao criar a fila!\n");
        return 1;
    }

    // Insere valores na fila
    enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 30);
    enfileirar(f, 40);
    enfileirar(f, 50);

    printf("Fila original:\n");
    exibirFila(f);

    reverso(f);  // Inverte a fila

    printf("Fila invertida:\n");
    exibirFila(f);

    return 0;
}
