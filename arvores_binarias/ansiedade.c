#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char resposta[10];
    int cont = 0, triagem = 0, form = 0;

    while(scanf("%[^\n]", resposta) != EOF) {
        form++;
        if(strcmp(resposta, "sim") == 0) {
            cont++;
        }
        if(form % 10 == 0) {
            if(cont >= 2) triagem++;
            cont = 0;
        }
        getchar();
    }

    printf("%d\n", triagem);

    return 0;
}