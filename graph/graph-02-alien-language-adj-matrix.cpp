#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define V 26
#define INF INT_MAX

using namespace std;

void printArray (int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void printGraph (bool graph[][V]) {
  printf(" ");
  for (int i = 0; i < 5; i++)
    printf("%c", i + 'a');
  printf("\n");

  for (int i = 0; i < 5; i++) {
    printf("%c", i + 'a');
    for (int j = 0; j < 5; j++) {
      printf("%c", graph[i][j] ? '1' : ' ');
    }
    printf("\n");
  }
}

// Return a vertex which has no 'in' edges
int getVertex (bool graph[][V], bool valid[]) {
  // for all vertices `v`
  for (int v = 0; v < V; v++) {
    if (valid[v]) {
      int in_edges = 0;
      // count the number of "in" edges (u,v)
      for (int u = 0; u < V; u++) {
        if (valid[u]) {
          if (graph[u][v]) {
            in_edges++;
            break;
          }
        }
      }
      if (in_edges == 0)
        return v;
    }
  }
  return -1;
}

void topologicalSort (bool graph[][V], bool valid[]) {
  while (1) {
    // get the vertex which has no "in" edge
    int u = getVertex(graph, valid);

    // Break the loop when we are left with zero vertices
    if (u == -1)
      break;

    // record that `u` has been deleted from the graph
    valid[u] = false;

    printf("%c ", u + 'a');

    // Remove all edges starting from `u`
    for (int v = 0; v < V; v++)
      graph[u][v] = false;
  }
  printf("\n");
}

// Given two strings, get to a point where these two differ. And when they
// differ, add an edge in the graph.
void processStrings (bool graph[][V], bool valid[], char *str1, char *str2) {
  while (*str1 && *str2 && *str1 == *str2) {
    str1++;
    str2++;
  }
  if (*str1 && *str2) {
    graph[*str1 - 'a'][*str2 - 'a'] = true;
    valid[*str1 - 'a'] = true;
    valid[*str2 - 'a'] = true;
  }
}

// Build the graph by processing two consecutive strings at a time
void buildGraph (bool graph[][V], bool valid[], char *str[], int n) {
  for (int i = 0; i < n-1; i++) {
    processStrings (graph, valid, str[i], str[i+1]);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3)
    return 1;

  int num_words = argc - 1;
  if (num_words < 2) {
    return 2;
  }

  // The adjacency matrix
  bool graph[V][V];
  memset(graph, false, sizeof(graph));

  // Valid array to represent which nodes we have in our graph
  bool valid[V];
  memset(valid, false, sizeof(valid));

  buildGraph (graph, valid, argv + 1, num_words);

  topologicalSort (graph, valid);
}
