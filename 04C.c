#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 13 // 文字列の最大長 + 1 ('\0' を含む)

// ノードの定義
typedef struct Node
{
  char key[MAX_STRING_LENGTH];
  struct Node *next;
} Node;

// ハッシュテーブルのサイズ
#define HASH_TABLE_SIZE 1000003

// ハッシュ関数
unsigned int hash(char *str)
{
  unsigned int hash = 5381;
  int c;
  while ((c = *str++))
  {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash % HASH_TABLE_SIZE;
}

// 辞書の挿入
void insert(Node *hash_table[], char *str)
{
  unsigned int index = hash(str);
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  strcpy(newNode->key, str);
  newNode->next = hash_table[index];
  hash_table[index] = newNode;
}

// 辞書の検索
void find(Node *hash_table[], char *str)
{
  unsigned int index = hash(str);
  Node *current = hash_table[index];
  while (current != NULL)
  {
    if (strcmp(current->key, str) == 0)
    {
      printf("yes\n");
      return;
    }
    current = current->next;
  }
  printf("no\n");
}

int main()
{
  int n;
  scanf("%d", &n);

  // ハッシュテーブルの初期化
  Node *hash_table[HASH_TABLE_SIZE];
  for (int i = 0; i < HASH_TABLE_SIZE; i++)
  {
    hash_table[i] = NULL;
  }

  // 命令の処理
  char command[MAX_STRING_LENGTH];
  char str[MAX_STRING_LENGTH];
  for (int i = 0; i < n; i++)
  {
    scanf("%s", command);
    if (strcmp(command, "insert") == 0)
    {
      scanf("%s", str);
      insert(hash_table, str);
    }
    else if (strcmp(command, "find") == 0)
    {
      scanf("%s", str);
      find(hash_table, str);
    }
  }

  // メモリの解放
  for (int i = 0; i < HASH_TABLE_SIZE; i++)
  {
    Node *current = hash_table[i];
    while (current != NULL)
    {
      Node *temp = current;
      current = current->next;
      free(temp);
    }
  }

  return 0;
}