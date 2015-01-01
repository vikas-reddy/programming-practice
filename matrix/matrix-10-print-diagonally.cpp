#include<iostream>
#include<stdlib.h>

#define ROWS 5
#define COLS 4

using namespace std;

bool isValid (int r, int c) {
  return ( (r >= 0 && r < ROWS) && (c >= 0 && c < COLS) );
}

void printDiagonally1 (int mat[][COLS]) {
  for (int s = 0; s <= ROWS + COLS - 2; s++) {

    // Coordinates of the starting cell
    int r = min(s, ROWS - 1);
    int c = (s < ROWS ? 0 : s - ROWS + 1);

    // Print while the coordinates are valid
    while (isValid(r, c)) {
      printf("%d ", mat[r][c]);
      r--, c++;
    }

    printf("\n");
  }
}

void printDiagonally2 (int mat[][COLS]) {
  for (int d = - (COLS - 1); d <= (ROWS - 1); d++) {
    int r = (d < 0 ? 0 : d);
    int c = (d < 0 ? -d : 0);

    while (isValid(r, c)) {
      printf("%d ", mat[r][c]);
      r++, c++;
    }

    printf("\n");
  }
}

int main(int argc, const char *argv[])
{
  int mat[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16},
    {17, 18, 19, 20},
  };

  printDiagonally2(mat);

  return 0;
}
