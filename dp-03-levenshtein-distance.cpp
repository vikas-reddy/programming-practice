#include<iostream>
#include<string.h>
using namespace std;

/*
 *
 * Program to compute Levenshtein distance (also called "edit distance")
 * between two strings.
 *
 *
 * Operations allowed: (R)eplace, (I)nsert, (D)elete
 *
 * Recursion: E(i,j) = min {
 *                       (str1[i] != str2[j] ? R : 0) + E(i-1,j-1),
 *                       I + E(i, j -1),
 *                       D + E(i - 1, j)
 *                     }
 * 
 * Method: Dynamic Programming in bottom-up fashion
 *
 *
 */

// builds this (len1 + 1)x(len2 + 1) array in bottom-up fashion
int **distances;

// computes minimum of three numbers
int min(int a, int b, int c) {
  int min_ab = (a < b) ? a : b;
  return (min_ab < c) ? min_ab : c;
}

// print the distances array
void printDistancesArray(int len1, int len2) {
  for (int i = 0; i < len1 + 1; i++) {
    for (int j = 0; j < len2 + 1; j++) {
      printf("%d ", distances[i][j]);
    }
    printf("\n");
  }
}

// the actual method
int editDistance(char str1[], char str2[], int len1, int len2) {
  // dist(0, 0) = 0
  distances[0][0] = 0;

  // dist(i, 0) = i;
  for (int i = 1; i < len1 + 1; i++) {
    distances[i][0] = i;
  }

  // dist(0, j) = j;
  for (int j = 1; j < len2 + 1; j++) {
    distances[0][j] = j;
  }

  int a, b, c;
  for (int i = 1; i < len1 + 1; i++) {
    for (int j = 1; j < len2 + 1; j++) {
      // Replace operation if needed
      a = (str1[i - 1] != str2[j - 1]) + distances[i - 1][j - 1];

      // Delete operation
      b = 1 + distances[i - 1][j];

      // Insert operation
      c = 1 + distances[i][j - 1];

      distances[i][j] = min(a, b, c);
    }
  }

  return distances[len1][len2];
}

// Recursive solution. Takes exponential time
int editDistanceRecursive(char str1[], char str2[], int len1, int len2) {
  if (len1 == 0) return len2;
  if (len2 == 0) return len2;

  return min(
        editDistanceRecursive(str1, str2, len1 - 1, len2) + 1, // delete operation
        editDistanceRecursive(str1, str2, len1, len2 - 1) + 1, // insert operation
        editDistanceRecursive(str1, str2, len1 - 1, len2 - 1) + (str1[len1 - 1] != str2[len2 - 1]) // replace if necessary
      );
}

int main(int argc, char *argv[])
{
  if (argc < 3) {
    cout << "Needs at least two command-line args" << endl;
    return 1;
  }
  char *str1 = argv[1];
  char *str2 = argv[2];
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  cout << str1 << " " << len1 << endl;
  cout << str2 << " " << len2 << endl;

  /* Recursive */
  /* cout << "Min distance: " << editDistanceRecursive(str1, str2, len1, len2) << endl; */
  /* return 0; */

  /* Dynamic Programming */
  // initializing the array
  distances = new int*[len1 + 1];
  for (int i = 0; i < len1 + 1; i++) {
    distances[i] = new int[len2 + 1];
  }

  cout << "Min distance = " << editDistance(str1, str2, len1, len2) << endl;

  /* printDistancesArray(len1, len2); */
  return 0;
}
