#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int insertionPoint (const char str[], char ch, int f, int l) {
  if (f < l) {
    int m = f + (l-f)/2;

    if (str[m] < ch && str[m+1] >= ch)
      return m+1;
    else if (str[m] >= ch)
      return insertionPoint(str, ch, f, m);
    else
      return insertionPoint(str, ch, m+1, l);
  }
  return 0;
}

int main(int argc, const char *argv[])
{
  if (argc < 3) {
    return 1;
  }

  const char *str = argv[1];
  int len = strlen(str);
  char ch = argv[2][0];

  cout << insertionPoint(str, ch, 0, len-1) << endl;

  return 0;
}
