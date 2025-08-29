float taxa_ocupacao(No* tabela[]){
    int ocupados = 0;

    for (int i = 0; i < TAM, i++){
        if (tabela[i] != NULL){
            ocupadas++;
        }
    }
    return (float)ocupados / TAM;
}