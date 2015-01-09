#include<iostream>
#include<string.h>
#include<map>

#define ALPHABET 26

using namespace std;

void printCounts (bool ct[], int n) {
  for (int i = 0; i < n; i++)
    printf("%c", 'a' + i);
  printf("\n");

  for (int i = 0; i < n; i++)
    printf("%d", ct[i]);
  printf("\n");
}

void computeAnd (bool res[], bool ct[]) {
  for (int i = 0; i < ALPHABET; i++)
    res[i] &= ct[i];
}

void findCommon1 (char *str[], int n) {
  bool res[ALPHABET];
  memset(res, true, sizeof(res));

  bool ct[ALPHABET];

  printCounts(res, ALPHABET);

  for (int i = 0; i < n; i++) {
    memset(ct, false, sizeof(ct));

    for (int j = 0; j < strlen(str[i]); j++)
      ct[str[i][j] - 'a'] = true;

    computeAnd(res, ct);
  }
  printCounts(res, ALPHABET);
}

void findCommon2 (char *str[], int n) {
  map<char,bool> res, t1, t2;

  for (int j = 0; j < strlen(str[0]); j++)
    res[str[0][j]] = true;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < strlen(str[i]); j++) {
      if (res.find(str[i][j]) != res.end())
        t1[str[i][j]] = true;
    }
    res = t1;
    t1.clear();
  }

  if (res.size()) {
    for (map<char,bool>::const_iterator i = res.begin(); i != res.end(); ++i) {
      printf("%c", i->first);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[])
{
  if (argc < 1)
    return 1;

  findCommon2(argv + 1, argc - 1);

  return 0;
}
