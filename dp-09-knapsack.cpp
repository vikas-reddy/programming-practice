#include<iostream>
#include<limits.h>

using namespace std;

int getMin(int wt[], int n) {
  int min = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (min > wt[i]) {
      min = wt[i];
    }
  }
  return min;
}

int knapsackRec(int val[], int wt[], int n, int W) {
  if (n == 0 || W == 0) {
    return 0;
  }
  if (wt[n-1] > W) {
    return knapsackRec(val, wt, n - 1, W);
  }
  /* Two cases: */
  int a = val[n-1] + knapsackRec(val, wt, n - 1, W - wt[n-1]); // wt[n-1] is included in the knapsack
  int b = knapsackRec(val, wt, n - 1, W); // wt[n-1] is not included in the knapsack
  return (a > b) ? a : b; // We're maximizing the knapsack value here
}

int knapsack(int val[], int wt[], int n, int W) {
  int cost[n+1][W+1];
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0) {
        cost[i][w] = 0;
      }
      else {
        if (W < wt[i-1]) {
          cost[i][w] = cost[i-1][w];
        }
        else {
          int a = val[i-1] + cost[i-1][w - wt[i-1]];
          int b = cost[i-1][W];
          cost[i][w] = (a > b) ? a : b;
        }
      }
    }
  }
  /* for (int i = 0; i < n; i++) { */
  /*   for (int w = 0; w <= W; w++) { */
  /*     printf("%d ", cost[i][w]); */
  /*   } */
  /*   printf("\n"); */
  /* } */
  return cost[n][W];
}

int main(int argc, const char *argv[])
{
  int n = 3;
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int W = 50;

  cout << knapsackRec(val, wt, n, W) << endl;
  cout << knapsack(val, wt, n, W) << endl;
  return 0;
}
