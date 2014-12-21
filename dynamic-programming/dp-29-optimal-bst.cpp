#include<iostream>
#include<limits.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int sumFreq (int freq[], int f, int l) {
  if (f > l)
    return 0;

  int sum = 0;
  for (int i = f; i <= l; i++)
    sum += freq[i];
  return sum;
}

int optBSTRec (int keys[], int freq[], int f, int l) {
  if (f > l)
    return 0;

  int min_cost = INT_MAX;

  for (int i = f; i <= l; i++) {
    int cost = (
        // left subtree goes one level deeper
        optBSTRec(keys, freq, f, i-1) + sumFreq(freq, f, i-1) +

        // current root
        freq[i] +

        // right subtree goes one level deeper
        optBSTRec(keys, freq, i+1, l) + sumFreq(freq, i+1, l)
        );

    if (min_cost > cost)
      min_cost = cost;
  }
  return min_cost;
}

int optBSTDP (int keys[], int freq[], int n) {
  int cost[n][n];

  for (int i = 0; i < n; i++)
    cost[i][i] = freq[i];

  int cum_freq[n];
  memset(cum_freq, 0, sizeof(cum_freq));

  // Cumulative freq array for easy computation of sum of frequencies
  cum_freq[0] = freq[0];
  for (int i = 1; i < n; i++)
    cum_freq[i] = cum_freq[i-1] + freq[i];

  /* for (int i = 0; i < n; i++) */
  /*   printf("%d ", cum_freq[i]); */
  /* printf("\n"); */

  for (int l = 2; l <= n; l++) {
    for (int i = 0; i < n - l + 1; i++) {
      int j = i + l - 1;
      cost[i][j] = INT_MAX;

      for (int k = i; k <= j; k++) {
        int left_cost = 0, right_cost = 0;

        if (k-1 >= i)
          left_cost = cost[i][k-1] + sumFreq(freq, i, k-1);
        if (k+1 <= j)
          right_cost = cost[k+1][j] + sumFreq(freq, k+1, j);

        int curr_cost = left_cost + right_cost + freq[k];

        if (cost[i][j] > curr_cost)
          cost[i][j] = curr_cost;
      }
    }
  }

  return cost[0][n-1];
}

int main(int argc, const char *argv[])
{
  int keys[] = {10, 12, 20};
  int freq[] = {34, 8, 50};
  int len = 3;

  cout << optBSTRec(keys, freq, 0, len-1) << endl;
  cout << optBSTDP(keys, freq, len) << endl;

  return 0;
}
