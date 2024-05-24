#include<stdio.h>
// 
// selection sort algorithm
// 
int selectionSort(int numOfElement, int elementsArr[]){
  int i, j, minIndex, temp, countOfSwap = 0;
  for(i = 0; i < numOfElement - 1; i++){
    minIndex = i;
    for(j = i + 1; j < numOfElement; j++){
      if(elementsArr[j] < elementsArr[minIndex]){
        minIndex = j;
      }
    }
    if(minIndex != i){
      temp = elementsArr[i];
      elementsArr[i] = elementsArr[minIndex];
      elementsArr[minIndex] = temp;
      countOfSwap++;
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
  int countOfSwap = selectionSort(numOfElement, elementsArr);

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
