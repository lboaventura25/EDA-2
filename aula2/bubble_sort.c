#include <stdio.h>

typedef int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if(less(B, A)) exch(A, B) }

void bubble_sort(Item *v, int l, int r) {
    for(int i = l; i < r; i++)
        for(int j = l + 1; j <= r; j++)
            cmpexch(v[j-1], v[j]);
}

int main() {
    int v[100000], cont = 0;

    while(scanf("%d", &v[cont++]) != EOF);

    bubble_sort(v, 0, cont - 2);

    for(int i = 0; i < cont - 1; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}