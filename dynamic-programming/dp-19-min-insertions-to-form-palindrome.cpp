#include<iostream>
#include<string.h>
using namespace std;

int minInsertions(const char str[], int f, int l) {
  if (f > l) return 0;
  if (f == l) return 0;

  if (str[f] == str[l]) {
    return minInsertions(str, f+1, l-1);
  }
  else {
    // either we insert the first character at the end to make it a palindrome
    int a = 1 + minInsertions(str, f+1, l);
    // or the last character at the beginning
    int b = 1 + minInsertions(str, f, l-1);
    return (a < b) ? a : b;
  }
}

int minInsertionsDP(const char str[], int n) {
  int ins[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ins[i][j] = 0;
    }
  }

  for (int l = 2; l <= n; l++) {
    for (int i = 0; i < n - l + 1; i++) {
      int j = i + l - 1;
      /* printf("(%d, %d) ", i, j); */
      /* for (int k = i; k <= j; k++) { */
      /* } */
      if (str[i] == str[j]) {
        ins[i][j] = ins[i+1][j-1];
      }
      else {
        int a = 1 + ins[i+1][j];
        int b = 1 + ins[i][j-1];
        ins[i][j] = (a < b) ? a : b;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", ins[i][j]);
    }
    printf("\n");
  }
  return ins[0][n-1];
}

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    cout << "Needs a command-line arg." << endl;
    return 1;
  }

  int len = strlen(argv[1]);
  /* Recursive solution */
  cout << minInsertions(argv[1], 0, len - 1) << endl;

  /* DP: bottom-up */
  cout << minInsertionsDP(argv[1], len) << endl;
  return 0;
}
