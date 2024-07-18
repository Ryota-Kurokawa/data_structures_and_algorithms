#include <stdio.h>
#include <stdlib.h>

#define MAX 100005
#define NIL -1

struct Node
{
  int parent, child, brother;
};

struct Node T[MAX];
int n, D[MAX];

void print(int u)
{
  int i, c;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("depth = %d, ", D[u]);

  if (T[u].parent == NIL)
  {
    printf("root, ");
  }
  else if (T[u].child == NIL)
  {
    printf("leaf, ");
  }
  else
  {
    printf("internal node, ");
  }

  printf("[");
  for (i = 0, c = T[u].child; c != NIL; i++, c = T[c].brother)
  {
    if (i)
    {
      printf(", ");
    }
    printf("%d", c);
  }
  printf("]\n");
}

void searchDepth(int u, int p)
{
  D[u] = p;
  if (T[u].brother)
  {
    searchDepth(T[u].brother, p);
  }
  if (T[u].child)
  {
    searchDepth(T[u].child, p + 1);
  }
}

int main()
{
  int leftId, nodeId, numOfChildren, element, rootDepth;
  // 根付き木のNodeの数を取得
  scanf("%d", &n);
  // Tの初期化
  for (int i = 0; i < n; i++)
  {
    T[i].brother = T[i].child = T[i].parent = NIL;
  }
  // Tに対して要素をはめていく
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &nodeId);
    scanf("%d", &numOfChildren);
    for (int j = 0; j < numOfChildren; j++)
    {
      scanf("%d", &element);
      if (j == 0)
      {
        // rootを入力された場合は左下の子供のnodeIdにelementを挿入する。
        T[nodeId].child = element;
      }
      else
      {
        // rootではない際はそのまま隣の兄弟のnodeIdにelementを挿入する。
        T[leftId].brother = element;
      }
      leftId = element;
      T[element].parent = nodeId;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (T[i].parent == NIL)
    {
      rootDepth = i;
      break;
    }
  }
  searchDepth(rootDepth, 0);

  for (int i = 0; i < n; i++)
  {
    print(i);
  }

  return 0;
}
