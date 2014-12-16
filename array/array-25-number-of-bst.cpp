#include<iostream>
#include<stdlib.h>

using namespace std;

int numBST (int n) {
  if (n <= 1)
    return 1;

  int ct = 0;
  for (int i = 1; i <= n; i++) {
    ct += numBST(i-1) * numBST(n-i);
  }
  return ct;
}

int main(int argc, const char *argv[])
{
  if (argc < 2)
    return 1;

  int n = atoi(argv[1]);

  cout << numBST(n) << endl;

  return 0;
}
