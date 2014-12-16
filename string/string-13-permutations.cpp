#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void swap (char *a, char *b) {
  char t = *a; *a = *b; *b = t;
}

/* We fix one character at a time at the beginning of the string, and recurse
 * into the (len-1) length remainder string */
void printPermutations (char *str, int f, int l) {
  // Base cases
  if (f > l)
    return;
  if (f == l)
    printf("%s\n", str);

  for (int i = f; i < l; i++) {

    // Fixing one character
    swap(str + f, str + i);

    // Recursing for the remainder of the string
    printPermutations(str, f+1, l);

    // Backtrack
    swap(str + f, str + i);
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;

  char *str = argv[1];
  int len = strlen(str);

  printPermutations(str, 0, len);

  return 0;
}
