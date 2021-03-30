#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if(less(B, A)) exch(A, B) }

void intercala(Item *v, int l, int m, int r) {
    Item *c = malloc(sizeof(Item) * (r - l + 1));
    int i = l;
    int j = m + 1;
    int k = 0;

    while(i <= m && j <= r) {
        if(lesseq(v[i], v[j]))
            c[k++] = v[i++];
        else
            c[k++] = v[j++];
    }

    while(i <= m)
        c[k++] = v[i++];

    while(j <= r)
        c[k++] = v[j++];

    k = 0;
    for(i = l; i <= r; i++)
        v[i] = c[k++];

    free(c);
}

void merge_sort(Item *v, int l, int r) {
    if (l >= r) return;

    int meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);

    intercala(v, l, meio, r);
}

int remove_iguais(Item v[], Item t) {
    Item temp[t], cont = 0;

    for(int i = 0; i < t; i++) {
        if (v[i] != v[i + 1]) {
            temp[cont++] = v[i];
        }
    }

    for (int i = 0; i < cont; i++)
        v[i] = temp[i];

    return cont;
}

int main() {

    Item v[300000], N, N_inicio;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);  

    merge_sort(v, 0, N - 1);

    N = remove_iguais(v, N);

    if(N % 2 != 0) {
        v[N++] = 1000000000;
        merge_sort(v, 0, N - 1);
    }

    N_inicio = N;

    for(int i = 0; (i + 1) < N_inicio; i += 2) {
        v[N++] = v[i] + v[i + 1];
    }

    intercala(v, 0, N_inicio - 1, N - 1);
    N = remove_iguais(v, N);

    for(int i = 0; i < N; i += 4)
        printf("%d\n", v[i]);

    printf("Elementos: %d\n", N);

    return 0;
}