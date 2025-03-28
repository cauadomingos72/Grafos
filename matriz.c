#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include "matriz.h"  // Cabeçalho com as definições e declarações do grafo

// Inicialização das variáveis globais
VerticeMatriz verticesMatriz[MAX_VERTICES] = {0}; // Lista de vértices
ArestaMatriz matrizAdj[MAX_VERTICES][MAX_VERTICES] = {0}; // Matriz de adjacência
int numVerticesMatriz = 0; // Número atual de vértices no grafo

// Função para inserir um vértice no grafo
// Parâmetro: label - Nome do vértice
// Retorna: true se o vértice foi inserido com sucesso, false caso contrário
bool inserirVerticeMatriz(char *label) {
    if (numVerticesMatriz >= MAX_VERTICES) return false; // Verifica se há espaço para mais vértices
    strcpy(verticesMatriz[numVerticesMatriz].label, label); // Copia o nome do vértice
    verticesMatriz[numVerticesMatriz].exists = true; // Marca o vértice como existente
    numVerticesMatriz++; // Incrementa o número de vértices
    return true;
}

// Função para remover um vértice do grafo
// Parâmetro: indice - Índice do vértice a ser removido
// Retorna: true se o vértice foi removido com sucesso, false caso contrário
bool removerVerticeMatriz(int indice) {
    if (indice < 0 || indice >= numVerticesMatriz || !verticesMatriz[indice].exists) return false; // Verifica se o índice é válido
    verticesMatriz[indice].exists = false; // Marca o vértice como não existente
    // Remove todas as arestas associadas ao vértice
    for (int i = 0; i < numVerticesMatriz; i++) {
        matrizAdj[indice][i].existe = false; // Remove arestas de saída
        matrizAdj[i][indice].existe = false; // Remove arestas de entrada
    }
    return true;
}

// Função para inserir uma aresta no grafo
// Parâmetros: origem - Índice do vértice de origem
//             destino - Índice do vértice de destino
//             peso - Peso da aresta
// Retorna: true se a aresta foi inserida com sucesso, false caso contrário
bool inserirArestaMatriz(int origem, int destino, int peso) {
    if (origem < 0 || origem >= numVerticesMatriz || destino < 0 || destino >= numVerticesMatriz) return false; // Verifica se os índices são válidos
    matrizAdj[origem][destino] = (ArestaMatriz){peso, true}; // Insere a aresta com o peso e marca como existente
    return true;
}

// Função para remover uma aresta do grafo
// Parâmetros: origem - Índice do vértice de origem
//             destino - Índice do vértice de destino
// Retorna: true se a aresta foi removida com sucesso, false caso contrário
bool removerArestaMatriz(int origem, int destino) {
    if (origem < 0 || origem >= numVerticesMatriz || destino < 0 || destino >= numVerticesMatriz) return false; // Verifica se os índices são válidos
    matrizAdj[origem][destino].existe = false; // Marca a aresta como não existente
    return true;
}

// Função para imprimir a lista de vértices do grafo
void imprimeVerticesMatriz() {
    printf("\nVértices existentes (Matriz de Adjacência):\n");
    for (int i = 0; i < numVerticesMatriz; i++) {
        if (verticesMatriz[i].exists) { // Verifica se o vértice está ativo
            printf("Índice %d: %s\n", i, verticesMatriz[i].label); // Imprime o índice e o nome do vértice
        }
    }
}

// Função para imprimir a matriz de adjacência do grafo
void imprimeMatrizAdjacencia() {
    printf("\nMatriz de Adjacência:\n   ");
    // Imprime os rótulos dos vértices na primeira linha
    for (int i = 0; i < numVerticesMatriz; i++) {
        if (verticesMatriz[i].exists) printf("%s ", verticesMatriz[i].label);
    }
    printf("\n");
    
    // Imprime as linhas da matriz de adjacência
    for (int i = 0; i < numVerticesMatriz; i++) {
        if (verticesMatriz[i].exists) { // Verifica se o vértice está ativo
            printf("%s ", verticesMatriz[i].label); // Imprime o rótulo do vértice
            for (int j = 0; j < numVerticesMatriz; j++) {
                // Imprime o peso da aresta ou um ponto se a aresta não existir
                printf(matrizAdj[i][j].existe ? "%d " : ". ", matrizAdj[i][j].peso);
            }
            printf("\n");
        }
    }
}

// Função para retornar os vizinhos de um vértice
// Parâmetro: vertice - Índice do vértice cujos vizinhos serão retornados
void retornarVizinhosMatriz(int vertice) {
    if (vertice < 0 || vertice >= numVerticesMatriz || !verticesMatriz[vertice].exists) return; // Verifica se o índice é válido
    printf("Vizinhos de %s: ", verticesMatriz[vertice].label);
    for (int i = 0; i < numVerticesMatriz; i++) {
        if (matrizAdj[vertice][i].existe) // Verifica se há uma aresta para o vizinho
            printf("%s ", verticesMatriz[i].label); // Imprime o rótulo do vizinho
    }
    printf("\n");
}
