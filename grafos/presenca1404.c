#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Dados {
    int vel_down;
    int vel_up;
} Dados;

typedef Dados Item;

#define Key(A) (A.vel_down)
#define KeyUp(A) (A.vel_up)
#define less(A, B) (Key(A) < Key(B))
#define lessUp(A, B) (KeyUp(A) < KeyUp(B))
#define equal(A, B) (Key(A) == Key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) {if(less(B, A)) {exch(A, B);} else if(equal(A, B)) {if(lessUp(A, B)) {exch(A, B);}}}

void intercala(Item *v, int l, int m, int r) {
    Item * c = malloc(sizeof(Item) * (r - l + 1));
    int i = l;
    int j = m + 1;
    int k = 0;

    while(i <= m && j <= r) {
        if(less(v[i], v[j])) {
            c[k++] = v[i++];
        } else if(equal(v[i], v[j])) {
            if(lessUp(v[i], v[j])) {
                c[k++] = v[i++];
            } else {
                c[k++] = v[j++];
            }
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

void merge_sort(Item *v, int l, int r) {
    if (l >= r) return;

    int meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);

    intercala(v, l, meio, r);
}

int main() {

    int vel_download, vel_upload, porcentagem_limite, T;
    int valor_down, valor_up, cont = 0;
    Item dados[1000000];

    scanf("%d %d %d %d", &vel_download, &vel_upload, &porcentagem_limite, &T); 

    float porcentagem = porcentagem_limite / 100.0;

    for(int i = 0; i < T; i++) {
        scanf("%d", &valor_down);
        getchar();
        scanf("%d", &valor_up);

        if(valor_down < (int)(vel_download - (vel_download * porcentagem)) ||
           valor_up < (int)(vel_upload - (vel_upload * porcentagem))) {
            dados[cont].vel_down = valor_down;
            dados[cont++].vel_up = valor_up;
        }
    }

    merge_sort(dados, 0, cont - 1);

    for(int i = 0; i < cont; i++) {
        printf("%d/%d\n", dados[i].vel_down, dados[i].vel_up);
    }

    return 0;
}