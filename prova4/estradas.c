#include <stdio.h> 
#include <stdlib.h>

typedef struct graph * Graph;
typedef struct Edge * Edge;

struct graph {
    int V;
    int E;
    int adj[2001][2001];
    int tc[2001][2001];
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

Graph graph_init(int v) {
    Graph G = malloc(sizeof(* G));
    G->V = v;
    G->E = 0;

    return G;
}

void graph_insert_edge(Graph G, Edge e, int d) {
    int v = e->v;
    int w = e->w;

    if(G->adj[v][w] == 0) G->E++;

    if(d == 2) {
        G->adj[v][w] = 1;
        G->adj[w][v] = 1;
    } else G->adj[v][w] = 1;
}

void graph_tc(Graph G) {
    int i, s, t;

    for(s = 0; s < G->V; s++) {
        for(t = 0; t < G->V; t++) {
            G->tc[s][t] = G->adj[s][t];
        }
    }

    for(s = 0; s < G->V; s++) G->tc[s][s] = 1;

    for(i = 0; i < G->V; i++) {
        for(s = 0; s < G->V; s++) {
            if(G->tc[s][i] == 1)
                for(t = 0; t < G->V; t++) {
                    if(G->tc[i][t] == 1) G->tc[s][t] = 1;
                }
        }
    }
}

int graph_reach(Graph G, int s, int t) {
    return G->tc[s][t];
}

int main() {
    
    int cities, v, w, d, t, x;

    scanf("%d", &cities);

    Graph graph = graph_init(cities);

    while(scanf("%d %d %d", &v, &w, &d) != EOF && (v != 0 || w != 0 || d != 0)) {
        graph_insert_edge(graph, edge_init(v, w), d);
    }

    graph_tc(graph);

    while(scanf("%d %d", &t, &x) != EOF) {
        int ida = 0;
        int volta = 0;

        if(graph_reach(graph, t, x)) ida = 1;
        if(graph_reach(graph, x, t)) volta = 1;

        if(ida && volta) printf("Ida e Volta\n");
        else if(ida && !volta) printf("Apenas Ida\n");
        else if(!ida && volta) printf("Apenas Volta\n");
        else printf("Impossibru\n");
    }

    return 0;
}
