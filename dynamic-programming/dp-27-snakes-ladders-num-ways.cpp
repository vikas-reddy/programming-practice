#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

/* There is n x n matrix and you are at starting position. What is the no. of
 * ways to reach n-square position if your next move will be dependent on
 * number on dice? You have been given information about ladders */

int numWaysRec  (int mat[], int n, int pos) {
  if (pos > n*n - 1)
    return 0;
  if (pos == n*n - 1)
    return 1;

  /* printf("pos: %d \n", pos); */
  int count = 0;
  for (int i = pos+1; i < n*n && i <= pos+6; i++) {
    count += numWaysRec (mat, n, (mat[i] == -1) ? i : mat[i]);
  }
  return count;
}

int numWaysDP (int mat[], int n) {
  int *ways = new int[n*n];
  memset(ways, 0, n*n);

  ways[n*n - 1] = 1;

  for (int i = n*n - 2; i >= 0; i--) {
    ways[i] = 0;
    for (int j = i+6; j >= i+1; j--) {
      if (j < n*n)
        ways[i] += ways[ (mat[j] == -1) ? j : mat[j] ];
    }
  }

  return ways[0];
}

int main(int argc, const char *argv[])
{
  int n = 3;
  int mat[] = {
    -1, 6, -1,
    -1, -1, -1,
    -1, -1, -1
  };

  cout << numWaysRec (mat, n, 0) << endl;
  /* cout << numWaysDP (mat, n) << endl; */

  return 0;
}
