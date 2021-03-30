#include <stdio.h>

typedef int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if(less(B, A)) exch(A, B) }

void selection_sort(Item *v, int l, int r) {
    for(int i = l; i < r; i++) {
        int min = i;
        for(int j = i + 1; j <= r; j++)
            if(less(v[j], v[min]))
                min = j;
        exch(v[i], v[min]);
    }
}

int main() {
    
    int v[100000], cont = 0;

    while(scanf("%d", &v[cont++]) != EOF);

    selection_sort(v, 0, cont - 2);

    for(int i = 0; i < cont - 1; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}