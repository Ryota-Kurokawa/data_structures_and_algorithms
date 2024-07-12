#include <stdio.h>
#include <stdlib.h>
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
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    graph[i].edgeCount = 0;
  }

  for (int i = 0; i < n; i++)
  {
    int u, k;
    scanf("%d %d", &u, &k);
    for (int j = 0; j < k; j++)
    {
      int v, c;
      scanf("%d %d", &v, &c);
      graph[u].edges[graph[u].edgeCount].vertex = v;
      graph[u].edges[graph[u].edgeCount].weight = c;
      graph[u].edgeCount++;
    }
  }

  dijkstra(0);

  for (int i = 0; i < n; i++)
  {
    printf("%d %d\n", i, distances[i]);
  }

  return 0;
}
