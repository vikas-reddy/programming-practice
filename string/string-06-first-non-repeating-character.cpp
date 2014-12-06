#include<iostream>
#include<string.h>
#include<map>
#include<iterator>

using namespace std;

char firstNonRepatingChar(char str[], int len) {
  map<char,bool> m;
  char res;
  for (int i = len-1; i >= 0; i--) {
    // if the char is not present
    if (m.find(str[i]) == m.end()) {
      res = str[i];
      m[str[i]] = true;
    }
    // if the current char is same as the unique element we have, reset it
    else if (res == str[i]) {
      res = '-';
    }
    /* printf("%c:%c ", str[i], res); */
  }
  return res;
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    cout << "Needs a string as command-line arg" << endl;
    return 1;
  }

  int len = strlen(argv[1]);
  cout << firstNonRepatingChar(argv[1], len) << endl;
  return 0;
}
