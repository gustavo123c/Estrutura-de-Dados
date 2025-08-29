void inserir_ordenado(No* tabela[], int valor) {
    int indice = valor % TAM;           // Aplica a função hash
    No* novo = criar_no(valor);         // Cria um novo nó

    No* atual = tabela[indice];
    No* anterior = NULL;

    // Encontra a posição correta para inserção ordenada
    while (atual != NULL && atual->valor < valor) {
        anterior = atual;
        atual = atual->prox;
    }

    // Caso o novo nó deva ser inserido no início
    if (anterior == NULL) {
        novo->prox = tabela[indice];    // Aponta para o atual primeiro
        tabela[indice] = novo;          // Atualiza o início da lista
    } else {
        anterior->prox = novo;          // Insere entre anterior e atual
        novo->prox = atual;
    }
}