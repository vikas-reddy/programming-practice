#include<iostream>

#define ROW 4
#define COL 4
#define MAX_SIZE 100

using namespace std;

/*
 * http://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
 */

void search(int mat[][COL], int elem) {
  int x = 0;
  int y = COL-1;

  while (true) {
    if (mat[x][y] == elem) {
      printf("(x,y) = (%d,%d)\n", x, y);
      return;
    }
    if (mat[x][y] < elem) {
      x++;
      if (x >= ROW)
        return;
    }
    else {
      y--;
      if (y < 0)
        return;
    }
  }
}

int main(int argc, const char *argv[])
{
  int mat[ROW][COL] = {
    {10, 20, 30, 40},
    {15, 25, 35, 45},
    {27, 29, 37, 48},
    {32, 33, 39, 50}
  };

  int elem;
  while (1) {
    cin >> elem;
    // exit
    if (elem == -1)
      break;
    search(mat, elem);
  }
  return 0;
}
