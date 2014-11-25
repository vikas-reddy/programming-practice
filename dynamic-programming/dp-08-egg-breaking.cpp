#include<iostream>
#include<limits.h>
using namespace std;

int maxSafeFloorRec(int eggs, int floors) {
  if (floors == 0 || floors == 1) return floors;
  if (eggs == 1) return floors;

  int min = INT_MAX;
  for (int i = 1; i <= floors; i++) {
    // we drop from the ith floor
    int a = maxSafeFloorRec(eggs - 1, i - 1); // the egg breaks
    int b = maxSafeFloorRec(eggs, floors - i); // the egg doesn't break
    int res = (a > b) ? a : b; // We go to the maximum of two partitions
    /* To minimize the number of drops in the worst case, we are taking the
     * maximum drops from the two partitions that we just created */

    if (min > res) {
      min = res;
    }
  }

  return min + 1; // 1 for the current trial
}

int maxSafeFloor(int eggs, int floors) {
  int eggFloor[eggs+1][floors+1];

  for (int f = 1; f <= floors; f++) {
    eggFloor[1][f] = f;
  }

  for (int e = 1; e <= eggs; e++) {
    eggFloor[e][0] = 0;
    eggFloor[e][1] = 1;
  }

  for (int e = 2; e <= eggs; e++) {
    for (int f = 2; f <= floors; f++) {
      int min = INT_MAX, minFloor;
      for (int i = 1; i <= f; i++) {
        int a = eggFloor[e - 1][i - 1]; // the egg breaks
        int b = eggFloor[e][f - i]; // the egg doesn't break
        int res = (a > b) ? a : b;

        if (min > res) {
          min = res;
          /* minFloor = i; */
        }
      }
      eggFloor[e][f] = 1 + min;
      /* printf("(e,f) = (%d,%d); minFloor = %d\n", e, f, minFloor); */
    }
  }

  for (int e = 1; e <= eggs; e++) {
    for (int f = 0; f <= floors; f++) {
      printf("%d ", eggFloor[e][f]);
    }
    printf("\n");
  }
  return eggFloor[eggs][floors];
}

int main(int argc, const char *argv[])
{
  int eggs, floors;
  cin >> eggs >> floors;

  /* cout << maxSafeFloorRec(eggs, floors) << endl; */
  cout << maxSafeFloor(eggs, floors) << endl;

  return 0;
}
