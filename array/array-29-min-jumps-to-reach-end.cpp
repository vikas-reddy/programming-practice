#include<iostream>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

using namespace std;

/*
 *
 * Given an array of integers where each element represents the max number of
 * steps that can be made forward from that element. Write a function to return
 * the minimum number of jumps to reach the end of the array (starting from the
 * first element).
 *
 * Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
 * Output: 3 (1-> 3 -> 8 ->9)
 *
 */

int swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int minJumpsRec (int arr[], int start, int end) {
  // I'm stuck!
  if (arr[start] == 0)
    return INT_MAX;

  // I found a way out
  if (start + arr[start] >= end)
    return 1;

  // Recurse for all other cases
  int min_jumps = INT_MAX;
  for (int i = start + 1; i <= start + arr[start]; i++) {
    int cur_jumps = minJumpsRec(arr, i, end);
    if (cur_jumps != INT_MAX && min_jumps > cur_jumps + 1)
      min_jumps = cur_jumps + 1;
  }
  return min_jumps;
}

int minJumpsDP (int arr[], int len) {
  int end = len - 1;

  int jumps[len];
  for (int i = 0; i < len; i++)
    jumps[i] = INT_MAX;

  for (int start = end; start >= 0; start--) {
    if (start + arr[start] >= end) {
      jumps[start] = 1;
    }
    else {
      for (int i = start + 1; i <= start + arr[start]; i++) {
        if (jumps[i] != INT_MAX && jumps[start] > jumps[i] + 1)
          jumps[start] = jumps[i] + 1;
      }
    }
  }

  printArray(jumps, len);
  return jumps[0];
}

int main(int argc, const char *argv[])
{
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int len = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, len);

  int start = 0;
  cout << minJumpsRec(arr, start, len - 1) << endl;

  cout << minJumpsDP(arr, len) << endl;

  return 0;
}
