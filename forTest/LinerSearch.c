#include<stdio.h>

#define MAX_ARR 10000

int search(int A[], int n, int key){
  int i = 0;
  A[n] = key;
  while (A[i] != key)
  {
    i++;
  }
  return i != n;
}

int main()
{
  int n, S[MAX_ARR+1], key, matchSum, keyNum;
  matchSum = 0;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &S[i]);
  }
  scanf("%d", &keyNum);
  for (int i = 0; i < keyNum; i++)
  {
    scanf("%d", &key);
    if (search(S, n, key))
    {
      matchSum++;
    }
  }
  printf("%d\n", matchSum);
  
  return 0;
}
