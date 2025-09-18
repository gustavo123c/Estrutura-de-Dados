#include <stdio.h>
#include "palindromo.h" // Inclui a nossa biblioteca para ter acesso à função ehPalindromo

int main() {
    // 1. Declaramos um conjunto de palavras para testar nossa função.
    printf("--- Verificador de Palíndromos com Pilha ---\n\n");
   
      char palavra[MAX];
    printf("\nAgora voce pode testar manualmente:\n");
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (ehPalindromo(palavra)) {
        printf(" -> '%s' eh palindromo!\n", palavra);
    } else {
        printf(" -> '%s' nao eh palindromo.\n", palavra);
    }

    return 0;
}