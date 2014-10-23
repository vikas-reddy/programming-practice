#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

void anagrams(string str, string temp, int pos) {
  if (str.length() <= 0) {
    return;
  }

  if (str.length() == 1) {
    temp.replace(pos, 1, 1, str[0]);
    cout << temp << endl;
    return;
  }

  int j;
  string s2;

  // loop over unique str[i]s to handle repetition
  for (int i=0; i < str.length(); i++) {
    temp.replace(pos, 1, 1, str[i]);

    // s2 = str - str[i]
    s2 = str;
    for (j=0; j < str.length(); j++) {
      if (s2[j] == str[i]) {
        s2.erase(j, 1);
        break;
      }
    }

    anagrams(s2, temp, pos+1);
  }
}

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    cout << "This program needs an argument!" << endl;
    return 1;
  }

  string str( (char*)argv[1] );
  string temp = str;

  anagrams(str, temp, 0);
  return 0;
}
