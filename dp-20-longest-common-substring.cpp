#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int longestSubstring(const char str1[], const char str2[], const int len1, const int len2) {
  // stores the length of the common substring of str1[0..i] and str2[0..j]
  int csubstr[len1+1][len2+1];

  // all values set to 0
  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      csubstr[i][j] = 0;
    }
  }

  int maxLen = 0;
  // the actual processing
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (str1[i-1] == str2[j-1]) {
        csubstr[i][j] = 1 + csubstr[i-1][j-1];
        maxLen = max(maxLen, csubstr[i][j]);
      }
      else {
        csubstr[i][j] = 0;
      }
    }
  }

  /* printing the array */
  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      printf("%d ", csubstr[i][j]);
    }
    printf("\n");
  }
  return maxLen;
}

int main(int argc, const char *argv[])
{
  if (argc < 3) {
    cout << "Needs two command-line args" << endl;
    return 1;
  }

  const int len1 = strlen(argv[1]);
  const int len2 = strlen(argv[2]);

  cout << longestSubstring(argv[1], argv[2], len1, len2) << endl;
  return 0;
}
