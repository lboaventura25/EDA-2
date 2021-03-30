#include <stdio.h>
#include <stdlib.h>

#define Item int
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {Item t = a; a = b; b = t;}
#define cmpexch(a, b) { if less(a, b) exch(a, b);}

int partition (Item *v, int l, int r) {
    Item c = v[r];
    int j = l;
    
    for(int k = l; k < r; k++)
        if(less(v[k], c)) {
            exch(v[k], v[j]);
            j++;
        }

    exch(v[j], v[r]);

    return j;
}

void quickSelect(int *v, int l, int r, int k) {

    if(r <= l)  return;

    int m = partition(v, l, r);

    if(m > k)   quickSelect(v, l, m - 1, k);
    if(m < k)   quickSelect(v, m + 1, r, k);
}


void quickSort(Item *v, int l, int r) {
    if (l < r) {
        int m = partition(v, l, r);

        quickSort(v, l, m - 1);
        quickSort(v, m + 1, r);
    }
}


int main(){
    int N, P, X, indice, fim, aux;

    scanf("%d %d %d", &N, &P, &X);

    int * v = (int *)calloc(N, sizeof(int));
    
    indice = P * X;
    fim = indice + X - 1;

    for(int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }

    quickSelect(v, 0, N - 1, indice);
    quickSelect(v, indice + 1, N - 1, fim);
    quickSort(v, indice + 1, fim - 1);

    aux = N;

    for(int i = 0; i < X; i++){
        if(indice < aux){
            printf("%d\n", v[indice]);
            indice += 1;
        }
    }

    free(v);

    return 0;
}