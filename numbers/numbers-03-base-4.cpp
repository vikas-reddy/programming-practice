#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

void base4 (int num) {
  if (num == 0)
    return;

  base4(num/4);
  cout << num % 4;
}

int main(int argc, const char *argv[])
{
  if (argc < 2)
    return 1;

  int num = atoi(argv[1]);

  base4(num);
  cout << endl;

  return 0;
}
