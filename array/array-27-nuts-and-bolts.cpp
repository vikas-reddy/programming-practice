#include<iostream>
#include<stdlib.h>

using namespace std;

short swap (short *a, short *b) { short t = *a; *a = *b; *b = t; }
char swap (char *a, char *b) { char t = *a; *a = *b; *b = t; }

void printArray(short arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void printArray(char arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%c ", arr[i]);
  }
  printf("\n");
}

int partition (short nuts[], char bolts[], int f, int l) {
  if (f > l)  return -1;
  if (f == l) return f;

  int pivIdx = l;
  int nutPivot = nuts[pivIdx];
  int targetIdx = f;

  // Rearranging bolts based on nutPivot
  for (int i = f; i <= l; i++) {
    if (bolts[i] - 'a' < nutPivot)
      swap(&bolts[i], &bolts[targetIdx++]);
  }
  for (int i = targetIdx; i <= l; i++) {
    if (bolts[i] - 'a' == nutPivot) {
      swap(&bolts[i], &bolts[targetIdx]);
      break;
    }
  }

  swap(&nuts[targetIdx], &nuts[pivIdx]);

  int boltPivot = bolts[targetIdx];
  targetIdx = f;

  // Rearranging nuts based on boltPivot
  for (int i = f; i <= l; i++) {
    if (nuts[i] < boltPivot - 'a')
      swap(&nuts[i], &nuts[targetIdx++]);
  }

  return targetIdx;
}

void arrange (short nuts[], char bolts[], int f, int l) {
  if (f >= l)
    return;

  int pivIdx = partition(nuts, bolts, f, l);
  arrange(nuts, bolts, f, pivIdx - 1);
  arrange(nuts, bolts, pivIdx + 1, l);
}

int main(int argc, const char *argv[])
{
  short nuts[] = {8, 9, 3, 5, 2, 0, 1, 4, 7, 6};
  char bolts[] = {'d', 'j', 'b', 'c', 'a', 'e', 'g', 'h', 'i', 'f'};
  int len = sizeof(nuts)/sizeof(nuts[0]);

  printArray(nuts, len);
  printArray(bolts, len);

  arrange(nuts, bolts, 0, len-1);

  printArray(nuts, len);
  printArray(bolts, len);

  return 0;
}
