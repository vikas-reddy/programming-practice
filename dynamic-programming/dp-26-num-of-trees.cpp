#include<iostream>
#include<stdlib.h>

using namespace std;

int numTreesRec (int n) {
  if (n == 0 || n == 1)
    return n;

  int count = 0;

  // All of the `i` nodes can act as root
  for (int i = 1; i <= n; i++) {
    count += numTreesRec(i-1);
    count += numTreesRec(n-i);
  }
  return count;
}

int main(int argc, const char *argv[])
{
  if (argc < 2)
    return 1;

  int n = atoi(argv[1]);

  cout << numTreesRec(n) << endl;
  return 0;
}
