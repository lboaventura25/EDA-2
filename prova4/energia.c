#include <stdio.h>
#define MAX 101
#define normal "normal\n\n"
#define falha "falha\n\n"

int grafo[101][101];
int d[101];
int marc[101];

void insere(int x, int y) {
    grafo[x][d[x]++] = y;
    grafo[y][d[y]++] = x;
}

void zera_array(int E) {
    for(int i = 1; i <= E; i++) {
        d[i] = 0;
        marc[i] = 0; 
    }
}

int main() {
    int E, L, X, Y, topo;
    int pilha[101];
    int u, i, v, cont, conjunto_teste = 1;
 
    while(scanf("%d %d", &E, &L) != EOF && (E != 0 && L != 0)) {
        zera_array(E);

        for(i = 1; i <= L; i++) {
            scanf("%d %d",&X,&Y);

            insere(X, Y);
        }

        topo = 0;
        marc[1] = 1;

        pilha[topo++] = 1;
        cont = 0;
    
        while(!topo == 0) {
            u = pilha[--topo];
            cont++;
    
            for(i = 0; i < d[u]; i++){
                v = grafo[u][i];
                if(marc[v] == 0){
                    marc[v] = 1;
                    pilha[topo++] = v;
                }
            }
        }

        printf("Teste %d\n", conjunto_teste++);

        printf("%s", cont == E ? normal : falha);  
    }
 
    return 0;
}