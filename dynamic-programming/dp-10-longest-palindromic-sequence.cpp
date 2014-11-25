#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;

int longestPalindromeRec(const char arr[], int i, int j) {
  if (i > j)  return 0;
  if (i == j) return 1;
  if (arr[i] == arr[j]) {
    return 2 + longestPalindromeRec(arr, i+1, j-1);
  }
  else {
    int a = longestPalindromeRec(arr, i+1, j);
    int b = longestPalindromeRec(arr, i, j-1);
    return (a > b) ? a : b;
  }
}

int longestPalindromeDP(const char arr[], unsigned n) {
  // 2D used for memoization
  int lengths[n][n];

  // setting all values to 0
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      lengths[i][j] = 0;

  // palindromes of length 1
  for (int l = 0; l < n; l++)
    lengths[l][l] = 1;

  /* Now that we have palindrome of length 1, we can compute "longest
   * palindrome" lengths starting from length 2 to n */
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i < n - l + 1; i++) {
      int j = i + l - 1;
      if (arr[i] == arr[j]) {
        lengths[i][j] = 2 + lengths[i+1][j-1];
      }
      else {
        int a = lengths[i+1][j];
        int b = lengths[i][j-1];
        lengths[i][j] = (a > b) ? a : b;
      }
    }
  }

  // Printing the array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", lengths[i][j]);
    }
    printf("\n");
  }
  return lengths[0][n-1];
}

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    cout << "Needs a command-line argument. Exiting!" << endl;
    return 1;
  }

  cout << longestPalindromeRec(argv[1], 0, strlen(argv[1]) - 1) << endl;
  cout << longestPalindromeDP(argv[1], strlen(argv[1])) << endl;
  return 0;
}
