#include <stdio.h>
#include "pilha.h"  // cabeçalho da pilha

int main() {
    char expressao[100];
    
    printf("Digite sua expressao:\n");
    scanf("%s", expressao);

    if (verificarExpressao(expressao)) {
        printf("Expressao CORRETA!\n");
    } else {
        printf("Expressao INCORRETA!\n");
    }

    return 0;
}
