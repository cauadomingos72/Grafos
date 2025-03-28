#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include <stdlib.h>  // Biblioteca para alocação de memória e funções gerais
#include <stdbool.h> // Biblioteca para usar o tipo booleano (true/false)
#include <string.h>  // Biblioteca para manipulação de strings

#define MAX_VERTICES 100 // Define o número máximo de vértices no grafo

// Estrutura que representa um nó na lista de adjacência
typedef struct No {
    int destino;       // Índice do vértice de destino
    int peso;          // Peso da aresta
    struct No* prox;   // Ponteiro para o próximo nó na lista
} No;

// Estrutura que representa um vértice no grafo
typedef struct {
    char label[50];    // Nome ou rótulo do vértice
    bool exists;       // Indica se o vértice está ativo ou não
    No* listaAdj;      // Ponteiro para a lista de adjacência do vértice
} VerticeLista;

// Declaração de variáveis globais para o grafo
extern VerticeLista verticesLista[MAX_VERTICES]; // Lista de vértices
extern int numVerticesLista;                     // Número atual de vértices no grafo

bool inserirVerticeLista(char *label);
bool removerVerticeLista(int indice);
bool inserirArestaLista(int origem, int destino, int peso);
bool removerArestaLista(int origem, int destino);
void imprimeListaAdjacencia();
void imprimeVerticesLista();
void retornarVizinhosLista(int vertice);
void liberarListaAdjacencia();

#endif
