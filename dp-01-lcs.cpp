#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

/*
 *
 * Program to find the length of a LCS of the two given strings. It also prints
 * the LCS, albeit in the reverse order.
 *
 * ./a.out thisisatest testing123testing
 * ./a.out AGGTAB GXTXAYB
 * ./a.out ABCDGH AEDFHR
 *
 */

char *string1;
char **lcs_arr;
char **path_arr;

void print2Darray(int len1, int len2) {
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      printf("%c ", path_arr[i][j]);
    }
    printf("\n");
  }
}
void printSubstring(int len1, int len2) {
  int y = len1 - 1, x = len2 - 1;

  while (y >= 0) {
    switch (path_arr[y][x]) {
      case '\\':
        printf("%c", string1[y]);
        y--; x--;
        break;
      case '|': y--; break;
      case '-': x--; break;
      default: x--;
    }
  }
  printf("\n");
}

int max (int a, int b) {
  return (a > b ? a : b);
}

// DP: builds the lcs_arr[len1 + 1][len2 + 1] array from bottom to top
int lcs2(char str1[], char str2[], int len1, int len2) {
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      if (i == 0 || j == 0) {
        lcs_arr[i][j] = 0;
      }
      else if (str1[i - 1] == str2[j - 1]) {
        lcs_arr[i][j] = lcs_arr[i - 1][j - 1] + 1;
        path_arr[i - 1][j - 1] = '\\';
      }
      else {
        lcs_arr[i][j] = max(lcs_arr[i - 1][j], lcs_arr[i][j - 1]);
        if (lcs_arr[i][j] == lcs_arr[i - 1][j]) {
          path_arr[i - 1][j - 1] = '|';
        }
        else {
          path_arr[i - 1][j - 1] = '-';
        }
      }
    }
  }
  return lcs_arr[len1-1][len2-1];
}

// DP: normal recursive approach; takes exponential time
int lcs1(char str1[], char str2[], int len1, int len2) {
  if (len1 == 0 || len2 == 0) {
    return 0;
  }

  if (str1[len1 - 1] == str2[len2 - 1]) {
    path_arr[len1 - 1][len2 - 1] = '\\';
    return 1 + lcs1(str1, str2, len1 - 1, len2 - 1);
  }
  else {
    int a = lcs1(str1, str2, len1 - 1, len2);
    int b = lcs1(str1, str2, len1, len2 - 1);
    int maxLcs = max(a, b);
    path_arr[len1 - 1][len2 - 1] = (maxLcs == a) ? '|' : '-';
    return maxLcs;
  }
}

int main(int argc, char *argv[])
{
  if (argc < 3) {
    cout << "Needs command-line arguments. exiting!" << endl;
    return 1;
  }

  string1 = argv[1];
  char *str1 = argv[1];
  char *str2 = argv[2];

  int len1 = strlen(str1);
  int len2 = strlen(str2);

  // initializing the path_arr[len1][len2] 2d array
  path_arr = new char*[len1];
  for (int i = 0; i < len1; i++) {
    path_arr[i] = new char[len2];
  }

  /*
  cout << lcs1(str1, str2, len1, len2) << endl;
  print2Darray(len1, len2);
  printSubstring(len1, len2);
  */

  // initializing the lcs_arr[len1 + 1][len2 + 1] 2d array
  lcs_arr = new char*[len1 + 1];
  for (int i = 0; i < len1 + 1; i++) {
    lcs_arr[i] = new char[len2 + 1];
  }

  cout << lcs2(str1, str2, len1 + 1, len2 + 1) << endl;
  print2Darray(len1, len2);
  printSubstring(len1, len2);
  return 0;
}
