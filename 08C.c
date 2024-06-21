#include <stdio.h>
#define MAX 10000
#define NIL -1

struct Node
{
  int key;
  struct Node *right, *left, *parent;
};
struct Node *root, *NIL_NODE;
// 
// insertの実装
// 
void insert(int k)
{
  struct Node *y = NIL_NODE;
  struct Node *x = root;
  struct Node *z;

  z = (struct Node *)malloc(sizeof(struct Node));
  z->key = k;
  z->left = NIL_NODE;
  z->right = NIL_NODE;

  while (x != NIL_NODE)
  {
    y = x;
    if (z->key < x->key)
    {
      x = x->left;
    }
    else
    {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NIL_NODE)
  {
    root = z;
  }
  else
  {
    if (z->key < y->key)
    {
      y->left = z;
    }
    else
    {
      y->right = z;
    }
  }
}
// 
// inorderTreeWalkの実装
// 
void inorderTreeWalk(struct Node *u)
{
  if (u == NIL_NODE)
  {
    return;
  }
  inorderTreeWalk(u->left);
  printf(" %d", u->key);
  inorderTreeWalk(u->right);
}
//
// preorderTreeWalkの実装
//
void preorderTreeWalk(struct Node *u)
{
  if (u == NIL_NODE)
  {
    return;
  }
  printf(" %d", u->key);
  preorderTreeWalk(u->left);
  preorderTreeWalk(u->right);
}
// 
// findの実装
// 
struct Node *find(int k)
{
  struct Node *t = root;
  while (t != NIL_NODE && t->key != k)
  {
    if (k < t->key)
    {
      t = t->left;
    }
    else
    {
      t = t->right;
    }
  }
  return t;
}
// 
// deleteの実装
//
void delete (struct Node *z)
{
  struct Node *y;
  struct Node *x;

  if (z->left == NIL_NODE || z->right == NIL_NODE)
  {
    y = z;
  }
  else
  {
    y = z->right;
    while (y->left != NIL_NODE)
    {
      y = y->left;
    }
  }
  if (y->left != NIL_NODE)
  {
    x = y->left;
  }
  else
  {
    x = y->right;
  }
  if (x != NIL_NODE)
  {
    x->parent = y->parent;
  }
  if (y->parent == NIL_NODE)
  {
    root = x;
  }
  else
  {
    if (y == y->parent->left)
    {
      y->parent->left = x;
    }
    else
    {
      y->parent->right = x;
    }
  }
  if (y != z)
  {
    z->key = y->key;
  }
  free(y);
}
//
// main関数
//
int main()
{
  int n, i, x;
  char com[20];
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    scanf("%s", com);
    if (com[0] == 'f')
    {
      scanf("%d", &x);
      struct Node *t = find(x);
      if (t != NIL_NODE)
      {
        printf("yes\n");
      }
      else
      {
        printf("no\n");
      }
    }
    else if (com[0] == 'i')
    {
      scanf("%d", &x);
      insert(x);
    }
    else if (com[0] == 'p')
    {
      inorderTreeWalk(root);
      printf("\n");
      preorderTreeWalk(root);
      printf("\n");
    }
    else if (com[0] == 'd')
    {
      scanf("%d", &x);
      delete (find(x));
    }
  }
  return 0;
}