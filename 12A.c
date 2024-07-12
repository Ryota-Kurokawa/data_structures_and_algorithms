#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n;
  scanf("%d", &n);
  int A[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &A[i][j]);
    }
  }
  int visited[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = 0;
  }
  visited[0] = 1;
  int min = 1000000;
  int minIndex = 0;
  int sum = 0;
  for (int i = 0; i < n - 1; i++)
  {
    min = 1000000;
    for (int j = 0; j < n; j++)
    {
      if (visited[j] == 1)
      {
        for (int k = 0; k < n; k++)
        {
          if (visited[k] == 0 && A[j][k] != -1 && A[j][k] < min)
          {
            min = A[j][k];
            minIndex = k;
          }
        }
      }
    }
    visited[minIndex] = 1;
    sum += min;
  }
  printf("%d\n", sum);
  return 0;
}