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
char **arr;

void print2Darray(int len1, int len2) {
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }
}
void printSubstring(int len1, int len2) {
  int y = len1 - 1, x = len2 - 1;

  while (y >= 0) {
    switch (arr[y][x]) {
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

int lcs(char str1[], char str2[], int len1, int len2) {
  if (len1 == 0 || len2 == 0) {
    return 0;
  }

  if (str1[len1 - 1] == str2[len2 - 1]) {
    arr[len1 - 1][len2 - 1] = '\\';
    return 1 + lcs(str1, str2, len1 - 1, len2 - 1);
  }
  else {
    int a = lcs(str1, str2, len1 - 1, len2);
    int b = lcs(str1, str2, len1, len2 - 1);
    int maxLcs = max(a, b);
    arr[len1 - 1][len2 - 1] = (maxLcs == a) ? '|' : '-';
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

  // initializing the global array
  arr = new char*[len1];
  for (int i = 0; i < len1; i++) {
    arr[i] = new char[len2];
  }

  cout << lcs(str1, str2, len1, len2) << endl;
  print2Darray(len1, len2);
  printSubstring(len1, len2);
  return 0;
}
