#include <stdio.h>
#define MAX 10000
#define NIL -1

struct Node
{
  int parent, left, right;
};
struct Node Tree[MAX];
int n, Depth[MAX], Height[MAX];

void setDepth(int nodeId, int depth)
{
  if (nodeId == NIL) return;
  Depth[nodeId] = depth;
  setDepth(Tree[nodeId].left, depth + 1);
  setDepth(Tree[nodeId].right, depth + 1);
}

// 高さを返す
int setHeight(int nodeId){
  int h1 = 0;
  int h2 = 0;
  if (Tree[nodeId].left != NIL) {
    h1 = setHeight(Tree[nodeId].left) + 1;
  }
  if (Tree[nodeId].right != NIL) {
    h2 = setHeight(Tree[nodeId].right) + 1;
  }
  return Height[nodeId] = (h1 > h2 ? h1 : h2);
}

// 兄弟nodeを返す
int getSibling(int nodeId) {
  if (Tree[nodeId].parent == NIL) return NIL;
  if (Tree[Tree[nodeId].parent].left != NIL && Tree[Tree[nodeId].parent].left != nodeId) return Tree[Tree[nodeId].parent].left;
  if (Tree[Tree[nodeId].parent].right != NIL && Tree[Tree[nodeId].parent].right != nodeId) return Tree[Tree[nodeId].parent].right;
  return NIL;
}

void print(int u) {
  printf("node %d: ", u);
  printf("parent = %d, ", Tree[u].parent);
  printf("sibling = %d, ", getSibling(u));
  int deg = 0;
  if (Tree[u].left != NIL) deg++;
  if (Tree[u].right != NIL) deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", Depth[u]);
  printf("height = %d, ", Height[u]);

  if (Tree[u].parent == NIL) printf("root\n");
  else if (Tree[u].left == NIL && Tree[u].right == NIL) printf("leaf\n");
  else printf("internal node\n");
}

int main()
{
  int instanceNodeId = -1, instanceLeftNode = -1, instanceRightNode = -1, root = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    Tree[i].parent = Tree[i].right = Tree[i].left = NIL;
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d %d", &instanceNodeId, &instanceLeftNode, &instanceRightNode);
    Tree[instanceNodeId].left = instanceLeftNode;
    Tree[instanceNodeId].right = instanceRightNode;
    if (instanceLeftNode != NIL) Tree[instanceLeftNode].parent = instanceNodeId;
    if (instanceRightNode != NIL) Tree[instanceRightNode].parent = instanceNodeId;
  }

  for (int i = 0; i < n; i++)
  {
    if (Tree[i].parent == NIL)
    {
      root = i;
      break;
    }
  }
  
  setDepth(root, 0);
  setHeight(root);

  for (int i = 0; i < n; i++)
  {
    print(i);
  }
  

  return 0;
}
