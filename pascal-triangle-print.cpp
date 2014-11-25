#include<iostream>
using namespace std;

void printPascal1(int n) {
  // array initialization
  int arr[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      arr[i][j] = 0;
  for (int i = 0; i < n; i++) {
    arr[i][0] = 1;
    arr[i][i] = 1;
  }

  for (int i = 2; i < n; i++) {
    for (int j = 1; j < i; j++) {
      arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
    }
  }

  // printing the triangle
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int coeff(int n, int k) {
  int res = 1;
  if (k > n - k) {
    k = n - k;
  }
  for (int i = 0; i < k; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

void printPascal2(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d ", coeff(i, j));
    }
    printf("\n");
  }
}


void printPascal3(int n) {
  int curr;
  for (int l = 1; l <= n; l++) {
    int val = 1;
    for (int i = 1; i <= l; i++) {
      printf("%d ", val);
      val = val * (l - i)/i;
    }
    printf("\n");
  }
}

int main(int argc, const char *argv[])
{
  int n = 10;

  /* printPascal1(n); */
  /* printPascal2(n); */
  printPascal3(n);
  return 0;
}
