#include <stdio.h>
#include "palindromo.h" // Inclui a nossa biblioteca para ter acesso à função ehPalindromo

int main() {
    // 1. Declaramos um conjunto de palavras para testar nossa função.
    printf("--- Verificador de Palíndromos com Pilha ---\n\n");
    printf("Testando palavras que devem ser palíndromos:\n");
    
    char p1[] = "arara";
    char p2[] = "osso";    // Palíndromo de tamanho par
    char p3[] = "reviver";
    char p4[] = "anilina";

    if (ehPalindromo(p1)) {
        printf(" -> A palavra '%s' É um palíndromo.\n", p1);
    } else {
        printf(" -> A palavra '%s' NÃO é um palíndromo. (ERRO)\n", p1);
    }
    
    if (ehPalindromo(p2)) {
        printf(" -> A palavra '%s' É um palíndromo.\n", p2);
    } else {
        printf(" -> A palavra '%s' NÃO é um palíndromo. (ERRO)\n", p2);
    }

    if (ehPalindromo(p3)) {
        printf(" -> A palavra '%s' É um palíndromo.\n", p3);
    } else {
        printf(" -> A palavra '%s' NÃO é um palíndromo. (ERRO)\n", p3);
    }

    if (ehPalindromo(p4)) {
        printf(" -> A palavra '%s' É um palíndromo.\n", p4);
    } else {
        printf(" -> A palavra '%s' NÃO é um palíndromo. (ERRO)\n", p4);
    }
    
    // 2. Testando palavras que NÃO devem ser palíndromos
    printf("\nTestando palavras que NÃO devem ser palíndromos:\n");

    char p5[] = "casa";
    char p6[] = "abacaxi";

    if (ehPalindromo(p5)) {
        printf(" -> A palavra '%s' É um palíndromo. (ERRO)\n", p5);
    } else {
        printf(" -> A palavra '%s' NÃO é um palíndromo.\n", p5);
    }
    
    if (ehPalindromo(p6)) {
        printf(" -> A palavra '%s' É um palíndromo. (ERRO)\n", p6);
    } else {
        printf(" -> A palavra '%s' NÃO é um palíndromo.\n", p6);
    }

    // 3. Testando casos que demonstram as limitações do código
    printf("\nTestando casos que mostram as limitações (sensibilidade a maiúsculas e espaços):\n");
    
    char p7[] = "Radar"; // Letra maiúscula no início
    
    if (ehPalindromo(p7)) {
        printf(" -> A palavra '%s' É um palíndromo. (ERRO)\n", p7);
    } else {
        printf(" -> A palavra '%s' NÃO é um palíndromo (porque 'R' != 'r').\n", p7);
    }

    // 4. Retornamos 0 para indicar que o programa foi executado com sucesso.
    return 0;
}