#include<stdio.h>
// 
// Bubble sort algorithm
// 
int bubbleSort(int numOfElement, int elementsArr[]){
  int i, j, temp, countOfSwap = 0;
  for(i = 0; i < numOfElement - 1; i++){
    for(j = 0; j < numOfElement - i - 1; j++){
      if(elementsArr[j] > elementsArr[j + 1]){
        temp = elementsArr[j];
        elementsArr[j] = elementsArr[j + 1];
        elementsArr[j + 1] = temp;
        countOfSwap++;
      }
    }
  }
  return countOfSwap;
}

int main()
{
  // 配列の要素数を取得
  int numOfElement;
  scanf("%d", &numOfElement);

  // 配列の要素を取得
  int elementsArr[numOfElement];
  for(int i = 0; i < numOfElement; i++){
    scanf("%d", &elementsArr[i]);
  }

  // バブルソートを実行し、スワップ回数を取得
  int countOfSwap = bubbleSort(numOfElement, elementsArr);

  for(int i = 0; i < numOfElement; i++){
    printf("%d", elementsArr[i]);
    if(i != numOfElement - 1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n", countOfSwap);
  return 0;
}
