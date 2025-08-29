int chave_existe(No* tabela[], int valor){
    int indice = valor % TAM;
    No* aux = tabela[indice];

    while (aux != NULL){
        if(aux -> valor == valor){ // se o valor for encontrado
            return 1;
            aux = aux -> prox;  //vai para o proximo no
        }
    }
    return 0;
}