#include<iostream>
#include<stdlib.h>

#define ROW 3
#define COL 6

using namespace std;

// even rows: left to right
// odd rows: right to left
void printSpiral1(int mat[][COL]) {
  int r = 0, c = 0;
  while (r < ROW) {
    if (r % 2 == 0) {
      for (int i = 0; i < COL; i++)
        printf("%d ", mat[r][i]);
    }
    else {
      for (int i = COL-1; i >= 0; i--)
        printf("%d ", mat[r][i]);
    }
    r++;
  }
}

// real spiral
void printSpiral2(int mat[][COL]) {
  int rowMin = 0, colMin = 0;
  int rowMax = ROW-1, colMax = COL-1;
  int count = 0;

  while (true) {
    for (int c = colMin; c <= colMax; c++, count++)
      printf("%d ", mat[rowMin][c]);
    rowMin++;
    if (count >= ROW*COL) break;

    for (int r = rowMin; r <= rowMax; r++, count++)
      printf("%d ", mat[r][colMax]);
    colMax--;
    if (count >= ROW*COL) break;

    for (int c = colMax; c >= colMin; c--, count++)
      printf("%d ", mat[rowMax][c]);
    rowMax--;
    if (count >= ROW*COL) break;

    for (int r = rowMax; r >= rowMin; r--, count++)
      printf("%d ", mat[r][colMin]);
    colMin++;
    if (count >= ROW*COL) break;
  }
  printf("\n");
}

int main(int argc, const char *argv[])
{
  int mat[ROW][COL] = {
    {1,  2,  3,  4,  5,  6},
    {7,  8,  9,  10, 11, 12},
    {13, 14, 15, 16, 17, 18}
  };

  /* printSpiral1(mat); */
  printSpiral2(mat);
  return 0;
}
