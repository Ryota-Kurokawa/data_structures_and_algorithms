#include <stdio.h>
#define MAX 10000
#define NIL -1

struct Node {int parent, left, right;};
struct Node T[MAX];
int n, D[MAX], H[MAX];
// 
// 当該時点での深さを保管する
// 
void setDepth(int u, int d) {
  // もし、uがNILならば、何もしない
  if (u == NIL) return NIL;
  // uの深さをdに設定する
  D[u] = d;
  // 左の子を深さd+1で設定する
  setDepth(T[u].left, d + 1);
  // 右の子を深さd+1で設定する
  setDepth(T[u].right, d + 1);
}
// 
// 当該時点での高さを保管する
// 
int setHeight(int u){
  // h1, h2を0で初期化する
  int h1 = 0, h2 = 0;
  // もし、uの左の子がNILでないならば、h1に左の子の高さを設定する
  if (T[u].left != NIL) h1 = setHeight(T[u].left) + 1;
  // もし、uの右の子がNILでないならば、h2に右の子の高さを設定する
  if (T[u].right != NIL) h2 = setHeight(T[u].right) + 1;
  // uの高さを設定する
  return H[u] = (h1 > h2 ? h1 : h2);
}
// 
// 兄弟を取得する
// 
int getSibling(int u) {
  // もし、uの親がNILならば、NILを返す
  if (T[u].parent == NIL) return NIL;
  // もし、uの親の左の子がuでないならば、かつ、uの親の左の子がNILでないならば、uの親の左の子を返す
  if (T[T[u].parent].left != u && T[T[u].parent].left != NIL) return T[T[u].parent].left;
  // もし、uの親の右の子がuでないならば、かつ、uの親の右の子がNILでないならば、uの親の右の子を返す
  if (T[T[u].parent].right != u && T[T[u].parent].right != NIL) return T[T[u].parent].right;
  // それ以外は、NILを返す
  return NIL;
}
// 
// 特定の形にして出力する
// 
void print(int u) {
  // uの情報を出力する
  printf("node %d: ", u);
  // 親の情報を出力する
  printf("parent = %d, ", T[u].parent);
  // 兄弟の情報を出力する
  printf("sibling = %d, ", getSibling(u));
  // 子の数を出力する
  int deg = 0;
  if (T[u].left != NIL) deg++;
  if (T[u].right != NIL) deg++;
  printf("degree = %d, ", deg);
  // 深さを出力する
  printf("depth = %d, ", D[u]);
  // 高さを出力する
  printf("height = %d, ", H[u]);
  // もし、uの親がNILならば、rootを出力する
  if (T[u].parent == NIL) printf("root\n");
  // もし、uの左の子がNILで、かつ、uの右の子がNILならば、leafを出力する
  else if (T[u].left == NIL && T[u].right == NIL) printf("leaf\n");
  // それ以外は、internal nodeを出力する
  else printf("internal node\n");
}
// 
// mian関数
// 
int main()
{
  int v,l,r, root;
  // nを入力する
  scanf("%d", &n);
  // Tの要素を初期化する
  for (int i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;
  // n回ループする
  for (int i = 0; i < n; i++)
  {
    // v,l,rを入力する
    scanf("%d %d %d", &v, &l, &r);
    // vの左の子をlに設定する
    T[v].left = l;
    // vの右の子をrに設定する
    T[v].right = r;
    // もし、lがNILでないならば、lの親をvに設定する
    if (l != NIL) T[l].parent = v;
    // もし、rがNILでないならば、rの親をvに設定する
    if (r != NIL) T[r].parent = v;
  }
  // rootを設定する
  for (int i = 0; i < n; i++) if (T[i].parent == NIL) root = i;
  // 深さを設定する
  setDepth(root, 0);
  // 高さを設定する
  setHeight(root);
  // 出力する
  for (int i = 0; i < n; i++) print(i);

  
  return 0;
}
