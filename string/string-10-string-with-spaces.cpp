#include<iostream>
#include<stdlib.h>
#include<string.h>

/*
 *
 * Given a string you need to print all possible strings that can be made by
 * placing spaces (zero or one) in between them. For example : ABC -> A BC, AB
 * C, ABC, A B C
 *
 */

void printString (char *str, int len) {
  for (int i = 0; i < len; i++) {
    printf("%c", str[i]);
  }
  printf("\n");
}

void printSpaces (char *str, int strLen, char *temp, int tempLen) {
  switch (strLen) {
    // Base case
    case 0:
      printString (temp, tempLen);
      break;

    // One-character string
    case 1:
      temp[tempLen++] = str[0];
      printSpaces (str + 1, strLen - 1, temp, tempLen);
      break;

    // strLen >= 2
    default:
      // recurse without space
      temp[tempLen++] = str[0];
      printSpaces (str + 1, strLen - 1, temp, tempLen);

      temp[tempLen++] = ' ';
      printSpaces (str + 1, strLen - 1, temp, tempLen);
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;

  char *str = argv[1];
  int strLen = strlen(str);

  char *temp = new char[2*strLen - 1];
  int tempLen = 0;

  printSpaces (str, strLen, temp, tempLen);
  return 0;
}
