#include <stdio.h>

float imc(float peso, float altura) {
    float X = peso / (altura * altura); 
    return X; 
}
int main() {
    float peso, altura, resultado;

    printf("Digite o peso em kg: ");
    scanf("%f", &peso);

    printf("Digite a altura em m: ");
    scanf("%f", &altura);


    resultado = imc(peso, altura);
    
    
    printf("O IMC = %.2f\n", resultado);

    return 0;
}