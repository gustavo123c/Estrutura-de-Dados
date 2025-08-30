#include <stdio.h>


float imc(float *peso, float *altura) {
    float X = *peso / (*altura * *altura); 
    return X;
}

int main() {
    float peso, altura, resultado;
    float *ptrPeso, *ptrAltura; 

    ptrPeso = &peso;
    ptrAltura = &altura;


    printf("Digite o peso em kg: ");
    scanf("%f", ptrPeso); 

    printf("Digite a altura em m: ");
    scanf("%f", ptrAltura);


    resultado = imc(ptrPeso, ptrAltura);

    
    printf("O IMC = %.2f\n", resultado);

    return 0;
}
