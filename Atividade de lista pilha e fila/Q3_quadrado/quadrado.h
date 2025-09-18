#define QUADRADO_H

// Estrutura do Quadrado
typedef struct {
    float lado;
} Quadrado;

// Cria e inicializa um quadrado
Quadrado* Quadrado_Criar(float lado);

// Libera memória do quadrado
void Quadrado_Destruir(Quadrado *q);

// Retorna o lado do quadrado
float Quadrado_ObterLado(Quadrado *q);

// Retorna o perímetro do quadrado
float Quadrado_Perimetro(Quadrado *q);

// Retorna a área do quadrado
float Quadrado_Area(Quadrado *q);

// Retorna a diagonal do quadrado
float Quadrado_Diagonal(Quadrado *q);
