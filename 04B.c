#include <stdio.h>

// 二分探索関数
int binary_search(int arr[], int size, int target)
{
  int left = 0, right = size - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
      return 1; // 見つかった
    }
    else if (arr[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return 0; // 見つからなかった
}

// 共通要素の数を数える関数
int count_common_elements(int n, int S[], int q, int T[])
{
  int count = 0;
  for (int i = 0; i < q; i++)
  {
    if (binary_search(S, n, T[i]))
    {
      count++;
    }
  }
  return count;
}

int main()
{
  int n, q;
  scanf("%d", &n);

  int S[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);

  int T[q];
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &T[i]);
  }

  int result = count_common_elements(n, S, q, T);
  printf("%d\n", result);

  return 0;
}
