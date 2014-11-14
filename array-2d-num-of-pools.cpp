#include<iostream>
#include<stdio.h>
#include<stack>

using namespace std;

class coords {
  public:
    int x;
    int y;
    int color;
    coords(int a, int b) {
      x = a;
      y = b;
      color = 0; // unvisited
    }
};

void print2D(int arr[][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  } printf("\n");
}

bool isBoundary(int x, int y) {
  return (x == 0 || x == 4 || y == 0 || y == 4);
}

int numOfPools(int arr[][5]) {
  // initalize the visited array
  int visited[5][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
  };

  // four moves for four directions
  int moves[4][2] = {
    {1, 0},
    {0, -1},
    {-1, 0},
    {0, 1}
  };

  int poolsCount = 0;

  // keep visiting all zeros
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (arr[i][j] == 0 && visited[i][j] == 0) {

        if (isBoundary(i, j)) {
          return -1;
        }

        // initalization for crawler
        stack<coords*> s;
        coords *start = new coords(i,j), *c;
        visited[start->x][start->y] = 1; // gray

        // start with the current node
        s.push(start);

        // while we visit all connected 0s
        while (!s.empty()) {
          c = s.top();
          int visits = 0;
          // try going in all four directions
          for (int i = 0; i < 4; i++) {
            int x_coord = c->x + moves[i][0];
            int y_coord = c->y + moves[i][1];

            // continue for out-of-bound coords
            if (x_coord < 0 || x_coord >= 5 || y_coord < 0 || y_coord >= 5) {
              continue;
            }

            // do nothing for 1s
            if (arr[x_coord][y_coord] == 0) {
              if (isBoundary(x_coord, y_coord)) {
                return -1;
              }
              if (visited[x_coord][y_coord] == 0) {
                coords *temp = new coords(x_coord, y_coord);
                visited[x_coord][y_coord] = 1;
                s.push(temp);
                visits++;
                break;
              }
            }
          }
          if (visits == 0) {
            visited[c->x][c->y] = 2;
            s.pop();
          }
          /* print2D(visited); */
        }

        poolsCount++;
      }
    }
  }
  print2D(visited);
  return poolsCount;
}

int main(int argc, const char *argv[])
{
  int arr[5][5] = {
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,1,1,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1}
  };

  print2D(arr);
  cout << "Number of pools: " << numOfPools(arr) << endl;
  return 0;
}
