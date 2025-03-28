#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include <string.h>  // Biblioteca para manipulação de strings
#include "lista.h"   // Cabeçalho com as definições e declarações do grafo

// Inicialização das variáveis globais
VerticeLista verticesLista[MAX_VERTICES] = {0}; // Lista de vértices
int numVerticesLista = 0;                      // Número atual de vértices no grafo

// Função para inserir um vértice no grafo
// Parâmetro: label - Nome do vértice
// Retorna: true se o vértice foi inserido com sucesso, false caso contrário
bool inserirVerticeLista(char *label) {
    if (numVerticesLista >= MAX_VERTICES) return false; // Verifica se há espaço para mais vértices
    strcpy(verticesLista[numVerticesLista].label, label); // Copia o nome do vértice
    verticesLista[numVerticesLista].exists = true; // Marca o vértice como existente
    verticesLista[numVerticesLista].listaAdj = NULL; // Inicializa a lista de adjacência como vazia
    numVerticesLista++; // Incrementa o número de vértices
    return true;
}

// Função para remover um vértice do grafo
// Parâmetro: indice - Índice do vértice a ser removido
// Retorna: true se o vértice foi removido com sucesso, false caso contrário
bool removerVerticeLista(int indice) {
    if (indice < 0 || indice >= numVerticesLista || !verticesLista[indice].exists) return false; // Verifica se o índice é válido
    verticesLista[indice].exists = false; // Marca o vértice como não existente

    // Libera a memória alocada para a lista de adjacência do vértice
    No* atual = verticesLista[indice].listaAdj;
    while (atual) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    verticesLista[indice].listaAdj = NULL; // Define a lista de adjacência como vazia

    return true;
}

// Função para inserir uma aresta no grafo
// Parâmetros: origem - Índice do vértice de origem
//             destino - Índice do vértice de destino
//             peso - Peso da aresta
// Retorna: true se a aresta foi inserida com sucesso, false caso contrário
bool inserirArestaLista(int origem, int destino, int peso) {
    if (origem < 0 || origem >= numVerticesLista || destino < 0 || destino >= numVerticesLista) return false; // Verifica se os índices são válidos
    
    // Cria um novo nó para a lista de adjacência
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->destino = destino; // Define o destino da aresta
    novoNo->peso = peso;       // Define o peso da aresta
    novoNo->prox = verticesLista[origem].listaAdj; // Insere o nó no início da lista
    verticesLista[origem].listaAdj = novoNo; // Atualiza a lista de adjacência do vértice de origem
    
    return true;
}

// Função para remover uma aresta do grafo
// Parâmetros: origem - Índice do vértice de origem
//             destino - Índice do vértice de destino
// Retorna: true se a aresta foi removida com sucesso, false caso contrário
bool removerArestaLista(int origem, int destino) {
    if (origem < 0 || origem >= numVerticesLista || destino < 0 || destino >= numVerticesLista) return false; // Verifica se os índices são válidos

    No* atual = verticesLista[origem].listaAdj; // Ponteiro para percorrer a lista de adjacência
    No* anterior = NULL; // Ponteiro para o nó anterior

    // Procura o nó correspondente à aresta
    while (atual != NULL && atual->destino != destino) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return false; // Aresta não encontrada

    // Remove o nó da lista de adjacência
    if (anterior == NULL)
        verticesLista[origem].listaAdj = atual->prox; // Remove o primeiro nó
    else
        anterior->prox = atual->prox; // Remove um nó intermediário ou final

    free(atual); // Libera a memória do nó removido
    return true;
}

// Função para imprimir a lista de adjacência do grafo
void imprimeListaAdjacencia() {
    printf("\nLista de Adjacência:\n");
    for (int i = 0; i < numVerticesLista; i++) {
        if (verticesLista[i].exists) { // Verifica se o vértice está ativo
            printf("%s -> ", verticesLista[i].label); // Imprime o rótulo do vértice
            No* atual = verticesLista[i].listaAdj; // Ponteiro para percorrer a lista de adjacência
            while (atual) {
                printf("(%s, %d) ", verticesLista[atual->destino].label, atual->peso); // Imprime o destino e o peso da aresta
                atual = atual->prox;
            }
            printf("\n");
        }
    }
}

// Função para imprimir a lista de vértices do grafo
void imprimeVerticesLista() {
    printf("\nVértices existentes (Lista de Adjacência):\n");
    for (int i = 0; i < numVerticesLista; i++) {
        if (verticesLista[i].exists) { // Verifica se o vértice está ativo
            printf("Índice %d: %s\n", i, verticesLista[i].label); // Imprime o índice e o nome do vértice
        }
    }
}

// Função para retornar os vizinhos de um vértice
// Parâmetro: vertice - Índice do vértice cujos vizinhos serão retornados
void retornarVizinhosLista(int vertice) {
    if (vertice < 0 || vertice >= numVerticesLista || !verticesLista[vertice].exists) return; // Verifica se o índice é válido
    printf("Vizinhos de %s: ", verticesLista[vertice].label);
    No* atual = verticesLista[vertice].listaAdj; // Ponteiro para percorrer a lista de adjacência
    while (atual) {
        printf("%s ", verticesLista[atual->destino].label); // Imprime o rótulo dos vizinhos
        atual = atual->prox;
    }
    printf("\n");
}

// Função para liberar a memória alocada para todas as listas de adjacência
void liberarListaAdjacencia() {
    for (int i = 0; i < numVerticesLista; i++) {
        No* atual = verticesLista[i].listaAdj; // Ponteiro para percorrer a lista de adjacência
        while (atual) {
            No* temp = atual;
            atual = atual->prox;
            free(temp); // Libera a memória de cada nó
        }
        verticesLista[i].listaAdj = NULL; // Define a lista de adjacência como vazia
    }
}
