// 重さがそれぞれ wi(i=0,1,...n−1)
//  の n
//  個の荷物が、ベルトコンベアから順番に流れてきます。これらの荷物を k
//  台のトラックに積みます。各トラックには連続する 0 個以上の荷物を積むことができますが、それらの重さの和がトラックの最大積載量 P
//  を超えてはなりません。最大積載量 P
//  はすべてのトラックで共通です。

// n
// 、k
// 、wi
//  が与えられるので、すべての荷物を積むために必要な最大積載量 P
//  の最小値を求めるプログラムを作成してください。

// 入力
// 最初の行に荷物の数 n
//  とトラックの数 k
//  が空白区切りで与えられます。続く n
//  行に n
//  個の整数 wi
//  がそれぞれ１行に与えられます。

// 出力
// P
//  の最小値を１行に出力してください。

// 制約
// 1≤n≤100,000
// 1≤k≤100,000
// 1≤wi≤10,000
// 入力例 1
// 5 3
// 8
// 1
// 7
// 3
// 9
// 出力例 1
// 10


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int w[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &w[i]);
  }
  int left = 0;
  int right = 1000000000;
  while (right - left > 1)
  {
    int mid = (left + right) / 2;
    int i = 0;
    for (int j = 0; j < k; j++)
    {
      int s = 0;
      while (s + w[i] <= mid)
      {
        s += w[i];
        i++;
        if (i == n)
        {
          break;
        }
      }
    }
    if (i == n)
    {
      right = mid;
    }
    else
    {
      left = mid;
    }
  }
  printf("%d\n", right);
  return 0;
}