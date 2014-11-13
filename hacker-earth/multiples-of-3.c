#include <stdio.h>

int isMultiple(long long unsigned n) {
  int sum = 0;
  while (n) {
    sum += n % 10;
    n = n/10;
  }
  return (sum % 3 == 0);
}

int main() {
  int n, i, count = 0;
  long long unsigned elem;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%u", &elem);
    if (isMultiple(elem) == 1)
      count++;
  }
  printf("%d\n", count);
  return 0;
}
