#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int num, n, k;
  cin >> num;

  n = num;
  for (k = 10; n/k > 0; k *= 10) {
    if (n%k < k/10) {
      n = (n/k)*k + 5*(k/10) + (n%k);
    }
  }

  cout << n << endl;
  return 0;
}
