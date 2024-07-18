#include<stdio.h>

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
  int i, n, q, A[10000+1], sum = 0;
// 
// 配列Aにn個の要素を入力する。
// 
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
// 
// q個の要素を入力し、Aに含まれる要素の数を出力する。
// 
  scanf("%d", &q);
  for (i = 0; i < q; i++)
  {
    int key;
    scanf("%d", &key);
    if (search(A, n, key))
    {
      sum++;
    }
  }

  printf("%d\n", sum);
  return 0;
}
