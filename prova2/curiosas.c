#include <stdio.h>
#include <stdlib.h>

void checa_nota_mais_frequente(int *A, int numero_checado, int *maior, int *max) {
    if(A[numero_checado] > *maior) {
        *max = numero_checado;
        *maior = A[numero_checado];
    }

    if(A[numero_checado] == *maior) {
        if(numero_checado > *max) {
            *max = numero_checado;
            *maior = A[numero_checado];
        }
    }
}

int main() {
    int N, A[1001] = {0}, max = 0, maior = 0, digitado;
    
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &digitado);

        A[digitado]++;
        
        checa_nota_mais_frequente(A, digitado, &maior, &max);
    }

    printf("%d\n", max);

    return 0;
}