// 最大ヒープを実装してみる
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int H, A[MAX+1];

void maxHeapify(int i)
{
  int l, r, largest;
  l = 2 * i;
  r = 2 * i + 1;

  if (l <= H && A[l] > A[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  if (r <= H && A[r] > A[largest])
  {
    largest = r;
  }
  if (largest != i)
  {
    int tmp = A[i];
    A[i] = A[largest];
    A[largest] = tmp;
    maxHeapify(largest);
  }
}

int main()
{
  int i;
  // ヒープのサイズをnとする
  scanf("%d", &H);
  // 配列Aにn個の要素を入力する
  for (i = 1; i <= H; i++)
  {
    scanf("%d", &A[i]);
  }
  // ヒープを構築する
  for (i = H / 2; i >= 1; i--)
  {
    maxHeapify(i);
  }
  // 出力する
  for (i = 1; i <= H; i++)
  {
    printf(" %d", A[i]);
  }
  printf("\n");
  return 0;
}