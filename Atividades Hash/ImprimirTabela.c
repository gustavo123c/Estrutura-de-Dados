void imprimir (No* tabela[]){
    for (int i = 0; i < TAM; i++){
        printf("indice %d:", i);
        No* aux = tabela[i]
        while ( aux != NULL){
            printf("%d" , aux-> valor);
            aux = aux -> prox;
        }
    }
}
    

