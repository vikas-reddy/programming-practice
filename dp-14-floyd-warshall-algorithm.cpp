#include<stdio.h>
#include<iostream>
#include<limits.h>

#define INF INT_MAX
#define V 4

using namespace std;

int gr[V][V] = {
  {0, 5, INF, 10},
  {INF, 0, 3, INF},
  {INF, INF, 0, 1},
  {INF, INF, INF, 0}
};
int res[V][V] = {
  {0, 5, INF, 10},
  {INF, 0, 3, INF},
  {INF, INF, 0, 1},
  {INF, INF, INF, 0}
};

void floydWarshall() {
  for (int a = 0; a < V; a++) {
    for (int b = 0; b < V; b++) {
      if (a != b) {
        // for all distinct pair of vertices (a,b)

        int min = res[a][b];
        for (int c = 0; c < V; c++) {
          if (c != a && c != b) {
            // for all intermediate vertices c
            if (res[a][c] != INF && res[c][b] != INF) {
              int curr = res[a][c] + res[c][b];
              if (curr < min) {
                min = curr;
              }
            }
          }
        }
        res[a][b] = min;

      }
    }
  }
}

int main(int argc, const char *argv[])
{
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      printf("%2d ", (gr[i][j] == INF) ? -1 : gr[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  floydWarshall();

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      printf("%2d ", (res[i][j] == INF) ? -1 : res[i][j]);
    }
    printf("\n");
  }

  return 0;
}
