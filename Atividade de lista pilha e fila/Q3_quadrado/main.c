#include <stdio.h>
#include "quadrado.h"

int main(void) {
    Quadrado q;
    float lado;

    printf("Digite o valor do lado do quadrado: ");
    if (scanf("%f", &lado) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    inicializarQuadrado(&q, lado);

    printf("\n--- Informacoes do Quadrado ---\n");
    printf("Lado: %.2f\n", obterLado(&q));
    printf("Perimetro: %.2f\n", calcularPerimetro(&q));
    printf("Area: %.2f\n", calcularArea(&q));
    printf("Diagonal: %.2f\n", calcularDiagonal(&q));

    return 0;
}
