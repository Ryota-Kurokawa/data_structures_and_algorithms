#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

// 出力する際の書式を指定する
void outPutPrint(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("node %d: key = %d, ", i+1, A[i]);
    if (i != 0)
    {
      printf("parent key = %d, ", A[(i - 1) / 2]);
    }
    if (2 * i + 1 < n)
    {
      printf("left key = %d, ", A[2 * i + 1]);
    }
    if (2 * i + 2 < n)
    {
      printf("right key = %d, ", A[2 * i + 2]);
    }

    printf("\n");
  }
  
}

int main()
{
  int n;
  // ヒープのサイズをnとする
  scanf("%d", &n);
  // 要素を詰め込む配列Aを定義する
  int A[MAX];
  // 初期化を行う(番兵を設定する)
  for (int i = 0; i < MAX; i++)
  {
    A[i] = -1;
  }
  // 配列Aにn個の要素を入力する
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  // 出力する
  outPutPrint(A, n);
  return 0;
}
