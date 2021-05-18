#include <stdio.h>
#include <stdlib.h>

#define ehPar(A) (A % 2 == 0)

int main() {

    int N, numero_gerado;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &numero_gerado);

        if(ehPar(numero_gerado)) printf("Jedi\n");
        else printf("Sith\n");
    }

    return 0;
}
