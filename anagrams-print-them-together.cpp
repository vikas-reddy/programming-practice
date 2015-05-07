#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool compare(char *a, char *b) {
  strcmp(a, b);
}

void sortArrays(char *copies[], int indexes[], int len) {
  sort(copies, copies + len, strcmp);
}

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    cout << "Needs at least one argument" << endl;
    return 1;
  }

  // Copying from argv to other arrays
  int n = argc - 1;
  char *strings[n], *copies[n];
  int indexes[n];
  for (int i = 0; i < n; i++) {
    strings[i] = (char *)malloc((n+1) * sizeof(char));
    copies[i] = (char *)malloc((n+1) * sizeof(char));
    strcpy(strings[i], argv[i + 1]);
    strcpy(copies[i], argv[i + 1]);
    indexes[i] = i;
  }

  // sort words in 'copies' array
  for (int i = 0; i < n; i++) {
    int len = strlen(copies[i]);
    sort(copies[i], copies[i] + len);
  }

  sortArrays(copies, indexes, n);

  // printing
  for (int i = 0; i < n; i++) {
    cout << copies[i] << " ";
  }
  cout << endl;
  return 0;
}
