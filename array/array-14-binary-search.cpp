#include<iostream>
using namespace std;

/* Find the number of occurances of an element in the array */

int findFirst(int arr[], int k, int f, int l) {
  /* printf("f,l = %d,%d\n", f, l); */
  if (f <= l) {
    int m = (f + l)/2;
    if ((m == 0 || arr[m-1] < k) && arr[m] == k){
      return m;
    }
    if (m == 0 || arr[m-1] >= k) {
      return findFirst(arr, k, f, m-1);
    }
    else {
      return findFirst(arr, k, m+1, l);
    }
  }
  return -1;
}

int findLast(int arr[], int k, int f, int l) {
  if (f <= l) {
    int m = (f + l)/2;
    /* printf("f,m,l = %d,%d,%d\n", f, m, l); */
    if (arr[m] == k && (m == l || arr[m+1] > k)) {
      return m;
    }
    if (m == l || arr[m+1] <= k) {
      return findLast(arr, k, m+1, l);
    }
    else {
      return findLast(arr, k, f, m-1);
    }
  }
  return -1;
}

// find the number of occurances of k in the array
int numOccurances(int arr[], int n, int k) {
  int f, l;
  f = findFirst(arr, k, 0, n-1);
  if (f != -1) {
    l = findLast(arr, k, 0, n-1);
  }

  /* cout << f << " " << l << endl; */
  return (f == -1) ? -1 : (l - f + 1);
}

int main(int argc, const char *argv[])
{
  int arr[] = {0, 1, 1, 1, 1, 1, 2, 2, 2, 2};
  int len = sizeof(arr)/sizeof(arr[0]);

  cout << numOccurances(arr, len, 1) << endl;
  return 0;
}
