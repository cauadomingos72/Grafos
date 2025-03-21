#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define MAX_VERTICES 100 // Número máximo de vértices permitidos
#define INF 99999 // Representação de um peso infinito para arestas inexistentes

// Macro para verificar se um índice de vértice é válido
#define VALIDO(i) (i >= 0 && i < numVertices && vertices[i].exists)

// Estrutura para representar um vértice
typedef struct {
    char label[50];
    bool exists;
} Vertice;

// Estrutura para representar uma aresta
typedef struct {
    int peso;
    bool existe;
} Aresta;

// Declaração de estruturas para armazenar os vértices e a matriz de adjacência
Vertice vertices[MAX_VERTICES] = {0};
Aresta matrizAdj[MAX_VERTICES][MAX_VERTICES] = {0};
int numVertices = 0;

// Função para inserir um novo vértice no grafo
bool inserirVertice(char *label) {
    if (numVertices >= MAX_VERTICES) return false; // Verifica se atingiu o limite máximo de vértices
    strcpy(vertices[numVertices].label, label); // Copia o rótulo fornecido para o vetor de vértices
    vertices[numVertices].exists = true; // Marca o vértice como existente
    numVertices++; // Incrementa o número de vértices
    return true;
}

// Função para remover um vértice do grafo
bool removerVertice(int indice) {
    if (!VALIDO(indice)) return false; // Verifica se o índice é válido
    vertices[indice].exists = false; // Marca o vértice como inexistente
    for (int i = 0; i < numVertices; i++) { // Remove todas as arestas associadas ao vértice
        matrizAdj[indice][i].existe = false;
        matrizAdj[i][indice].existe = false;
    }
    return true;
}

// Retorna o rótulo de um vértice a partir do seu índice
char* labelVertice(int indice) {
    return VALIDO(indice) ? vertices[indice].label : NULL;
}

// Exibe os vértices existentes e seus respectivos índices
void imprimeVertices() {
    printf("\nVértices existentes:\n");
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i].exists) {
            printf("Índice %d: %s\n", i, vertices[i].label);
        }
    }
}

// Imprime a matriz de adjacência representando o grafo
void imprimeMatrizAdjacencia() {
    printf("\nMatriz de Adjacência:\n   ");
    for (int i = 0; i < numVertices; i++) { // Imprime os rótulos dos vértices como cabeçalho da matriz
        if (vertices[i].exists) printf("%s ", vertices[i].label);
    }
    printf("\n");
    
    for (int i = 0; i < numVertices; i++) { // Imprime a matriz linha por linha
        if (vertices[i].exists) {
            printf("%s ", vertices[i].label); // Nome do vértice na lateral da matriz
            for (int j = 0; j < numVertices; j++) {
                printf(matrizAdj[i][j].existe ? "%d " : ". ", matrizAdj[i][j].peso);
            }
            printf("\n");
        }
    }
}

// Imprime a lista de adjacência do grafo
void imprimeListaAdjacencia() {
    printf("\nLista de Adjacência:\n");
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i].exists) {
            printf("%s -> ", vertices[i].label);
            for (int j = 0; j < numVertices; j++) {
                if (matrizAdj[i][j].existe) {
                    printf("(%s, %d) ", vertices[j].label, matrizAdj[i][j].peso);
                }
            }
            printf("\n");
        }
    }
}

// Adiciona uma aresta entre dois vértices com um determinado peso
bool inserirAresta(int origem, int destino, int peso) {
    if (!VALIDO(origem) || !VALIDO(destino)) return false; // Verifica se os índices são válidos
    matrizAdj[origem][destino] = (Aresta){peso, true}; // Define a aresta na matriz de adjacência
    return true;
}

// Remove uma aresta entre dois vértices
bool removerAresta(int origem, int destino) {
    if (!VALIDO(origem) || !VALIDO(destino)) return false; // Verifica se os índices são válidos
    matrizAdj[origem][destino].existe = false; // Marca a aresta como inexistente
    return true;
}

// Retorna o peso de uma aresta entre dois vértices
int pesoAresta(int origem, int destino) {
    return VALIDO(origem) && VALIDO(destino) && matrizAdj[origem][destino].existe ? matrizAdj[origem][destino].peso : INF;
}

// Exibe os vizinhos de um vértice específico
void retornarVizinhos(int vertice) {
    if (!VALIDO(vertice)) return;
    printf("Vizinhos de %s: ", vertices[vertice].label);
    for (int i = 0; i < numVertices; i++) {
        if (matrizAdj[vertice][i].existe)
            printf("%s ", vertices[i].label);
    }
    printf("\n");
}

// Menu interativo para manipulação do grafo
void menu() {
    int opcao, origem, destino, peso;
    char label[50];
    while (1) {
        printf("\nMENU:\n");
        printf("1. Adicionar Vértice\n2. Remover Vértice\n3. Adicionar Aresta\n4. Remover Aresta\n");
        printf("5. Imprimir Matriz e Lista de Adjacência\n6. Mostrar Vizinhos\n7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o rótulo do vértice: ");
                scanf("%s", label);
                inserirVertice(label);
                break;
            case 2:
                imprimeVertices();
                printf("Digite o índice do vértice a remover: ");
                scanf("%d", &origem);
                removerVertice(origem);
                break;
            case 3:
                imprimeVertices();
                printf("Origem: "); scanf("%d", &origem);
                printf("Destino: "); scanf("%d", &destino);
                printf("Peso: "); scanf("%d", &peso);
                inserirAresta(origem, destino, peso);
                break;
            case 4:
                imprimeVertices();
                printf("Origem: "); scanf("%d", &origem);
                printf("Destino: "); scanf("%d", &destino);
                removerAresta(origem, destino);
                break;
            case 5:
                imprimeMatrizAdjacencia();
                imprimeListaAdjacencia();
                break;
            case 6:
                imprimeVertices();
                printf("Digite o índice do vértice: ");
                scanf("%d", &origem);
                retornarVizinhos(origem);
                break;
            case 7:
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }
}

// Função principal
int main() {
    setlocale(LC_ALL, "pt_BR.utf8");
    SetConsoleOutputCP(65001);
    inserirVertice("A");
    inserirVertice("B");
    inserirVertice("C");
    inserirAresta(0, 1, 2);
    inserirAresta(1, 2, 3);
    inserirAresta(2, 0, 4);
    menu();
    return 0;
}