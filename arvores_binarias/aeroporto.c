#include <stdio.h>
#include <stdlib.h>

int main() {

    int Aeroportos, Voos, X, Y, conjunto_teste = 0;
    int * aero;
    int maior = 0;

    while(scanf("%d %d", &Aeroportos, &Voos) && Aeroportos != 0 && Voos != 0) {
        conjunto_teste++;
        maior = 0;
        aero = (int *) calloc(sizeof(int), 101);

        for(int i = 0; i < Voos; i++) {
            scanf("%d %d", &X, &Y);

            aero[X]++;
            aero[Y]++;

            if(aero[X] >= maior) maior = aero[X];
            if (aero[Y] >= maior) maior = aero[Y];
        }

        printf("Teste %d\n", conjunto_teste);
        for(int j = 0; j <= Aeroportos; j++) {
            if(aero[j] == maior) printf("%d ", j);
        }

        printf("\n\n");

        free(aero);
    }

    return 0;
}