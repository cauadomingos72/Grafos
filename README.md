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
gcc -o grafo main.c lista.c matriz.c
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

## Diferenças Entre as Duas Representações:
| **Característica**              | **Matriz de Adjacência**                              | **Lista de Adjacência**                              |
|----------------------------------|-------------------------------------------------------|------------------------------------------------------|
| **Espaço**                       | Ocupa `O(V^2)` de espaço, onde `V` é o número de vértices. Mais eficiente para grafos densos. | Ocupa `O(V + E)` de espaço, onde `V` é o número de vértices e `E` é o número de arestas. Mais eficiente para grafos esparsos. |
| **Acesso a Arestas**             | Acesso direto à aresta entre dois vértices em `O(1)`. | Acesso pode ser mais demorado, pois requer iterar pela lista de adjacência (`O(V)` no pior caso). |
| **Inserção/Remoção de Arestas**  | Mais rápida para grafos densos, já que a remoção de arestas é feita diretamente na matriz (`O(1)`). | Requer manipulação da lista de adjacência, o que pode ser mais lento, especialmente em grafos grandes (`O(V)` no pior caso). |
| **Armazenamento de Arestas**     | Armazena as arestas em uma matriz 2D com um valor booleano para existência e o peso. | Armazena as arestas em listas associadas a cada vértice, onde cada lista contém pares de vértices de destino e pesos. |
| **Eficiência para Grafos Densos**| Muito eficiente. O espaço e o tempo de acesso são fixos e rápidos. | Pode ser ineficiente para grafos densos, pois seria necessário percorrer muitas listas para verificar a existência de arestas. |
| **Eficiência para Grafos Esparsos**| Ineficiente devido ao alto custo de espaço (`O(V^2)`). | Muito eficiente, pois ocupa apenas o espaço necessário para armazenar as arestas (`O(V + E)`). |

