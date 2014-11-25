#include<iostream>
#include<string.h>
using namespace std;

void polyMult(int arr1[], int arr2[], int len1, int len2) {
  int res[len1+len2-1];
  memset(res, 0, sizeof(res));

  for (int i = 0; i < len2; i++) {
    for (int j = 0; j < len1; j++) {
      res[i+j] += arr2[i] * arr1[j];
    }
    for (int k = 0; k < len1 + len2 - 1; k++)
      printf("%2d ", res[k]);
    printf("\n");
  }

}

int main(int argc, const char *argv[])
{
  int a[] = {5, 0, 10, 6};
  int b[] = {1, 2, 4};
  int len_a = sizeof(a)/sizeof(a[0]);
  int len_b = sizeof(b)/sizeof(b[0]);

  polyMult(a, b, len_a, len_b);
  return 0;
}
