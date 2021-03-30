#include <stdio.h>
#include <string.h>

typedef struct item {
     char nome[21];
     int num_solucoes;
} Item;

#define Key(A) (A.num_solucoes)
#define less(A, B) (Key(A) > Key(B))
#define lesseq(A, B) (Key(A) >= Key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if(less(B, A)) exch(A, B) }
#define Key_string(A) (A.nome)
#define less_string(A, B) (strcmp(Key_string(A), Key_string(B)) < 0)
#define lesseq_string(A, B) (strcmp(Key_string(A), Key_string(B)) <= 0)
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch_string(A, B) { if(less_string(B, A)) exch(A, B) }


void bubble_sort(Item *v, int l, int r) {
    for(int i = l; i < r; i++)
        for(int j = l + 1; j <= r; j++)
            cmpexch(v[j-1], v[j]);
}

void bubble_sort_string(Item *v, int l, int r) {
    for(int i = l; i < r; i++)
        for(int j = l + 1; j <= r; j++)
            cmpexch_string(v[j-1], v[j]);
}

int main() {
     Item v[100000];
     int cont = 0, num = 1;

     while(scanf("%d", &cont) != EOF) {
          for(int i = 0; i < cont; i++) {
               scanf(" %[^ ]", v[i].nome);
               scanf("%d", &v[i].num_solucoes);
          }

          bubble_sort_string(v, 0, cont -1);
          bubble_sort(v, 0, cont - 1);

          // for(int i = 0; i < cont; i++) {    
          //    printf("%s", v[i].nome);
          //    printf(" %d\n", v[i].num_solucoes);
          // }

          printf("Instancia %d\n", num++);
          printf("%s\n", v[cont - 1].nome);
     }


     return 0;
}