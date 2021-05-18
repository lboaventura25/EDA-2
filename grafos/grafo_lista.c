#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph * Graph;
typedef struct node * Link;
int * pre;

typedef struct {
	int v;
	int w;
} Edge;

struct graph {
	int V;
	int E;
	Link * adj;
};

struct node {
	int v;
	Link next;
};

// Graph GRAPHCopy(Graph);
// void GRAPHDestroy(Graph);

Link NEW(int v, Link next) {
	Link x = malloc(sizeof * x);

	x->v = v; 
	x->next = next;

	return x;
}

Edge EDGE(int v, int w) {
	Edge edge = {v, w};

	return edge;
}

Graph GRAPHInit(int v) {
	Graph G = malloc(sizeof(* G));
	G->V = v;
	G->E = 0;

	G->adj = malloc(v * sizeof(Link));

	for (int i = 0; i < v; i++)
		G->adj[i] = NULL;

	return G;
}

void GRAPHInsertE(Graph G, Edge e) {
	int v = e.v, w = e.w;

	G->adj[v] = NEW(w, G->adj[v]);
	G->adj[w] = NEW(v, G->adj[w]);

	G->E++;
}

int GRAPHEdge(Edge *a, Graph G) {
	int v, E = 0; 
    Link t;

	for (v = 0; v < G->V; v++)
		for(t = G->adj[v]; t != NULL; t = t->next)
			if (v < t->v) a[E++] = EDGE(v, t->v);

	return E;
}

int cont = 0;
// Matriz de Adjascências
// void dfsR(Graph G, Edge e) {
// 	int t, w = e.w;
// 	pre[w] = cont++;

// 	for(t = 0; t < G->V; t++)
// 		if(G->adj[w][t] != 0)
// 			if(pre[t] == -1)
// 				dfsR(G, EDGE(w, t));
// }

// Lista de Adjascências
void dfsR(Graph G, Edge e) {
	int t, w = e.w;
	pre[w] = cont++;

	for(Link l = G->adj[w]; l != NULL; l = l->next) {
        t = l->v;

        if(pre[t] == -1)
            dfsR(G, EDGE(w, t));
    }
}

void GRAPHPrint(Graph G) {
	for (int i = 0; i < G->V; i++) {
		printf("%d", i);
		for (Link j = G->adj[i]; j != NULL; j = j->next) {
            printf(" -> %d", j->v);
		}
		printf("\n");
	}
}

int main (void) {
	int qtd;
	scanf("%d", &qtd);
	Graph grafo = GRAPHInit(qtd);
	// for (int n = 0; n < grafo->V; n++)
	// 	pre[n] = -1;

	while (qtd--) {
		int v, w;
		scanf("%d %d", &v, &w);
		GRAPHInsertE(grafo, EDGE(v, w));
	}

    GRAPHPrint(grafo);

	return 0;
}
