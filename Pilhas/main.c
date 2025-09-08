#include <stdio.h>
#include "pilhaSequencial.h"

int main(void){
    Pilha *p = cria_Pilha();
    if (p == NULL){
        printf("Erro ao criar pilha.\n");
        return 1;
    }

    printf("Pilha criada.\n");
    printf("Tamanho inicial: %d\n", tamanho_Pilha(p));
    printf("Esta vazia? ");
    if (Pilha_vazia(p)){
        printf("Sim\n"); 
    }        
    else{
        printf("Nao\n");
    } 
        

    /* alunos de exemplo */
    struct aluno a1 = {101, "Ana",   8.0f, 7.5f, 9.0f};
    struct aluno a2 = {202, "Bruno", 6.0f, 8.0f, 7.0f};
    struct aluno a3 = {303, "Clara", 9.0f, 9.5f, 8.5f};

    struct aluno topo;

    // Pilhar 1 a 1
    printf("\nInserindo Aluno...\n");
    insere_Pilha(p, a1);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Topo: %d - %s\n", topo.matricula, topo.nome);
    }
        

    printf("\nInserindo Aluno...\n");
    insere_Pilha(p, a2);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Topo: %d - %s\n", topo.matricula, topo.nome);
    }
        
    printf("\nInserindo Aluno...\n");
    insere_Pilha(p, a3);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Topo: %d - %s\n", topo.matricula, topo.nome);
    }
        

    printf("\nEsta vazia? ");
    if (Pilha_vazia(p)){
        printf("Sim\n"); 
    }        
    else{
        printf("Nao | Tamanho: %d\n", tamanho_Pilha(p));
    }
        
        
    // Remover 1 a 1
    printf("\nRemovendo do topo...\n");
    if (acessa_topo_Pilha(p, &topo)){
        printf("Removendo: %d - %s\n", topo.matricula, topo.nome);
    }
    remove_Pilha(p);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Novo topo: %d - %s\n", topo.matricula, topo.nome);
    }

    printf("\nRemovendo do topo...\n");
    if (acessa_topo_Pilha(p, &topo)){
        printf("Removendo: %d - %s\n", topo.matricula, topo.nome);
    }
    remove_Pilha(p);
    printf("Tamanho: %d\n", tamanho_Pilha(p));
    if (acessa_topo_Pilha(p, &topo)){
        printf("Novo topo: %d - %s\n", topo.matricula, topo.nome);
    }

    printf("\nRemovendo do topo...\n");
    if (acessa_topo_Pilha(p, &topo)){
        printf("Removendo: %d - %s\n", topo.matricula, topo.nome);
    }
    remove_Pilha(p);
    printf("Tamanho: %d\n", tamanho_Pilha(p));

    printf("\nEsta vazia? ");
    if (Pilha_vazia(p)){
        printf("Sim\n"); 
    }         
    else{
        printf("Nao | Tamanho: %d\n", tamanho_Pilha(p));
    } 

    libera_Pilha(p);
    printf("\nPilha liberada.\n");
    return 0;
}