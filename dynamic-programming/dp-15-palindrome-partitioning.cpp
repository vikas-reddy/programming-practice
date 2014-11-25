#include<stdio.h>
#include<iostream>
#include<limits.h>
#include<string.h>

using namespace std;

bool isPalindrome(const char str[], int a, int b) {
  while (a <= b) {
    if (str[a] != str[b]) {
      return false;
    }
    a++;
    b--;
  }
  return true;
}

int minCutsRec(const char str[], int a, int b) {
  /* printf("%d %d\n", a, b); */
  if (a > b)  return 0;
  if (a == b) return 0;

  if (isPalindrome(str, a, b)) {
    return 0;
  }

  int min = INT_MAX;
  for (int i = a; i < b; i++) {
    int val = minCutsRec(str, a, i) + 1 + minCutsRec(str, i+1, b);
    if (val < min) {
      min = val;
    }
  }
  return min;
}

int minCutsDP(const char str[], int len) {
  int cuts[len][len];
  bool pal[len][len];

  // initializing the data arrays
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (i >= j) {
        cuts[i][j] = 0;
      }
      pal[i][j] = false;
    }
  }

  // all one length strings are palindromes
  for (int i = 0; i < len; i++) {
    pal[i][i] = true;
  }

  for (int l = 2; l <= len; l++) {
    for (int i = 0; i <= len - l; i++) {
      int j = i + l - 1;

      // update the pal array
      if (str[i] == str[j]) {
        pal[i][j] = (l == 2) ? true : pal[i+1][j-1];
      }

      // update the cuts array
      if (pal[i][j]) {
        cuts[i][j] = 0;
      }
      else {
        int min = INT_MAX;
        for (int k = i; k < j; k++) {
          int val = 1 + cuts[i][k] + cuts[k+1][j];
          if (val < min) {
            min = val;
          }
        }
        cuts[i][j] = min;
      }
    }
  }

  /* printing the 2d arrays */
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      printf("%d ", cuts[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      printf("%d ", pal[i][j]);
    }
    printf("\n");
  }

  return cuts[0][len-1];
}

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    cout << "Needs a command-line argument. Exiting!" << endl;
    return 1;
  }

  /*
   * ababbbabbababa
   * aba b bbabb ababa
   *
   */
  int len = strlen(argv[1]);
  cout << minCutsRec(argv[1], 0, len-1) << endl;
  cout << minCutsDP(argv[1], len) << endl;
  return 0;
}
