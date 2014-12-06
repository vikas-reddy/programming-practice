#include<iostream>
#include<stdlib.h>

using namespace std;

int Majority(int A[], int l, int r) {
  int size = r - l + 1;
  if( size == 1 )
    return A[l];
  if( size == 2 )
    return A[l] == A[r] ? A[l] : -1;
  int leftMajority, leftCount = 0;
  int rightMajority, rightCount = 0;
  int m = l + size/2;
  leftMajority = Majority(A, l, m);
  rightMajority = Majority(A, m+1, r);
  if( leftMajority != -1 )
    for( int i = l; i <= r; i++ )
      if( leftMajority == A[i] )
        leftCount++;
  if( rightMajority != -1 )
    for( int i = l; i <= r; i++ )
      if( rightMajority == A[i] )
        rightCount++;
  if( leftCount > rightCount )
    return leftCount > (m - l + 1)/2 ? leftMajority : -1;
  if( leftCount < rightCount )
    return rightCount > (r - m)/2 ? rightMajority : -1;
  return -1;
}

int main(int argc, const char *argv[]) {
  // sort the array in O(nlogn) time
  // find the majority element in O(n)
  int arr[10] = {3, 4, 5, 5, 6, 8, 8, 8, 9, 9}, len = 10;
  int i = 0, j = 0, freq = 0, maxFreq = 0, repeatingElement = 0;

  for (i = 0, freq = 0; i < len; i = j) {
    for (j = i; j < len && arr[j] == arr[i]; j++, freq++);
    if (freq > maxFreq) {
      maxFreq = freq;
      repeatingElement = arr[i];
    }
  }
  cout << "element: " << repeatingElement << "; freq: " << maxFreq << endl;


  // majority in O(log n)
  /* int arr2[] = {1, 2, 3, 3, 3, 3, 10}; */
  int arr2[] = {1, 1, 2, 4, 4, 4, 6, 6};
  int len2 = sizeof(arr2)/sizeof(arr2[0]);
  cout << Majority(arr2, 0, len2-1) << endl;
  return 0;
}
