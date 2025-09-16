#include <stdio.h>  // Biblioteca padrão
#include "filaInversa.h"   // Inclui a fila

int main() {
    Fila f;                        // Declara uma fila
    inicializarFila(&f);           // Inicializa a fila

    // Insere valores na fila
    enfileirar(&f, 10);            // Adiciona 10
    enfileirar(&f, 20);            // Adiciona 20
    enfileirar(&f, 30);            // Adiciona 30
    enfileirar(&f, 40);            // Adiciona 40
    enfileirar(&f, 50);            // Adiciona 50

    printf("Fila original:\n");    // Mostra texto
    exibirFila(&f);                // Exibe a fila atual

    reverso(&f);                   // Chama a função para inverter

    printf("Fila invertida:\n");   // Mostra texto
    exibirFila(&f);                // Exibe a fila invertida

    return 0;                      // Finaliza o programa
}
