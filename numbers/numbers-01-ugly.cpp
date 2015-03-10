#include<iostream>
using namespace std;

int divideBy(int n, int factor) {
  while (n % factor == 0) {
    n = n/factor;
  }
  return n;
}

bool isUgly(int n) {
  n = divideBy(n, 2);
  n = divideBy(n, 3);
  n = divideBy(n, 5);

  return (n == 1);
}

int main(int argc, const char *argv[])
{
  int n = 1, count = 0;
  while (count <= 150) {
    if (isUgly(n)) {
      printf("%d ", n);
      count++;
    }
    n++;
  }
  printf("\n");
  return 0;
}
