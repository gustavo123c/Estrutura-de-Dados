#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadrado.h"

// Cria e inicializa um quadrado
Quadrado* Quadrado_Criar(float lado) {
    Quadrado *q = (Quadrado*) malloc(sizeof(Quadrado));
    if (q != NULL) {
        if (lado > 0) {
            q->lado = lado;
        } else {
            q->lado = 1; // valor padrão
            printf("Valor invalido, lado definido como 1.\n");
        }
    }
    return q;
}

// Libera memória do quadrado
void Quadrado_Destruir(Quadrado *q) {
    if (q != NULL) {
        free(q);
    }
}

// Retorna o lado
float Quadrado_ObterLado(Quadrado *q) {
    return q->lado;
}

// Retorna o perímetro
float Quadrado_Perimetro(Quadrado *q) {
    return 4 * q->lado;
}

// Retorna a área
float Quadrado_Area(Quadrado *q) {
    return q->lado * q->lado;
}

// Retorna a diagonal
float Quadrado_Diagonal(Quadrado *q) {
    return q->lado * sqrt(2);
}
