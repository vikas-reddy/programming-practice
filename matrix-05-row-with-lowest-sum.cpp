#include<iostream>
#include<algorithm>
#include<limits.h>

#define ROW 5
#define COL 6

using namespace std;

/*
 *
 * Matrix of 1s and 0s. 1s are sorted in beginning of each row. Find
 * an efficient way of finding the row with maximum 0s in it.
 * or find row which has lowest sum.
 *
 * 1 1 1 0 0 0
 * 1 1 0 0 0 0
 * 1 1 1 1 1 1
 * 1 1 1 0 0 0
 * 1 1 1 1 0 0 
 *
 */

// Brute-force O(m*n)
int maxRow1(bool mat[][COL]) {
  int maxSum = 0, sum, rowIdx;
  for (int i = 0; i < ROW; i++) {
    sum = 0;
    for (int j = 0; j < COL; j++) {
      sum += (int) mat[i][j];
    }
    if (sum > maxSum) {
      maxSum = sum;
      rowIdx = i;
    }
  }
  return rowIdx;
}

int indexOfLastOne(bool arr[], int f, int l) {
  /* printf("%d-%d ", f, l); */
  if (f <= l) {
    int m = (f+l)/2;
    /* printf("%d\n", m); */
    if (m == 0) {
      return (arr[m] ? 0 : -1);
    }
    if (m == COL-1) {
      return (arr[m] ? m : -1);
    }
    if (arr[m] && !arr[m+1])
      return m;
    if (!arr[m])
      return indexOfLastOne(arr, f, m);
    if (arr[m+1])
      return indexOfLastOne(arr, m+1, l);
  }
  return -1;
}

// O(m*log(n))
int maxRow2(bool mat[][COL]) {
  int lastOneIdx, maxSum = INT_MIN, maxRow;
  for (int i = 0; i < ROW; i++) {
    lastOneIdx = indexOfLastOne(mat[i], 0, COL-1);
    /* cout << i << " -> " << lastOneIdx << endl; */
    /* cout << lastOneIdx + 1 << endl; */
    if (lastOneIdx + 1 > maxSum) {
      maxSum = lastOneIdx + 1;
      maxRow = i;
    }
  }
  return maxRow;
}

// O(m+n)
int maxRow3(bool mat[][COL]) {
  int maxRow;

  int r, c;
  r = 0;
  c = 0;
  while (r < ROW) {
    // seek to the last 1 of rth row
    for (c = c; c < COL && mat[r][c]; c++) {
      maxRow = r;
    }

    r++;
  }
  return maxRow;
}

int main(int argc, const char *argv[])
{
  bool mat[ROW][COL] = {
    {1, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 0, 0}
  };

  /* cout << "Row with maximum 1s: " << maxRow1(mat) << endl; */
  /* cout << "Row with maximum 1s: " << maxRow2(mat) << endl; */
  cout << "Row with maximum 1s: " << maxRow3(mat) << endl;
  return 0;
}
