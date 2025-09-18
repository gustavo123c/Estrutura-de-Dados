#include <stdio.h>
#include "quadrado.h"

int main() {
    Quadrado *q1 = Quadrado_Criar(5);
    Quadrado *q2 = Quadrado_Criar(-2); // valor inválido → lado = 1

    printf("Quadrado 1:\n");
    printf("Lado = %.2f\n", Quadrado_ObterLado(q1));
    printf("Perimetro = %.2f\n", Quadrado_Perimetro(q1));
    printf("Area = %.2f\n", Quadrado_Area(q1));
    printf("Diagonal = %.2f\n\n", Quadrado_Diagonal(q1));

    printf("Quadrado 2:\n");
    printf("Lado = %.2f\n", Quadrado_ObterLado(q2));
    printf("Perimetro = %.2f\n", Quadrado_Perimetro(q2));
    printf("Area = %.2f\n", Quadrado_Area(q2));
    printf("Diagonal = %.2f\n", Quadrado_Diagonal(q2));

    Quadrado_Destruir(q1);
    Quadrado_Destruir(q2);

    return 0;
}
