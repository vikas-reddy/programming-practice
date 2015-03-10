#include<iostream>
using namespace std;

/*
 * Ugly number is of the form (2^a * 3^b * 4^c)
 *
 * Unlike the program which checks whether is an ugly number or not, this one
 * actually computes all ugly numbers from the beginning.
 * Uses bottom-up/tabulation -- dynamic programming 
 *
 * To find first 150 ugly numbers
 * */

int min(int a, int b, int c) {
  int ab = (a < b) ? a : b;
  return (ab < c) ? ab : c;
}

int main(int argc, const char *argv[])
{
  int ugly[150];

  // first element is 1 
  ugly[0] = 1;
  for (int i = 1; i < 150; i++) {
    ugly[i] = -1;
  }

  // initalization
  int idx2 = 0, idx3 = 0, idx5 = 0;
  int next2, next3, next5, nextUgly;

  for (int i = 1; i < 150; i++) {
    // Next ugly number is obviously a 2/3/5 multiple of previous ugly numbers
    next2 = ugly[idx2] * 2;
    next3 = ugly[idx3] * 3;
    next5 = ugly[idx5] * 5;

    // see which one is next
    nextUgly = min(next2, next3, next5);

    // increment the indexes appropriately
    if (nextUgly == next2) { idx2++; }
    if (nextUgly == next3) { idx3++; }
    if (nextUgly == next5) { idx5++; }

    // storing the current ugly number in the array
    ugly[i] = nextUgly;
  }

  for (int i = 0; i < 150; i++) {
    printf("%d ", ugly[i]);
  }
  printf("\n");
  return 0;
}
