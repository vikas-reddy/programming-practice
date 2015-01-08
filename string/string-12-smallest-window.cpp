#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<iterator>

#define ALPHABET 26

using namespace std;

void printArray (int arr[], int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void printString (char str[], int f, int l) {
  for (int i = f; i <= l; i++)
    printf("%c", str[i]);
  printf("\n");
}

// Checks if ct2 is a subset of ct1
bool isSubset (int ct2[], int ct1[]) {
  for (int i = 0; i < ALPHABET; i++) {
    if (ct1[i] > ct2[i])
      return false;
  }
  return true;
}

/* The actual function */
bool smallestWindow (char *str1, int len1,
    char *str2, int len2,
    int &start, int &end,
    int &min_window) {

  // Two count arrays, one for original counts of str2, and the other for
  // current counts of various subarrays of str1 we're considering
  int ct1[ALPHABET], ct2[ALPHABET];
  memset(ct1, 0, sizeof(ct1));
  memset(ct2, 0, sizeof(ct2));

  // The first count array
  for (int i = 0; i < len2; i++)
    ct1[str2[i] - 'a']++;

  int st = -1, ed = -1;

  // Finding the starting point
  for (int i = 0; i < len1; i++) {
    if (ct1[str1[i] - 'a']) {
      st = i;
      break;
    }
  }

  // If none of the characters in str1 are present in str2
  if (st == -1)
    return false;

  // Finding the end point
  for (int i = st; i < len1; i++) {
    if (ct1[str1[i] - 'a']) {
      ct2[str1[i] - 'a']++;

      if (isSubset(ct2, ct1)) {
        ed = i;

        min_window = ed - st + 1;
        start = st;
        end = ed;

        break;
      }
    }
  }

  // If no window is possible
  if (ed == -1)
    return false;

  // Now that we found a window, let's minimize it!
  for (ed = ed + 1; ed < len1; ed++) {
    // We ignore chars which are not present at all in ct1/ct2
    if (ct2[str1[ed] - 'a']) {
      ct2[str1[ed] - 'a'] ++;

      // If first and last are equal in our subarray, trying removing from
      // first all "unwanted/redundant" characters
      if (str1[ed] == str1[st]) {

        // Remove unwanted characters
        for (st = st; st <= ed; st++) {
          if (ct2[str1[st] - 'a']) {
            ct2[str1[st] - 'a']--;

            if (!isSubset(ct2, ct1)) {
              ct2[str1[st] - 'a']++;
              break;
            }
          }
        }

        // Try to minimize the min-window
        if (min_window > ed - st + 1) {
          start = st;
          end = ed;
          min_window = ed - st + 1;
        }
      }
    }
  }

  return true;
}

int main(int argc, char *argv[]) {
  if (argc < 3)
    return 1;

  char *str1 = argv[1], *str2 = argv[2];
  int len1 = strlen(str1), len2 = strlen(str2);

  int start, end, min_window;
  bool status = smallestWindow(str1, len1, str2, len2, start, end, min_window);

  if (status) {
    printString(str1, start, end);
  }
  else {
    cout << "No window exists!" << endl;
  }

  return 0;
}
