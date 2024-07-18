#include <stdio.h>
#include <stdlib.h>

// ノード構造体の定義
typedef struct Node
{
  int key;
  struct Node *prev, *next;
} Node;

// ダミーノードの定義
Node *nil;

// 初期化
void init()
{
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

// 挿入関数
void insert(int key)
{
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

// 削除関数
void delete(Node *t)
{
  if (t == nil)
    return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

// キーによる削除関数
void deleteKey(int key)
{
  Node *cur = nil->next;
  while (cur != nil && cur->key != key)
  {
    cur = cur->next;
  }
  if (cur != nil)
  {
    delete (cur);
  }
}

// 先頭削除関数
void deleteFirst()
{
  delete (nil->next);
}

// 末尾削除関数
void deleteLast()
{
  delete (nil->prev);
}

// リストの内容を出力する関数
void printList()
{
  Node *cur = nil->next;
  int isFirst = 1;
  while (cur != nil)
  {
    if (!isFirst)
    {
      printf(" ");
    }
    printf("%d", cur->key);
    cur = cur->next;
    isFirst = 0;
  }
  printf("\n");
}

int main()
{
  int n;
  scanf("%d", &n);

  init();

  for (int i = 0; i < n; i++)
  {
    char command[20];
    int key;
    scanf("%s", command);
    if (command[0] == 'i')
    {
      scanf("%d", &key);
      insert(key);
    }
    else if (command[0] == 'd')
    {
      if (command[6] == '\0')
      {
        scanf("%d", &key);
        deleteKey(key);
      }
      else if (command[6] == 'F')
      {
        deleteFirst();
      }
      else if (command[6] == 'L')
      {
        deleteLast();
      }
    }
  }

  printList();

  return 0;
}
