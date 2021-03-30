#include <stdio.h>

int main()
{

  int N, X, soma = 0;

  scanf("%d", &N);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &X);
    soma += X;
  }

  printf("%d\n", soma);

  return 0;
}