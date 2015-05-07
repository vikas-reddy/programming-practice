#include<iostream>

using namespace std;

#define N 5
#define K 3

void sumOfSubquares (int mat[][N]) {
  int res[N-K+1][N-K+1];

  for (int r = 0; r < N; r++)
    for (int c = 1; c < N; c++)
      mat[r][c] += mat[r][c-1];

  for (int r = 1; r < N; r++)
    for (int c = 0; c < N; c++)
      mat[r][c] += mat[r-1][c];

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++)
      printf("%d ", mat[r][c]);
    printf("\n");
  }

  for (int r = 0; r < N-K+1; r++) {
    for (int c = 0; c < N-K+1; c++) {
      int x = r+K-1;
      int y = c+K-1;
      printf("%d - %d - %d   ", mat[x][y], (y >= K ? mat[x][y-K] : 0), (x >= K ? mat[x-K][y] : 0));

      res[r][c] = mat[x][y] - (y >= K ? mat[x][y-K] : 0) - (x >= K ? mat[x-K][y] : 0);
    }
    printf("\n");
  }

  for (int r = 0; r < N-K+1; r++) {
    for (int c = 0; c < N-K+1; c++)
      printf("%d ", res[r][c]);
    printf("\n");
  }
}

int main(int argc, const char *argv[])
{
  int n = 5, k = 3;

  /* int **mat = new int*[n]; */
  /* for (int r = 0; r < n; r++) */
  /*   mat[r] = new int[n]; */

  int mat[N][N] = {
    {1, 1, 1, 1, 1},
    {2, 2, 2, 2, 2},
    {3, 3, 3, 3, 3},
    {4, 4, 4, 4, 4},
    {5, 5, 5, 5, 5},
  };

  sumOfSubquares(mat);

  return 0;
}
