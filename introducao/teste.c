#include <stdio.h>

void insertionSort(int *v, int r) {
  int i, j, tmp;

  for(i = 1; i < r; i++) {
    j = i - 1;
    tmp = v[i];

    while(j > -1 && v[j] > tmp) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = tmp;
  }
}

int main() {

  int v[50000];
  int i = 0;

  while(scanf("%d", &v[i]) != EOF) {
    i++;
  }

  insertionSort(&v[0], i);

  for(int j = 0; j < i; j++) {
    printf("%d", v[j]);

    if(j + 1 == i) {
      printf("\n");
    } else {
      printf(" ");
    }
  }

  return 0;
}