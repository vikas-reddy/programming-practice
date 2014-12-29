#include<iostream>
#include<list>
#include<stack>
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
    void toplogicalSort1 ();
    void toplogicalSort2 ();

  private:
    void DFSUtil (int, bool[]);
    void BFSUtil (int, bool[]);
    void toplogicalSortUtil1 (int, bool[], stack<int>*);
    int getVertexWithNoInEdges (bool[]);
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

void Graph::toplogicalSort1 () {
  bool *visited = new bool[V];
  memset(visited, false, sizeof(visited));

  stack<int> s;

  // DFS
  for (int src = 0; src < V; src++)
    if (!visited[src])
      toplogicalSortUtil1(src, visited, &s);

  // Print the contents of the stack
  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
  printf("\n");
}

// This is a normal DFS, but after recursing for the adjacent vertices, we add
// the current vertex to a stack
void Graph::toplogicalSortUtil1 (int src, bool visited[], stack<int> *s) {
  visited[src] = true;
  for (list<int>::const_iterator v = adj[src].begin(); v != adj[src].end(); ++v) {
    if (!visited[*v])
      toplogicalSortUtil1(*v, visited, s);
  }
  s->push(src);
}

void Graph::toplogicalSort2 () {
  bool *included = new bool[V];
  memset(included, false, sizeof(included));

  for (int i = 0; i < V; i++) {
    int u = getVertexWithNoInEdges(included);
    // if no such vertex exists
    if (u == -1)
      break;

    printf("%d ", u);
    included[u] = true;
  }
  printf("\n");
}

int Graph::getVertexWithNoInEdges (bool included[]) {
  bool *copy = new bool[V];
  for (int i = 0; i < V; i++)
    copy[i] = included[i];

  for (int u = 0; u < V; u++) {
    for (list<int>::const_iterator v = adj[u].begin(); v != adj[u].end(); ++v) {
      copy[*v] = true;
    }
  }

  for (int i = 0; i < V; i++)
    if (!included[i] && !copy[i]) {
      adj[i].clear();
      return i;
    }
  return -1;
}

/************* `Graph` ends here ****************/

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

  g->toplogicalSort2();

  return 0;
}
