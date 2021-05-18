/*
-> Lista Encadeada de Adjacência
  ==========================================================================
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct graph * Graph;
typedef struct node * Link;
typedef struct Edge * Edge;

struct node {
    int v;
    Link next;
};

struct graph {
    int V;
    int E;
    Link * adj;
};

struct Edge {
    int v;
    int w;
};

Edge edge_init(int v, int w) {
    Edge E = malloc(sizeof(* E));
    E->v = v;
    E->w = w;

    return E;
}

Link new(int v, Link next) {
    Link x = malloc(sizeof(* x));

    x->v = v;
    x->next = next;

    return x;
}

Graph graph_init(int v) {
    Graph G = malloc(sizeof(* G));
    G->V = v;
    G->E = 0;
    G->adj = malloc(v * sizeof(Link));

    for(int i = 0; i < v; i++)
        G->adj[i] = NULL;

    return G;
}

void graph_insert_edge(Graph G, Edge e) {
    int v = e->v;
    int w = e->w;

    G->adj[v] = new(w, G->adj[v]);
    G->adj[w] = new(v, G->adj[w]);
    G->E++;
}

int graph_edges(Edge a[], Graph G) {
    int v, E = 0;
    Link t;

    for(v = 0; v < G->V; v++) 
        for(t = G->adj[v]; t != NULL; t = t->next)
            if(v < t->v)
                a[E++] = edge_init(v, t->v);

    return E;
}

// Busca em Profundidade (DFS)
static int cont, conexos;
static int pre[1000];

void graph_search(Graph G) {
    int v;
    cont = 0, conexos = 0;

    for(v = 0; v < G->V; v++) pre[v] = -1;

    for(v = 0; v < G->V; v++) {
        if(pre[v] == -1) {
            dfsR(G, edge_init(v, v));
            conexos++;
        }
    }
}

void dfsR(Graph G, Edge e) {
    int t, w = e->w;
    pre[w] = cont++;

    for(t = 0; t < G->V; t++) 
        if(G->adj[w][t] != 0)
            if(pre[t] == -1)
                dfsR(G, edge_init(w, t));
}

int main() {
    Graph grafo = graph_init(5);

    for(int v = 0; v < grafo->V; v++)
        pre[v] = -1;

    return 0;
}