#include<iostream>
#include<string.h>
#include<limits.h>
#include<algorithm>
using namespace std;

int maxProduct(int n) {
  if (n == 1) return 0;
  if (n == 2) return 1;

  int maxP = INT_MIN;
  for (int i = 1; i < n; i++) {
    /* cout << i << " " << n - i << endl; */

    // i * (max)
    // cut the rope further only if it optimizes the product
    int product = i * max(n - i, maxProduct(n - i));

    // maximize the whole products
    maxP = max(maxP, product);
  }
  return maxP;
}

void printArray(int arr[], int f, int l) {
  for (int i = f; i <= l; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int maxProductDP(int n) {
  int prd[n+1];
  memset(prd, 0, sizeof(prd));

  // initial values
  prd[1] = 0;
  prd[2] = 1;

  for (int l = 3; l <= n; l++) {
    int maxPrd = INT_MIN;
    for (int i = 1; i < l; i++) {
      // Decide whether the cut further
      int product = i * max(l - i, prd[l-i]);
      maxPrd = max(maxPrd, product);
    }
    prd[l] = maxPrd;
  }

  printArray(prd, 1, n);

  return prd[n];
}

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  /* cout << "Max product: " << maxProduct(n) << endl; */
  cout << "Max product: " << maxProductDP(n) << endl;
  return 0;
}
