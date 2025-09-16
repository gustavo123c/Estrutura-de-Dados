#include <stdio.h>
#include <math.h>
#include "quadrado.h"

// Inicializa o quadrado com um valor para o lado
void inicializarQuadrado(Quadrado *q, float lado) {
    if (lado > 0) {
        q->lado = lado;
    } else {
        q->lado = 1; // valor padrão caso seja inválido
        printf("Valor invalido, lado definido como 1.\n");
    }
}

// Retorna o valor do lado
float obterLado(Quadrado *q) {
    return q->lado;
}

// Retorna o perímetro (4 * lado)
float calcularPerimetro(Quadrado *q) {
    return 4 * q->lado;
}

// Retorna a área (lado^2)
float calcularArea(Quadrado *q) {
    return q->lado * q->lado;
}

// Retorna a diagonal (lado * sqrt(2))
float calcularDiagonal(Quadrado *q) {
    return q->lado * sqrt(2);
}