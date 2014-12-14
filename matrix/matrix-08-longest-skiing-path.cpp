#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

using namespace std;

/*
 * Program to find the length of the longest decreasing path in a matrix
 *
 * To run: ./a.out input.txt
 *
 */

// Prints a matrix
void printMat (int **mat, int R, int C) {
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++)
      printf("%d ", mat[r][c]);
    printf("\n");
  }
  printf("\n");
}

// Frees the memory assigned on the heap for a matrix
void freeMatrix (int **mat, int R, int C) {
  for (int r = 0; r < R; r++)
    free(mat[r]);
  free(mat);
}

// Checks whether a coordinate (x,y) is valid
bool isValid (int x, int y, int R, int C) {
  return (x >= 0 && x < R && y >= 0 && y < C);
}

// Find the maximum in a matrix
int findMax (int **mat, int R, int C) {
  int max = INT_MIN;
  for (int i = 0; i < R; i++) {
    for (int c = 0; c < C; c++) {
      if (mat[i][c] > max) {
        max = mat[i][c];
      }
    }
  }
  return max + 1;
}

// The maximize algorithm
int maximizePaths (int **mat, int **len, int R, int C) {
  static int moves[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
  };

  // `ct` is the number of elements we have maximized
  int ct = 0;

  int x, y, new_len;

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      for (int m = 0; m < 4; m++) {
        x = r + moves[m][0];
        y = c + moves[m][1];

        if (isValid(x, y, R, C) && mat[x][y] < mat[r][c]) {
          new_len = len[x][y] + 1;
          if (new_len > len[r][c]) {
            len[r][c] = new_len;
            ct++;
          }
        }

      }
    }
  }
  return ct;
}

// Runs the "maximize" algorithm (bottom-up DP) until we can no longer maximize
// any path in the matrix
int longestPath (int **mat, int R, int C) {

  // Initialize len
  int **len = new int*[R];
  for (int r = 0; r < R; r++)
    len[r] = new int[C];

  // Set all paths to 0 by default
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      len[r][c] = 0;

  int n = 0, ct = 0;

  // We run the "maximize algorithm" no more than R*C times, or until we can no
  // longer maximize any path
  do {
    n = maximizePaths(mat, len, R, C);
    ct++;
  } while (n > 0 && ct < R * C);

  return findMax(len, R, C);
}


int main(int argc, const char *argv[])
{
  if (argc < 2) {
    cout << "Needs an input filename as command-line argument. Exiting!" << endl;
    return 1;
  }

  // Input stream
  const char *input_file = argv[1];
  ifstream fstr(input_file);

  // If I can't open the file
  if (!fstr.is_open()) {
    cout << "Unable to open file" << endl;
    return 2;
  }

  // Number of places
  int num_places;
  fstr >> num_places;

  // For each place
  for (int p = 0; p < num_places; p++) {

    // Read place name
    char *place;
    fstr >> place;

    // Read rows and columns
    int R, C;
    fstr >> R >> C;

    // Initialize a matrix
    int **mat;
    mat = new int*[R];
    for (int i = 0; i < R; i++)
      mat[i] = new int[C];

    /* cout << R << " " << C << endl; */

    // Read the matrix
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++) {
        fstr >> mat[i][j];
      }

    /* printMat(mat, R, C); */

    cout << place << ": " << longestPath(mat, R, C) << endl;

    freeMatrix(mat, R, C);
  }

  fstr.close();
  return 0;
}
