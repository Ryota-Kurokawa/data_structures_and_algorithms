// 幅優先探索

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define INFTY (1 << 21)
int n, M[N][N];
int d[N], Q[N * N], head = 0, tail = 0;

void push(int x) {
  Q[tail++] = x;
}

void bfs(int s) {
  int i, u, v;
  for (i = 0; i < n; i++) {
    d[i] = INFTY;
  }
  d[s] = 0;
  push(s);
  while (head != tail) {
    u = Q[head++];
    for (v = 0; v < n; v++) {
      if (M[u][v] == 0) {
        continue;
      }
      if (d[v] != INFTY) {
        continue;
      }
      d[v] = d[u] + 1;
      push(v);
    }
  }
  for (i = 0; i < n; i++) {
    printf("%d %d\n", i + 1, ((d[i] == INFTY) ? (-1) : d[i]));
  }
}

int main() {
  int u, k, v, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      M[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    u--;
    for (j = 0; j < k; j++) {
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }
  bfs(0);
  return 0;
}