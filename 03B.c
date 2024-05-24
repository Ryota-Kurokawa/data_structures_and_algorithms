#include<stdio.h>
#include<string.h>
#define LEN 100005

// プロセスを表す構造体
typedef struct pp {
  char name[100];
  int t;
} P;

P Q[LEN];
int head, tail, n;

// キューにプロセスを追加する
void enqueue(P x)
{
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

// キューからプロセスを取り出す
P dequeue()
{
  P x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int min(int a, int b)
{
  // 三項演算子：条件式 ? 式1 : 式2を行うことで条件式が真の場合は式1を、偽の場合は式2を返す
  return a < b ? a : b;
}

int main()
{
  int elaps = 0, c;
  int i, q;
  P u;
  scanf("%d %d", &n, &q);
  
  // 全てのプロセスをキューに追加する
  for (i = 1; i <= n; i++)
  {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
  }
  head = 1;
  tail = n + 1;

  // シミュレーション
  while (head != tail)
  {
    u = dequeue();
    c = min(q, u.t);
    u.t -= c;
    elaps += c;
    if (u.t > 0)
    {
      enqueue(u);
    }
    else
    {
      printf("%s %d\n", u.name, elaps);
    }
  }
  return 0;
}


