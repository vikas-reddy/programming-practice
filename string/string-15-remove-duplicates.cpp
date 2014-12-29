#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

#define MAX_CHARS 26

using namespace std;

// O(nlogn) because of sorting
void removeDuplicates1 (char * str, int len) {
  // Nothing to do
  if (len <= 1)
    return;

  // Sort the string first
  sort(str, str + len);

  int resultPtr = 1;

  for (int i = 1; i < len; i++) {
    if (str[i] != str[i - 1])
      str[resultPtr++] = str[i];
  }
  str[resultPtr] = '\0';
}

// O(n) algorithm; makes use of an assumption that range of characters is
// usually limited
void removeDuplicates2 (char *str, int len) {
  if (len <= 1)
    return;

  bool *flag = new bool[MAX_CHARS];
  memset(flag, false, sizeof(flag));

  int resultPtr = 0;

  for (int i = 0; i < len; i++) {
    // new character
    if (flag[str[i] - 'a'] == false) {
      flag[str[i] - 'a'] = true;
      str[resultPtr++] = str[i];
    }
  }
  str[resultPtr] = '\0';
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;

  char *str = argv[1];
  int len = strlen(str);

  cout << str << endl;

  removeDuplicates2(str, len); // in-place removal

  cout << str << endl;

  return 0;
}
