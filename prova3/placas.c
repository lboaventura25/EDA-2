#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) { if (less(A,B)) exch(A,B); }

int *pq;
int N;

void insertionsort(int *v, int l, int r) {
    for(int i = r; i > l; i--) cmpexch(v[i], v[i - 1]);
    for(int i = l + 2; i <= r; i++) {
        int j = i; 
        int tmp = v[j];

        while(less(tmp,v[j - 1])) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
    }
}

int separa(int *V, int l, int r) {
    int i = l - 1; 
    int j = r;
    int v = V[r];

    for(;;) {
        while(less(V[++i],v));
        while(less(v, V[--j])) if(j == l) break;
        if(i >= j) break;
        exch(V[i], V[j]);
    }
    exch(V[i], V[r])

    return i;
}

static void quicksortM3(int *V, int l, int r) {
    if (r-l <= 32) return;
    
    exch(V[(l + r) / 2], V[r - 1]);
    cmpexch(V[l], V[r - 1]);
    cmpexch(V[l], V[r]);
    cmpexch(V[r - 1], V[r]);

    int j = separa(V, l, r);
    quicksortM3(V, l, j - 1);
    quicksortM3(V, j + 1,r);
}


void quicksortM3insertion(int *V, int l, int r) {
    quicksortM3(V, l, r);
    insertionsort(V, l, r);
}

void PQinit(int maxN) {
    pq = malloc(sizeof(int) * (maxN + 1));
    N  = 0;
}

int PQempty() {
    return N == 0;
}

void fixUp(int *pq, int k) {
    while (k > 1 && less(pq[k / 2], pq[k])) {
        exch(pq[k], pq[k / 2]);
        k = k / 2;
    }
}
void fixDown(int *pq, int k, int N) {
    int j;
    while(2 * k <= N) {
        j = 2 * k;
        if (j < N && less(pq[j], pq[j + 1])) j++;

        if (!less(pq[k], pq[j])) break;
        exch(pq[k], pq[j]);
        k=j;
    }
}

void PQinsert(int val) {
    pq[++N] = val;
    fixUp(pq, N);
}

int PQdelmax() {
    exch(pq[1], pq[N]);
    fixDown(pq, 1, N - 1);
    return pq[N--];
}

int PQpeek() {
    return pq[1];
}

void PQworkAround(int x) {
    pq[1] = x;
    fixDown(pq, 1, N);
}

int main() {
    int primeiro, segundo;

    PQinit(100000);

    while(scanf("%d %d", &primeiro, &segundo) != EOF) {
        if(primeiro == 1) {
            if (segundo < PQpeek()) PQworkAround(segundo);
            else PQinsert(segundo);
        }
        else {
            quicksortM3insertion(pq, 1, segundo);
            printf("%d ", pq[1]);
            for (int i = 2 ; i <= segundo; i++) 
                printf("%d ", pq[i]);
            printf("\n");
        }
    }

    return 0;
}