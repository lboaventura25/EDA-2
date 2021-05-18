#include <stdio.h>
#include <stdlib.h>

void ordena_insercao(int *v, int n){
    int chave, i, j;
    for(i = 0; i < n; i++){
        chave = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j + 1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
}


int main(){
    int n;
    scanf("%d", &n);

    int *v = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }


    ordena_insercao(v, n);

    for(int i = 0; i < n; i++){
        printf("%d", v[i]);
        if(i != n-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}