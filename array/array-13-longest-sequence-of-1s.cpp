#include<iostream>
#include<limits.h>
using namespace std;

/* Given an array of 0s and 1s, find the position of 0 to be replaced with 1 to
 * get longest continuous sequence of 1s.*/

// O(n2) naive
int findPosition1(bool arr[], int len) {
  int pre = 0, post = 0;
  int maxCount = INT_MIN, current;
  int idx;
  int i, j;

  // we don't increment i in the for loop
  for (i = 0; i < len; ) {

    // == 1
    if (arr[i]) {
      pre++;
      i++;
    }

    // == 0
    else {

      // count the 1s after this element
      post = 0;
      for (j = i+1; j < len && arr[j]; j++, post++);

      // maximize the current max
      current = pre + 1 + post;
      if (current > maxCount) {
        idx = i;
        maxCount = current;
      }

      printf("pre: %d, post: %d, idx: %d\n", pre, post, i);

      // the current zeros that we have calculated will be useful for next
      // calculation
      pre = post;

      // no post 0s --> start from next 0
      if (post == 0) {
        i++;
      }
      // else start from next 1
      else {
        i = j;
      }
    }
  }
  printf("maxCount: %d; index: %d\n", maxCount, idx);
}

int main(int argc, const char *argv[])
{
  bool arr[] = {1,1,0,0,1,0,1,1,1,0,1,1,1};
  /* bool arr[] = {0,1,1,1,1,0,0,1,0,0,1,1,1}; */
  /* bool arr[] = {0, 1, 1, 0, 1, 1, 0, 1, 1, 0}; */
  int len = sizeof(arr)/sizeof(arr[0]);

  cout << findPosition1(arr, len) << endl;
  return 0;
}
