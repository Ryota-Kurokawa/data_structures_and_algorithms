// 与えられた文字列に出現する各文字の種類ごとに異なるビット文字列の符号語を割り当てて文字列をビット文字列へ符号化したいです。この時、どの符号語も別の符号語の接頭語とならないように符号語を割り当てると、得られたビット文字列符号から一意に元の文字列を定めることができます。

// このような符号語の割り当てを求める方法の一つに、ハフマンの符号化アルゴリズムがあります。さらに、このアルゴリズムは任意の文字列について最短の自然数長ビット文字列符号をもたらすことが知られています。

// 例として、各文字ごとの出現頻度が以下の表のような文字列について考えます。ハフマンの符号化アルゴリズムを用いると表の3段目のような符号語を得ることができ、これが最適な符号語の割り当てとなります。

// a	b	c	d	e	f
// 出現頻度	45	13	12	16	9	5
// 符号語	0	101	100	111	1101	1100
// ハフマンの符号化アルゴリズムは、以下の図のようなハフマン木と呼ばれる全二分木を構成します。


// ハフマン木を構成するためには、まずそれぞれの文字の種類ごとに、文字の種類とその出現頻度を持つ親を持たない頂点を作ります。その後、手順を繰り返します。

// 親を持たない頂点のうち、最も出現頻度の低い2つの頂点 x,y
//  を選ぶ
// x
//  と y
//  の出現頻度の和を出現頻度とする新たな頂点 z
//  を作る
// z
//  を x
//  と y
//  の親にする
// 親を持たない頂点が1つなら終了.そうでないなら 1. へ戻る
// ハフマン木の葉を除く各頂点の左の子への辺と右の子への辺のそれぞれに0と1を割り当てることで、根から各文字の葉へ向かうパス上に対応する符号を見て取ることができます。

// 課題
// 文字列 S
//  が入力として与えられるので、ハフマンの符号化アルゴリズムを用いて S
//  の各文字に符号語を割り当てたときに、S
//  を符号化して得られるビット文字列の長さを出力するプログラムを作成してください。


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100
#define INF INT_MAX

typedef struct
{
  int vertex;
  int weight;
} Edge;

typedef struct
{
  Edge edges[MAX_N];
  int edgeCount;
} AdjacencyList;

AdjacencyList graph[MAX_N];
int distances[MAX_N];
int visited[MAX_N];
int n;

void dijkstra(int start)
{
  for (int i = 0; i < n; i++)
  {
    distances[i] = INF;
    visited[i] = 0;
  }
  distances[start] = 0;

  for (int i = 0; i < n; i++)
  {
    int minDistance = INF;
    int u = -1;

    // Find the unvisited vertex with the smallest distance
    for (int j = 0; j < n; j++)
    {
      if (!visited[j] && distances[j] < minDistance)
      {
        minDistance = distances[j];
        u = j;
      }
    }

    if (u == -1)
      break; // All reachable vertices are visited
    visited[u] = 1;

    // Update distances of adjacent vertices
    for (int j = 0; j < graph[u].edgeCount; j++)
    {
      Edge edge = graph[u].edges[j];
      int v = edge.vertex;
      int weight = edge.weight;
      if (distances[u] + weight < distances[v])
      {
        distances[v] = distances[u] + weight;
      }
    }
  }
}

int main()
{
  char S[MAX_N];
  scanf("%s", S);
  n = strlen(S);
  int freq[26] = {0};
  for (int i = 0; i < n; i++)
  {
    freq[S[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] > 0)
    {
      printf("%c %d\n", i + 'a', freq[i]);
    }
  }
  return 0;
}