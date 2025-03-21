# Representação de Grafos em C

Este projeto implementa um grafo utilizando tanto a matriz de adjacência quanto a lista de adjacência em C. O programa permite adicionar e remover vértices e arestas, visualizar a representação do grafo e consultar informações sobre seus elementos.

## Funcionalidades
- **Adicionar vértice** com um nome identificador.
- **Remover vértice** baseado no índice.
- **Adicionar aresta** entre dois vértices, especificando a origem, o destino e o peso.
- **Remover aresta** entre dois vértices.
- **Visualizar o grafo** em formato de matriz de adjacência e lista de adjacência.
- **Consultar os vízinhos** de um vértice.
- **Exibir um menu interativo** para interação com o grafo.

## Como Compilar
Para compilar o programa, utilize o seguinte comando no terminal:

```sh
gcc main.c -o grafo
```

## Como Executar
Após a compilação, execute o programa com o seguinte comando:

```sh
./grafo
```

## Estrutura do Programa
O programa está estruturado em diversas funções para modularização:

- `bool inserirVertice(char *label)`: Adiciona um novo vértice ao grafo.
- `bool removerVertice(int indice)`: Remove um vértice e suas conexões.
- `bool inserirAresta(int origem, int destino, int peso)`: Adiciona uma aresta com um peso entre dois vértices.
- `bool removerAresta(int origem, int destino)`: Remove uma aresta entre dois vértices.
- `void imprimeMatrizAdjacencia()`: Exibe a matriz de adjacência do grafo.
- `void imprimeListaAdjacencia()`: Exibe a lista de adjacência do grafo.
- `void retornarVizinhos(int vertice)`: Mostra os vízinhos de um vértice.
- `void menu()`: Apresenta um menu interativo para manipular o grafo.
