#include <stdio.h>
#include <string.h>

typedef struct
{
  char suit;
  int value;
} Card;

void bubbleSort(Card C[], int N)
{
  int i, j;
  for (i = 0; i < N; i++)
  {
    for (j = N - 1; j > i; j--)
    {
      if (C[j].value < C[j - 1].value)
      {
        Card temp = C[j];
        C[j] = C[j - 1];
        C[j - 1] = temp;
      }
    }
  }
}

void selectionSort(Card C[], int N)
{
  int i, j, minj;
  for (i = 0; i < N; i++)
  {
    minj = i;
    for (j = i; j < N; j++)
    {
      if (C[j].value < C[minj].value)
      {
        minj = j;
      }
    }
    if (minj != i)
    {
      Card temp = C[i];
      C[i] = C[minj];
      C[minj] = temp;
    }
  }
}

int isStable(Card original[], Card sorted[], int N)
{
  int i, j;
  for (i = 0; i < N; i++)
  {
    for (j = i + 1; j < N; j++)
    {
      if (sorted[i].value == sorted[j].value)
      {
        int k, l;
        for (k = 0; k < N; k++)
        {
          if (original[k].suit == sorted[i].suit && original[k].value == sorted[i].value)
          {
            break;
          }
        }
        for (l = k + 1; l < N; l++)
        {
          if (original[l].suit == sorted[j].suit && original[l].value == sorted[j].value)
          {
            break;
          }
        }
        if (l < k)
        {
          return 0;
        }
      }
    }
  }
  return 1;
}

void printCards(Card C[], int N)
{
  int i;
  for (i = 0; i < N; i++)
  {
    printf("%c%d", C[i].suit, C[i].value);
    if (i < N - 1)
    {
      printf(" ");
    }
  }
  printf("\n");
}

int main()
{
  int N, i;
  scanf("%d", &N);

  Card original[N], bubbleSorted[N], selectionSorted[N];

  for (i = 0; i < N; i++)
  {
    char suit;
    int value;
    scanf(" %c%d", &suit, &value);
    original[i].suit = suit;
    original[i].value = value;
    bubbleSorted[i] = original[i];
    selectionSorted[i] = original[i];
  }

  bubbleSort(bubbleSorted, N);
  selectionSort(selectionSorted, N);

  printCards(bubbleSorted, N);
  printf("%s\n", isStable(original, bubbleSorted, N) ? "Stable\n" : "Not stable\n");

  printCards(selectionSorted, N);
  printf("%s\n", isStable(original, selectionSorted, N) ? "Stable\n" : "Not stable\n");

  return 0;
}
