#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define V 9
#define INF INT_MAX

using namespace std;

void printArray (int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int getMinDistVertex (int dist[], bool sptSet[]) {
  int min = INF, min_idx = 0;
  for (int i = 0; i < V; i++) {
    if (sptSet[i] == false) {
      if (dist[i] < min) {
        min = dist[i];
        min_idx = i;
      }
    }
  }
  return min_idx;
}

void djistraShortestPath (int graph[][V], int dist[], int src) {
  bool sptSet[V];
  memset(sptSet, false, sizeof(sptSet));

  // distance to `src` is 0
  dist[src] = 0;

  for (int ct = 0; ct < V-1; ct++) {
    // get the min distance vertex which is not already included
    int u = getMinDistVertex (dist, sptSet);

    // mark as included
    sptSet[u] = true;

    // For all edges (u,v)
    for (int v = 0; v < V; v++) {
      // if v is not already included, and if there exists an edge (u,v)
      if (!sptSet[v] && graph[u][v]) {
        if (dist[u] != INF && dist[v] > dist[u] + graph[u][v]) {
          dist[v] = dist[u] + graph[u][v];
        }
      }
    }
  }
}

int main(int argc, const char *argv[]) {
  int graph[V][V] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 0, 10, 0, 2, 0, 0},
    {0, 0, 0, 14, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}
  };

  int dist[V];
  for (int i = 0; i < V; i++)
    dist[i] = INF;

  djistraShortestPath (graph, dist, 0);

  printArray(dist, V);

  return 0;
}
