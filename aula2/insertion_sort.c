#include <stdio.h>

typedef int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if(less(B, A)) exch(A, B) }

void insertion_sort(Item *v, int l, int r) {
    for(int i = r; i > l; i--)
      cmpexch(v[i - 1], v[i]);
    for(int i = l + 2; i <= r; i++) {
        int j = i; 
        Item tmp = v[j];

        while(less(tmp, v[j - 1])) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
    }
        
}

int main() {
    int v[100000], cont = 0;

    while(scanf("%d", &v[cont++]) != EOF);

    insertion_sort(v, 0, cont - 2);

    for(int i = 0; i < cont - 1; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}