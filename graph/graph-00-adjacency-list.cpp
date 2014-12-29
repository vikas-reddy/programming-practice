#include<iostream>
#include<list>
#include<queue>
#include<iterator>
#include<string.h>

using namespace std;

class Graph {
  int V;
  list<int> *adj;

  public:
    Graph (int);
    ~Graph ();
    void addEdge (int, int);
    void print();
    void DFS ();
    void DFS (int);
    void BFS ();
    void BFS (int);

  private:
    void DFSUtil (int, bool[]);
    void BFSUtil (int, bool[]);
};

Graph::Graph (int V) {
  this->V = V;
  adj = new list<int>[V];
}

Graph::~Graph () {
  for (int i = 0; i < V; i++)
    adj[i].clear();
}

void Graph::addEdge (int u, int v) {
  adj[u].push_back(v);
}

void Graph::print () {
  for (int i = 0; i < V; i++) {
    printf("%d: ", i);
    for (list<int>::const_iterator j = adj[i].begin(); j != adj[i].end(); ++j) {
      printf("%d ", *j);
    }
    printf("\n");
  }
}

void Graph::DFS () {
  bool *visited = new bool[V];
  memset(visited, false, sizeof(visited));

  for (int i = 0; i < V; i++) {
    if (!visited[i])
      DFSUtil(i, visited);
  }
  printf("\n");
}

void Graph::DFS (int src) {
  bool *visited = new bool[V];
  memset(visited, false, sizeof(visited));

  DFSUtil(src, visited);

  printf("\n");
}

void Graph::DFSUtil (int src, bool visited[]) {
  visited[src] = true;
  printf("%d ", src);

  for (list<int>::const_iterator i = adj[src].begin(); i != adj[src].end(); ++i) {
    if (visited[*i] == false)
      DFSUtil(*i, visited);
  }
}

void Graph::BFS () {
  bool *visited = new bool[V];
  memset(visited, false, sizeof(visited));

  for (int src = 0; src < V; src++)
    if (!visited[src])
      BFSUtil(src, visited);

  printf("\n");
}

void Graph::BFS (int src) {
  bool *visited = new bool[V];
  memset(visited, false, sizeof(visited));

  BFSUtil(src, visited);

  printf("\n");
}

void Graph::BFSUtil (int src, bool visited[]) {
  queue<int> q;

  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    printf("%d ", u);
    visited[u] = true;

    for (list<int>::const_iterator v = adj[u].begin(); v != adj[u].end(); ++v) {
      if (!visited[*v])
        q.push(*v);
    }
  }
}

/************* Graph ends here ****************/

int main(int argc, const char *argv[])
{
  Graph *g = new Graph(6);
  g->addEdge(5, 2);
  g->addEdge(5, 0);
  g->addEdge(4, 0);
  g->addEdge(4, 1);
  g->addEdge(2, 3);
  g->addEdge(3, 1);

  g->print();

  g->DFS();
  g->BFS();

  return 0;
}
