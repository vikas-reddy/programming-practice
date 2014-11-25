#include<iostream>
#include<limits.h>
using namespace std;

int maxValueRecursive(const int prices[], int len, int k) {
  if (k < 1 || k > len) return 0;
  int max = INT_MIN, val, a, b;
  for (int i = 1; i <= k; i++) {
    a = prices[i - 1];
    b = maxValueRecursive(prices, len, k - i);
    if (a + b > max) {
      max = a + b;
    }
  }
  return max;
}

int maxValueDP(const int prices[], const int n) {
  int maxValues[n];

  // length 1 is obvious
  maxValues[0] = prices[0];

  // for lengths > 1
  for (int l = 2; l <= n; l++) {
    // set max to 'l' length cutting
    int max = prices[l-1];

    // and maximize it by comparing this value with shorter length cuttings
    for (int i = 1; i <= l/2; i++) {
      printf("%d, %d\n", i, l - i);
      // rod lengths i and l - i
      int val = maxValues[i-1] + maxValues[l-i-1];
      if (val > max) {
        max = val;
      }
    }
    maxValues[l-1] = max;
  }

  /* printing the array */
  for (int l = 0; l < n; l++) {
    printf("%d ", maxValues[l]);
  }
  printf("\n");

  return maxValues[n-1];
}

int main(int argc, const char *argv[])
{
  int n = 8;
  int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
  /* int prices[] = {3, 5, 8, 9, 10, 17, 17, 20}; */

  cout << maxValueRecursive(prices, n, n) << endl;
  cout << maxValueDP(prices, n) << endl;
  return 0;
}
