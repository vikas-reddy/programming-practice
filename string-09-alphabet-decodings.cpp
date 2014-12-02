#include<iostream>
#include<stdlib.h>
#include<string.h>
#define ALPHABET_SIZE 26

using namespace std;

int numDecodingsRec(char *str, int len) {
  if (len == 0 || len == 1)
    return 1;

  int count = 0;

  // last digit is not zero
  if ('9' >= str[len-1] && str[len-1] >= '1')
    count += numDecodingsRec(str, len-1);

  // last digit is either zero or the last two digits form a valid number
  if ( (str[len-2] <= '1') ||
      (str[len-2] == '2' && str[len-1] <= '6') )
    count += numDecodingsRec(str, len-2);

  return count;
}

int numDecodingsDP(char *str, int len) {
  int dec[len+1];

  dec[0] = dec[1] = 1;

  for (int l = 2; l <= len; l++) {

    int count = 0;

    // last digit is not zero
    if ('9' >= str[l-1] && str[l-1] >= '1')
      count += dec[l-1];

    // last digit is either zero or the last two digits form a number below 26
    if ( (str[l-2] <= '1') ||
        (str[l-2] == '2' && str[l-1] <= '6') )
      count += dec[l-2];

    dec[l] = count;
  }
  return dec[len];
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    cout << "Needs the number as argument" << endl;
    return 1;
  }

  char *str = argv[1];
  int len = strlen(str);

  cout << numDecodingsRec(str, len) << endl;
  cout << numDecodingsDP(str, len) << endl;
  return 0;
}
