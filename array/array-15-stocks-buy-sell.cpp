#include<iostream>

using namespace std;

/*
 * Program to find when to buy and sell stocks.
 * To find local minima and maxima, and print them in pairs
 *
 */

// Trade stocks multiple times
// We're finding local maxima and minima
void tradeStocks(int arr[], int len) {
  int i = 0;
  while (i < len) {
    // find local mimima to buy
    while (i < len-1 && arr[i] >= arr[i+1])
      i++;

    // reached the end of the array
    if (i == len-1)
      break;

    printf("Buy on %d. ", i);

    // find local maxima to sell
    while (i < len-1 && arr[i] < arr[i+1])
      i++;

    printf("Sell on %d.\n", i);
  }
}


// to find the max sum array of differences
void tradeStocksOnce(int arr[], int len) {
  int globalMax, localMax;
  int diff;
  int buyDay = 0, sellDay = 0, startIdx = 0;

  globalMax = localMax = 0;
  for (int i = 0; i < len-1; i++) {
    diff = arr[i+1] - arr[i];

    // finding max sum of differences
    localMax += diff;
    if (localMax < 0) {
      localMax = 0;
      startIdx = i+1;
    }

    // maximixing globally
    if (localMax > globalMax) {
      globalMax = localMax;
      buyDay = startIdx;
      sellDay = i+1;
    }
  }
  if (globalMax)
    printf("Buy on %d. Sell on %d. Earn: %d\n", buyDay, sellDay, globalMax);
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {100, 180, 260, 310, 40, 535, 695}; */
  /* int arr[] = {10, 14, 17, 22, 23, 40, 49, 55, 65, 75}; */
  /* int arr[] = {56, 63, 74, 70, 93, 62, 97, 30, 25, 0}; */
  int arr[] = {27, 95, 84, 92, 95, 32, 14, 51, 91, 35};
  /* int arr[] = {97, 73, 67, 66, 60, 30, 26, 18, 3, 3}; */
  int len = sizeof(arr)/sizeof(arr[0]);

  /* tradeStocks(arr, len); */
  tradeStocksOnce(arr, len);
  return 0;
}
