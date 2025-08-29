int contar_colisoes(No* tabela[]) {
    int colisoes = 0;
    for (int i = 0; i < TAM; i++){
        No* aux = tabela[i];
        int count = 0;
        while(aux != NULL){
            aux = aux -> prox;
            count++

        }
        if (count > 1){
            colisoes += count -1
        }
    }
}    