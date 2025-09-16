#include <stdio.h>
#include <stdbool.h>
#include "pilha.h"

int verificaParenteses(const char *expressao) {
    Pilha p;
    inicializarPilha(&p);

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (c == '(') {
            empilhar(&p, c);
        } else if (c == ')') {
            if (pilhaVazia(&p)) {
                return false; // fecha sem abrir
            }
            desempilhar(&p);
        }
    }

    return pilhaVazia(&p); // só é válida se acabar vazia
}

int main() {
    const char *expressao = "((a+b) * (c-d))";

    if (verificaParenteses(expressao)) {
        printf("Expressao CORRETA\n");
    } else {
        printf("Expressao INCORRETA\n");
    }

    return 0;
}