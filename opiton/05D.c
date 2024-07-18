#include <stdio.h>
#include <stdlib.h>

// マージソートと反転数のカウント
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  long long inv_count = 0;

  i = left; // 左部分のインデックス
  j = mid;  // 右部分のインデックス
  k = left; // マージされた配列のインデックス
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];

      // 反転が発生する場合
      inv_count = inv_count + (mid - i);
    }
  }

  // 残りの要素をコピーする
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  // 一時配列から元の配列へコピー
  for (i = left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right)
{
  int mid;
  long long inv_count = 0;
  if (right > left)
  {
    mid = (right + left) / 2;

    inv_count += mergeSortAndCount(arr, temp, left, mid);
    inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

    inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}

int main()
{
  int n;
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  int *temp = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  long long inv_count = mergeSortAndCount(arr, temp, 0, n - 1);

  printf("%lld\n", inv_count);

  free(arr);
  free(temp);

  return 0;
}
