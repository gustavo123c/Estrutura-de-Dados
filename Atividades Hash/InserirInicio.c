void inserir (No* tabela[], int valor){
    int indice = valor % TAM;
    No* novo = (No*) malloc(sizeof(No));
    novo -> valor = valor;
    novo -> prox = tabela[indice];
    tabela [indice] = novo;

}