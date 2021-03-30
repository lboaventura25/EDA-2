#include <stdio.h>

typedef int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if(less(B, A)) exch(A, B) }

int main() {
    int v[10] = {8, 9, 6, 1, 3, 0, 5, 7, 4, 2}; 

    printf("Vetor antes de ordenar --> ");
    for(int i = 0; i < 10; i++)
        printf("%d ", v[i]);
    printf("\n");

    // ordenar(v, 0, 9);

    printf("Vetor depois de ordenar --> ");
    for(int i = 0; i < 10; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}