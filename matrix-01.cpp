#include<iostream>
#include<stdlib.h>

using namespace std;

class Matrix {
  public:
    int **mat;
    int rows, cols;

    // initialize an empty matrix
    Matrix(int r, int c) {
      rows = r;
      cols = c;
      mat = new int*[rows];
      for (int i = 0; i < cols; i++) {
        mat[i] = new int[cols];
      }
      mat[0][0] = 10; mat[0][1] = 20; mat[0][2] = 30; mat[0][3] = 40;
      mat[1][0] = 15; mat[1][1] = 25; mat[1][2] = 35; mat[1][3] = 45;
      mat[2][0] = 27; mat[2][1] = 29; mat[2][2] = 37; mat[2][3] = 48;
      mat[3][0] = 32; mat[3][1] = 33; mat[3][2] = 39; mat[3][3] = 50;
    }

    void sortedOrder() {
      int p = 0, q = 0;
      int coords[2] = {0, 0};
      while (!(p == rows-1 && q == cols-1)) {
        // print mat(p,q)
        cout << mat[p][q] << " ";

        findNext(coords, p, q);
        p = coords[0];
        q = coords[1];
      }
      cout << endl;
    }

    void findNext(int coords[], int currRow, int currCol) {
      /* cout << "findNext: " << currRow << " " << currCol << endl; */
      int curr = mat[currRow][currCol];
      int diff = 1000;
      //   (mat[currRow][currCol], 0, currRow-1, currCol+1, cols-1)
      /* cout << 0 << " -> " << currRow << endl; */
      /* cout << currCol+1 << " -> " << cols-1 << endl; */
      for (int r = 0; r <= currRow; r++) {
        for (int c = currCol+1; c < cols; c++) {
          /* cout << curr << " vs " << mat[r][c] << endl; */
          if ( (mat[r][c] - curr) >= 0 && diff >= (mat[r][c] - curr) ) {
            diff  = mat[r][c] - curr;
            coords[0] = r;
            coords[1] = c;
          }
          /* cout << "diff = " << diff << endl; */
        }
      }
      //   (mat[currRow][currCol], currRow+1, rows-1, 0, currCol-1)
      /* cout << currRow+1 << " -> " << rows-1 << endl; */
      /* cout << 0 << " -> " << currCol << endl; */
      for (int r = currRow+1; r < rows; r++) {
        for (int c = 0; c <= currCol; c++) {
          /* cout << curr << " vs " << mat[r][c] << endl; */
          if ( (mat[r][c] - curr) >= 0 && diff >= (mat[r][c] - curr) ) {
            diff  = mat[r][c] - curr;
            coords[0] = r;
            coords[1] = c;
          }
          /* cout << "diff = " << diff << endl; */
        }
      }
      /* cout << "diff = " << diff << endl; */
      /* cout << "(" << coords[0] << ", " << coords[1] << ")" << endl; */
    }

    void print() {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          cout << mat[i][j] << " ";
        }
        cout << endl;
      }
    }
};

int main(int argc, const char *argv[])
{
  Matrix m(4,4);
  m.print();
  m.sortedOrder();
  return 0;
}
