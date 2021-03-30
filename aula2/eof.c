#include <stdio.h>

int main() {

    int a, soma = 0;

    while(scanf("%d", &a) != EOF) {
        soma++;
    }

    printf("%d\n", soma);

    return 0;
}