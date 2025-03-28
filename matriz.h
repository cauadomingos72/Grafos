#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include <stdlib.h>  // Biblioteca para alocação de memória e funções gerais
#include <stdbool.h> // Biblioteca para usar o tipo booleano (true/false)
#include <string.h>  // Biblioteca para manipulação de strings

// Define o número máximo de vértices no grafo
#define MAX_VERTICES 100

// Define um valor que representa "infinito", usado para pesos de arestas
#define INF 99999

// Estrutura que representa um vértice no grafo
typedef struct {
    char label[50]; // Nome ou rótulo do vértice
    bool exists;    // Indica se o vértice está ativo ou não
} VerticeMatriz;

// Estrutura que representa uma aresta no grafo
typedef struct {
    int peso;      // Peso da aresta
    bool existe;   // Indica se a aresta está ativa ou não
} ArestaMatriz;

// Declaração de variáveis globais para o grafo
extern VerticeMatriz verticesMatriz[MAX_VERTICES]; // Lista de vértices
extern ArestaMatriz matrizAdj[MAX_VERTICES][MAX_VERTICES]; // Matriz de adjacência
extern int numVerticesMatriz; // Número atual de vértices no grafo

bool inserirVerticeMatriz(char *label);
bool removerVerticeMatriz(int indice);
bool inserirArestaMatriz(int origem, int destino, int peso);
bool removerArestaMatriz(int origem, int destino);
void imprimeMatrizAdjacencia();
void imprimeVerticesMatriz();
void retornarVizinhosMatriz(int vertice);

#endif
