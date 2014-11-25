#include<iostream>
#include<string.h>
using namespace std;

// dictionary look-up
bool dictContains(string s) {
  string dict[] = {"one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine", "ten"};
  int size = sizeof(dict)/sizeof(dict[0]);
  for (int i = 0; i < size; i++) {
    if (s == dict[i]) {
      return true;
    }
  }
  return false;
}

bool wordBreakRec(string s) {
  int size = s.size();
  if (size == 0) return true;

  for (int i = 1; i <= size; i++) {
    if (dictContains(s.substr(0, i)) && wordBreakRec(s.substr(i, size-i))) {
      return true;
    }
  }
  return false;
}

bool wordBreakDP(string s) {
  int size = s.size();

  // wb[i] is true if wb[0..i] is a "valid" string
  bool wb[size+1];

  for (int i = 0; i <= size; i++)
    wb[i] = false;

  for (int i = 1; i <= size; i++) {

    // This condition is for simple words that are present in the dictionary.
    // For complex words (which are a combination of two or more dictionary
    // words), the following loop will check the validity
    if (wb[i] == false && dictContains(s.substr(0, i))) {
      wb[i] = true;
    }

    if (wb[i] == true) {
      for (int j = i+1; j <= size; j++) {

        if (wb[j] == false && dictContains(s.substr(i, j-i))) {
          wb[j] = true;

          if (j == size)
            return true;
        }
      }
    }
  }
  return wb[size];
}

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    return 1;
  }

  // Recursive
  cout << wordBreakRec(argv[1]) << endl;
  cout << wordBreakDP(argv[1]) << endl;
  return 0;
}
