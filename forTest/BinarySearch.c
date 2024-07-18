#include <stdio.h>

int A[1000000], n;

int binarySearch(int key)
{
  int left = 0;
  int right = n;
  int mid;
  int result;
  while (left < right)
  {
    mid = (left + right) / 2;
    if (key == A[mid])
    {
      return 1;
    }
    if (key > A[mid])
    {
      left = mid + 1;
    }
    if (key < A[mid])
    {
      right = mid;
    }
  }
  return 0;
}

int main()
{
  int keyNum, result;
  result = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  scanf("%d", &keyNum);
  for (int i = 0; i < keyNum; i++)
  {
    int key;
    scanf("%d", &key);
    if (binarySearch(key))
    {
      result++;
    }
  }
  printf("%d\n", result);

  return 0;
}

