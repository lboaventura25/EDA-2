#include <stdio.h>

int main() {
    int v[100000], temp[100000], cont = 0, cont_temp = 0, total = 0, check = 0;

    scanf("%d", &cont);

    for(int i = 0; i < cont; i++) {
        check = 0;
        scanf("%d", &v[i]);

        if(cont_temp != 0) {
            for(int j = 0; j < cont_temp; j++) {
                if(v[i] == temp[j]) {
                    check = 1;
                    break;
                }
            }
            if(!check) {
                temp[cont_temp++] = v[i];
                total++;
            }
        } else {
            temp[cont_temp++] = v[i];
            total++;
        }
    }

    printf("%d\n", total);

    return 0;
}