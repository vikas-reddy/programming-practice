#include<iostream>
#include<string.h>
using namespace std;

void reverse(char str[], int len) {
  int j;
  char temp;
  for (int i = 0; i < len/2; i++) {
    j = len - i - 1;
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

// Move the (l - f + 1) length string one step at a time. This has O(n**2)
// complexity
void shuffle1(char str[], int len, int f, int l) {
  char temp;
  f--;
  l--;
  while (f > 0) {
    temp = str[f - 1];
    for (int i = f; i <= l; i++) {
      str[i - 1] = str[i];
    }
    str[l] = temp;
    f--;
    l--;
  }
}

void shuffle2(char str[], int len, int f, int l) {
  reverse(str, l);
  reverse(str, l - f + 1);
  reverse(str + l - f + 1, f - 1);
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    cout << "Needs command-line arguments" << endl;
    return 1;
  }

  char *string = argv[1];
  int a, b;
  cin >> a >> b;

  shuffle2(string, strlen(string), a, b);
  cout << string << endl;
  return 0;
}
