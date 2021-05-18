#include <stdio.h>
#include <stdlib.h>

struct Graph
{
    int V;
    int E;
    int adj[2001][2001];
};

struct Edge
{
    int v;
    int w;
};

typedef struct Graph *Graph;
typedef struct Edge *Edge;

// int ** matrix_init(int l, int c) {
//     int ** matrix;

//     matrix = (int **) calloc(l, sizeof(int *));

//     for(int i = 0; i < l; i++) {
//         matrix[i] = (int *) calloc(c, sizeof(int));
//     }

//     return matrix;
// }

Graph graph_init(int v)
{
    Graph G = malloc(sizeof(*G));
    G->V = v;
    G->E = 0;
    // G->adj = matrix_init(v, v);

    return G;
}

Edge edge_init(int v, int w)
{
    Edge E = malloc(sizeof(*E));
    E->v = v;
    E->w = w;

    return E;
}

void graph_insert_edge(Graph G, Edge E)
{
    int v = E->v;
    int w = E->w;

    if (G->adj[v][w] == 0)
        G->E++;

    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void show_graph(Graph G)
{
    int v, w;

    printf(" | ");
    for (int i = 0; i < G->V; i++)
        printf("%d| ", i);
    printf("\n");
    for (int i = 0; i <= G->V; i++)
        printf("---");

    printf("\n");

    for (v = 0; v < G->V; v++)
    {
        printf("%d| ", v);
        for (w = 0; w < G->V; w++)
            printf("%d| ", G->adj[v][w]);
        printf("\n");
    }
}

int main()
{

    int N, M, J;
    int vizinhos, local_proximo;
    int *locais_juliano;
    Graph graph;
    Edge edge;

    scanf("%d %d %d", &N, &M, &J);

    graph = graph_init(N);
    locais_juliano = (int *)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vizinhos);

        for (int j = 0; j < vizinhos; j++)
        {
            scanf("%d", &local_proximo);

            edge = edge_init(i, local_proximo);
            graph_insert_edge(graph, edge);
        }
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &local_proximo);
        locais_juliano[i] = local_proximo;
    }

    for (int i = 0; i < J; i++)
    {
        scanf("%d", &local_proximo);

        for (int j = 0; j < M; j++)
        {
            if (graph->adj[locais_juliano[j]][local_proximo] == 1 || locais_juliano[j] == local_proximo)
                printf("Eu vou estar la\n");
            else
                printf("Nao vou estar la\n");
        }
    }

    // show_graph(graph);

    return 0;
}
