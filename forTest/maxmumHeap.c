// 
// rootが最も大きくて自分の子は自分よりも小さければ良い
// 
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int heapSize, sampleArray[MAX + 1];

void maxHeapify(int i) {
  int leftIndex, rightIndex, largest;
  leftIndex = 2 * i;
  rightIndex = 2 * i + 1;

  if (leftIndex <= heapSize && sampleArray[leftIndex] > sampleArray[i])
  {
    largest = leftIndex;
  } else if (rightIndex <= heapSize && sampleArray[rightIndex] > sampleArray[i])
  {
    largest = rightIndex;
  } else
  {
    largest = i;
  }
  
  // もし自身が最大ではない場合には、入れ替えたのち再帰関数を用いて条件下にあるかを確認する。
  if (largest != i)
  {
    int tmp = sampleArray[i];
    sampleArray[i] = largest;
    sampleArray[largest] = tmp;
    maxHeapify(largest);
  }
}

int main()
{
  int i;
  // ヒープのサイズをnとする
  scanf("%d", &heapSize);
  // 配列Aにn個の要素を入力する
  for (i = 1; i <= heapSize; i++)
  {
    scanf("%d", &sampleArray[i]);
  }
  // ヒープを構築する
  for (i = heapSize / 2; i >= 1; i--)
  {
    maxHeapify(i);
  }
  // 出力する
  for (i = 1; i <= heapSize; i++)
  {
    printf(" %d", sampleArray[i]);
  }
  printf("\n");
  return 0;
}