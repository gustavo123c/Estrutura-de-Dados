
#define QUADRADO_H

// Definição da estrutura Quadrado
typedef struct {
    float lado;
} Quadrado;

// Funções do TAD
void inicializarQuadrado(Quadrado *q, float lado);
float obterLado(Quadrado *q);
float calcularPerimetro(Quadrado *q);
float calcularArea(Quadrado *q);
float calcularDiagonal(Quadrado *q);

