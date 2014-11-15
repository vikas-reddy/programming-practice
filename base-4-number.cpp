#include<iostream>

using namespace std;

void base4(int num) {
  if (num) {
    base4(num / 4);
    cout << num % 4;
  }
}

int main(int argc, const char *argv[])
{
  int num;
  cin >> num;

  base4(num);
  cout << endl;
  return 0;
}
