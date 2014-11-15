#include<iostream>
#include<string.h>
using namespace std;

/* aaabbc = a3b2c1
 */

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    cout << "Needs one command-line argument. Exiting!" << endl;
    return 1;
  }

  const char *string = argv[1];
  int len = strlen(string);
  int count, i, j;

  i = 0;
  while (i < len) {
    for (j = i, count = 0; j < len && string[j] == string[i]; j++, count++);
    cout << string[i] << count;
    i = j;
  }
  cout << endl;

  return 0;
}
