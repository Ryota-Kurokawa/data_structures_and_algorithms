#include<stdio.h>

#define N 100

int main()
{
  int currentNode, numOfNode, outIndex, distinationElement, outputArray[N][N];
  scanf("%d", &numOfNode);
  for (int i = 0; i < numOfNode; i++)
  {
    for (int j = 0; j < numOfNode; j++)
    {
      outputArray[i][j] = 0;
    }
  }
  for (int i = 0; i < numOfNode; i++)
  {
    scanf("%d %d", &currentNode, &outIndex);
    for (int j = 0; j < outIndex; j++)
    {
      scanf("%d", &distinationElement);
      outputArray[currentNode-1][distinationElement-1] = 1;
    }
  }
  for (int i = 0; i < numOfNode; i++)
  {
    for (int j = 0; j < numOfNode; j++)
    {
      if (j)
      {
        printf(" ");
      }
      printf("%d", outputArray[i][j]);
    }
    printf("\n");
  }
  return 0;
}
