#include<iostream>
#include<algorithm>
using namespace std;

/*
 * http://www.geeksforgeeks.org/dynamic-programming-set-31-optimal-strategy-for-a-game/
 *
 * This is a two-player game. Players start picking up first or last coins, and
 * they accumulate the value of the coins they pick up. There are even number
 * of coins. The problem is to determine the maximum possible amt of money that
 * player 1 can definitely win if he starts first.
 *
 */

int maxMoney(const int arr[], int f, int l) {
  if (f > l) return 0;
  if (f == l) return arr[f];
  if (f + 1 == l) return max(arr[f], arr[l]);

  int c = maxMoney(arr, f+1, l-1);
  int a = arr[f] + min(maxMoney(arr, f+2, l), c);
  int b = arr[l] + min(maxMoney(arr, f, l-2), c);
  return max(a, b);
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {8, 15, 3, 7}; */
  int arr[] = {5, 3, 7, 10};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << maxMoney(arr, 0, n-1) << endl;
  return 0;
}
