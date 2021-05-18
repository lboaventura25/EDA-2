#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if(less(B, A)) exch(A, B) }
#define index(A, B) *(A + B)
#define ptr(A, B, C) index(A, B) = C

void intercala(Item *v, int l, int m, int r) {
    Item * c = malloc(sizeof(Item) * (r - l + 1));
    int i = l;
    int j = m + 1;
    int k = 0;

    while(i <= m && j <= r) {
        if(less(v[i], v[j])) {
            c[k++] = v[i++];
        } else {
            c[k++] = v[j++];
        }
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

void print(Item * vetor, Item limite) {
    for(int i = 0; i < limite; i++) {
        printf("%d%c", index(vetor, i), i == (limite - 1) ? '\n' : ' ');
    }
}

int main() {
    Item * vetor, cont = 0;
    Item primeiro, segundo;

    vetor = (Item *) malloc(100000 * sizeof(Item));

    while(scanf("%d %d", &primeiro, &segundo) != EOF) {        
        if (primeiro == 1) {
            if(cont <= 99) {
                ptr(vetor, cont++, segundo);
            } else if(index(vetor, cont - 1) > segundo) {
                ptr(vetor, cont - 1, segundo);
            }
            intercala(vetor, 0, cont - 2, cont - 1);
        } else {
            print(vetor, segundo);
        }
    }

    return 0;
}