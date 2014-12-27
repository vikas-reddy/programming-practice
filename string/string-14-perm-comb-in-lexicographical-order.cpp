#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

void printCombinations (
    char *input, bool *inc, int len, char *output, int pos
    ) {
  if (pos >= len)
    return;

  for (int i = 0; i < len; i++) {
    // Fix one letter at a time and recurse.
    // But fix a letter only if it's not already in the output string. That
    // means, no repetition!
    if (!inc[i]) {

      // Fix a letter
      output[pos] = input[i];

      // Mark it as included
      inc[i] = true;

      // Print output
      cout << output << endl;

      // Recurse
      printCombinations(input, inc, len, output, pos + 1);

      // We're done with the current letter
      inc[i] = false;
    }
  }
  // We need to do this so that "cout" prints the string properly
  output[pos] = '\0';
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;

  char *input = argv[1];
  int len = strlen(input);

  char *output = new char[len+1];
  memset(output, '\0', sizeof(output));

  bool *inc = new bool[len];
  memset(inc, false, sizeof(inc));

  // Sort the input string first
  sort(input, input + len);

  printCombinations(input, inc, len, output, 0);

  return 0;
}
