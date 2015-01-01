#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

/*
 * Given an array of numbers, arrange them in an alternate fashion such that
 * every number is followed by a number of opposite sign. Also the order was to
 * be maintained. If the count of negative numbers is more keep the extra at
 * last in array and same for positive numbers.
 *
 * Example :
 * Input: -3 -2 6 0 7 -1 -8
 * Output: -3 6 -2 0 -1 7 -8
 *
 */

void swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

void printArray (int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void rearrange1 (int arr[], int n) {
  int a = 0, b = 0;

  // Sort the array in such a way that positive numbers appear at the end, and
  // negative ones at the beginning, retaining their relative order
  while (true) {
    for (     ; a < n && arr[a] <  0; a++);
    for (b = a; b < n && arr[b] >= 0; b++);

    if (a >= n || b >= n || a >= b)
      break;

    // Shift the subarray (a,b-1) to right by one
    int temp = arr[b];
    for (int i = b-1; i >= a; i--)
      arr[i+1] = arr[i];
    arr[a] = temp;
  }
  // Now there `a` negative numbers and `n-a` positive numbers

  int negIdx = 0, posIdx = a;
  while (negIdx < n && posIdx < n && arr[negIdx] < 0 && negIdx + 1 < posIdx) {
    // Shift subarray
    int temp = arr[posIdx];
    for (int i = posIdx; i > negIdx; i--)
      arr[i] = arr[i-1];
    arr[negIdx+1] = temp;

    negIdx += 2;
    posIdx++;
  }
}

// Left rotates arr[] by 1
void rightRotate (int arr[], int f, int l) {
  if (f >= l)
    return;
  int temp = arr[l];
  for (int i = l; i > f; i--)
    arr[i] = arr[i-1];
  arr[f] = temp;
}

// O(n)
void rearrange2 (int arr[], int n) {
  int a, b;
  a = 0;

  // putting all negative numbers at the beginning
  // O(n) as a and b traverse through the length of the array only once
  while (true) {
    // Find the first non-negative number
    for (     ; a < n && arr[a] < 0;  a++);

    // Find the first negative number
    for (b = a; b < n && arr[b] >= 0; b++);

    if (a >= n || b >= n || a >= b)
      break;

    // Rotate the subarray by 1 to get the violating -ve number to the
    // beginning
    rightRotate(arr, a, b);

    // Start from the next element
    a++;
  }

  int neg_count = a, pos_count = n - a;

  if (neg_count == 0 || pos_count == 0)
    return;

  a = 1;
  b = neg_count;

  // Rearranging in alternate fashion
  // O(n)
  while (a < n && b < n && a < b) {
    rightRotate(arr, a, b);
    a += 2;
    b += 1;
  }
}

int findNextViolation (int arr[], int n, int a) {
  while ( a < n &&
          ((a & 1) && (arr[a] >= 0) || !(a & 1) && (arr[a] < 0))
      ) a++;
  return a;
}

int findNextPositive (int arr[], int n, int i) {
  while (i < n && arr[i] < 0)
    i++;
  return i;
}

int findNextNegative (int arr[], int n, int i) {
  while (i < n && arr[i] >= 0)
    i++;
  return i;
}

// Only one rearranging
void rearrange3 (int arr[], int n) {
  int a, b;
  a = 0;

  while (true) {
    // Find first violation
    a = findNextViolation(arr, n, a);

    // Find b
    b = (arr[a] < 0) ? findNextPositive(arr, n, a) : findNextNegative(arr, n, a);

    if (a >= n || b >= n || a >= b)
      break;

    rightRotate(arr, a, b);
    a++;
  }
}

int main(int argc, const char *argv[])
{
  // Random seed
  srand(time(NULL));

  /* int arr[] = {-3, -2, 6, 0, 7, -1, -8}; */
  /* int n = sizeof(arr)/sizeof(arr[0]); */
  int n = 10;
  int *arr = new int[n];
  int *arr2 = new int[n];
  for (int i = 0; i < n; i++) {
    int num = rand() % 100 - 50;
    arr[i] = num;
    arr2[i] = num;
  }

  printArray (arr, n);
  printArray (arr2, n);

  rearrange1 (arr, n);
  rearrange3 (arr2, n);

  printArray (arr, n);
  printArray (arr2, n);

  return 0;
}
