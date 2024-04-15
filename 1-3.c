#include<stdio.h>
int main(void)
{
  int N = 0;
  scanf("%d", &N);
  int A[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }
  
  for (int i = 0; i < N; i++)
  {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v)
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for (int k = 0; k < N; k++)
    {
      printf("%d", A[k]);
      if (k < N-1)
      {
        printf(" ");
      }
    }
    printf("\n");
  }
  

  return 0;
}
