int contar_elementos(No* tabela[]) {
    int total = 0;
    for (int i = 0; i < TAM; i++){
        No* aux = tabela[i];
        while (aux != NULL){
            total++;
            aux = aux -> novo;
        }
    }
    return total;
}