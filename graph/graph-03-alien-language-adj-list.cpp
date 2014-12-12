#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<list>
#include<iterator>
#include<limits.h>

#define Vx 2
#define INF INT_MAX

using namespace std;

class Graph {
  int V; // Number of vertices
  list<char> *adj; // array of adjacency list entries

  public:

  Graph(int V) {
    this->V = V;
    this->adj = new list<char>[V];
  }

  void addEdge (char v, char w) {
    adj[v - 'a'].push_back(w);
  }

  void toplogicalSort() {
    bool *included = new bool[V];
    memset(included, false, sizeof(included));

    while (1) {
      int u = getVertex(included);
      if (u == -1)
        break;
      printf("%c ", u + 'a');

      included[u] = true;
      adj[u].clear();
    }
    printf("\n");
  }

  void printAdj() {
    for (int v = 0; v < V; v++) {
      printf("%c: ", v + 'a');
      for (list<char>::iterator w = adj[v].begin(); w != adj[v].end(); ++w) {
        printf("%c ", *w);
      }
      printf("\n");
    }
  }

  private:

  // O(n3) search for vertex with no incoming edges
  int getVertex(bool included[]) {
    for (int v = 0; v < V; v++) {
      if (!included[v]) {
        int inEdges = 0;
        for (int w = 0; w < V; w++) {
          for (list<char>::iterator i = adj[w].begin(); i != adj[w].end(); ++i) {
            if (*i == v + 'a') {
              inEdges++;
              break;
            }
          }
          if (inEdges)
            break;
        }
        if (inEdges == 0)
          return v;
      }
    }
    return -1;
  }
};

// Given two strings, get to a point where these two differ. And when they
// differ, add an edge in the graph.
void processStrings (Graph *g, char *str1, char *str2) {
  while (*str1 && *str2 && *str1 == *str2) {
    str1++;
    str2++;
  }
  if (*str1 && *str2)
    g->addEdge(*str1, *str2);
}

// Build the graph by processing two consecutive strings at a time
void buildGraph (Graph *g, char *str[], int n) {
  for (int i = 0; i < n-1; i++) {
    processStrings (g, str[i], str[i+1]);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 4)
    return 1;

  int alphabet = atoi(argv[1]);
  int num_words = argc - 2;
  if (num_words < 2) {
    return 2;
  }

  Graph g(alphabet);

  buildGraph(&g, argv + 2, num_words);
  g.printAdj();

  g.toplogicalSort();
}
