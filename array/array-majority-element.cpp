#include<iostream>
#include<stdlib.h>

using namespace std;

int main(int argc, const char *argv[])
{
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
  return 0;
}
