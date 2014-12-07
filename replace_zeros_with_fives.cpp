#include<iostream>
#include<stdlib.h>

using namespace std;

void changeNumber (int *n, int k) {
  // Start from the tens digit (LSD) and go upto MSD
  for (int den = 1; *n/den; den *= 10) {
    if ( (*n/den) % 10 == 0 ) {
      *n += k * den;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Needs a command-line arg" << endl;
    return 1;
  }

  int n = atoi(argv[1]);
  int k = 5;

  changeNumber(&n, k);
  cout << n << endl;
  /*
  // Old code
  int num, n, k;
  cin >> num;

  n = num;
  for (k = 10; n/k > 0; k *= 10) {
    if (n%k < k/10) {
      n = (n/k)*k + 5*(k/10) + (n%k);
    }
  }

  cout << n << endl;
  */
  return 0;
}
