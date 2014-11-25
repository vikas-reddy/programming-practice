#include<iostream>

#define ROW 4
#define COL 4
#define MAX_SIZE 100

using namespace std;

void printMatrix(int mat[][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void reverseArray(int arr[], int f, int l, int step) {
  while (f < l) {
    swap(&arr[f], &arr[l]);
    f += step;
    l -= step;
  }
}

void transpose(int mat[][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = i+1; j < COL; j++) {
      if (i != j) {
        swap(&mat[i][j], &mat[j][i]);
      }
    }
  }
}

/* Rotation using separate buffer */
void rotate1(int mat[][COL], int rot[][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {

      /* clockwise 90 */
      rot[j][COL-1-i] = mat[i][j];

      /* anti-clockwise 90 */
      /* rot[ROW-1-j][i] = mat[i][j]; */

      /* 180 */
      /* rot[ROW-1-i][COL-1-j] = mat[i][j]; */
    }
  }
}

/* in-place rotate */
void rotate2(int mat[][COL]) {
  transpose(mat);

  /* reversing rows for clockwise 90 */
  for (int r = 0; r < ROW; r++) {
    reverseArray(mat[r], 0, COL-1, 1);
  }

  /* reversing cols for clockwise 90 */
  /* for (int c = 0; c < COL; c++) { */
  /*   reverseArray(&mat[0][c], c, ROW*(ROW-1)+c, ROW); */
  /* } */
}

int main(int argc, const char *argv[])
{
  int mat[ROW][COL] = {
    {10, 20, 30, 40},
    {15, 25, 35, 45},
    {27, 29, 37, 48},
    {32, 33, 39, 50}
  };
  /* printMatrix(mat); */

  rotate2(mat);
  printMatrix(mat);

  /* int rot[ROW][COL]; */
  /* rotate1(mat, rot); */

  /* printMatrix(rot); */
}
