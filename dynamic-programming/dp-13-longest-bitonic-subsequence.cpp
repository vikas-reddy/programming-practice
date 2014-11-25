#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;

/*
 * DP bottom-up approach.
 * Solution: compute the LIS (longest increasing subsequence) and LDS (longest
 * decreasing subsequence; this is from back) of the array. Once we have these
 * two arrays, we can compute LBS (longest bitonic subsequence) by a + b - 1
 *
 */
int longestBitonicDP(const int arr[], const int len) {
  int inc[len], dec[len];

  // inc[] computation
  for (int i = 0; i < len; i++) {
    int maxInc = 1;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        if (inc[j] + 1 > maxInc) {
          maxInc = inc[j] + 1;
        }
      }
    }
    inc[i] = maxInc;
  }

  // dec[] computation
  for (int i = len-1; i >= 0; i--) {
    int maxDec = 1;
    for (int j = len-1; j > i; j--) {
      if (arr[j] < arr[i]) {
        if (dec[j] + 1 > maxDec) {
          maxDec = dec[j] + 1;
        }
      }
    }
    dec[i] = maxDec;
  }

  for (int i = 0; i < len; i++) printf("%d ", inc[i]);
  printf("\n");
  for (int i = 0; i < len; i++) printf("%d ", dec[i]);
  printf("\n");

  /* Computing the length of the longest bitonic subsequence */
  int maxBit = INT_MIN;
  for (int i = 0; i < len; i++) {
    if (inc[i] + dec[i] - 1 > maxBit) {
      maxBit = inc[i] + dec[i] - 1;
    }
  }

  return maxBit;
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {12, 11, 40, 5, 3, 1}; */
  /* int arr[] = {80, 60, 30, 40, 20, 10}; */
  /* int arr[] = {1, 11, 2, 10, 4, 5, 2, 1}; */
  /* int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}; */
  int arr[] = {3,1,2,4,7,8,6};
  int len = sizeof(arr)/sizeof(arr[0]);

  cout << longestBitonicDP(arr, len) << endl;
  return 0;
}
