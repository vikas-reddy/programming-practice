#include <iostream>
#include <stdlib.h>

using namespace std;

  /* // print 2d array */
  /* for (int i = 0; i < 3; i++) { */
  /*   for (int j = 0; j < 3; j++) { */
  /*     cout << (*arr)[i][j] << " "; */
  /*   } */
  /*   cout << endl; */
  /* } */

/* bool isPresent(char (*arr)[3][3], int (*m)[8][2], char *str, int len) { */
bool isPresent(char (*arr)[3], int (*m)[2], char *str, int len) {
  if (len == 0) {
    return true;
  }

  cout << "here..." << endl;
  // find the location of (*str)
  /* isPresent(arr, m, str, len); */
}

int main() {
  char arr[3][3] = {
    {'b', 't', 'g'},
    {'p', 'a', 'd'},
    {'r', 'k', 'j'}
  };

  int moves[8][2] = {
    {1, -1},
    {1, 0},
    {1, 1},
    {0, -1},
    {0, 1},
    {-1, -1},
    {-1, 0},
    {-1, 1}
  };

  char *str;
  cout << "string = ";
  cin >> str;
  cout << str << endl;

  cout << isPresent(arr, moves, str, 3) << endl;
}
