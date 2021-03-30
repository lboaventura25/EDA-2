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

int main() {
    Item v[140000], N, numero, check, meio, inicio, fim;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    merge_sort(v, 0, N - 1);

    while(scanf("%d", &numero) != EOF) {
        check = 0;
        inicio = 0;
        fim = N - 1;

        while(inicio <= fim) {
            meio = (inicio + fim) / 2;

            if(numero == v[meio]) {
                check = 1;
                break;
            } else if(numero > v[meio]) {
                inicio = meio + 1;
                continue;
            } else {
                fim = meio - 1;
                continue;
            }
        }

        printf("%s\n", check ? "sim" : "nao");
    }

    return 0;
}