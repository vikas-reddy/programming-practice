#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;

/* Given a string "ABCDE" denoting five people, this program outputs the gift
 * arrangement that has to be done so that every person gifts another a gift,
 * and all people will be lleft with a gift */

int swap (char *a, char *b) {
  char t = *a; *a = *b; *b = t;
}

void printArray(char arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void shuffleStr(char str[], int len) {
  char *copy = new char[len];

  for (int i = 0; i < len; i++)
    copy[i] = str[i];

  // random seed
  srand(time(NULL));

  // this runs for all elements except the first
  for (int i = len-1; i >= 1; i--) {
    int j = rand() % i;
    /* printf("%c ", str[j]); */
    swap(&str[i], &str[j]);
  }

  // O(n2) just for the first element?
  for (int i = 0; i < len; i++) {
    bool included = false;
    for (int j = 1; j < len; j++) {
      if (copy[i] == str[j])
        included = true;
    }
    if (included == false) {
      str[0] = copy[i];
      break;
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    cout << "Needs a command-line argument" << endl;
    return 1;
  }

  char *str = argv[1];
  int len = strlen(str);

  printf("%s\n", str);

  shuffleStr(str, len);

  printf("%s\n", str);
  return 0;
}
