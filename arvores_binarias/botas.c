#include <stdio.h>
#include <stdlib.h>

int main() {

    int botasDireito[100000] = {0};
    int botasEquerdo[100000] = {0};
    int pares = 0, numero;
    char pe;

    while(scanf("%d %c", &numero, &pe) != EOF) {
        if(pe == 'E') botasEquerdo[numero]++;
        else botasDireito[numero]++;

        if(botasDireito[numero] == botasEquerdo[numero]) pares++;
    }

    printf("%d\n", pares);

    return 0;
}