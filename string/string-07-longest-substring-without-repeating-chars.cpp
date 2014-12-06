#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>

using namespace std;

int longestSubstr(char str[], int n) {
  map<char,int> m;
  int len = 0, lenMax = 0;
  for (int i = 0; i < n; i++) {

    // unvisited character
    if (m.find(str[i]) == m.end()) {
      len++;
    }
    else {
      // If the last occurence of the elment doesn't appear in the longest
      // length.
      if (i - m[str[i]] > len)
        len++;
      else
        len = i - m[str[i]];
    }
    m[str[i]] = i;
    lenMax = max(len, lenMax);
  }
  /* lenMax = max(len, lenMax); */
  return lenMax;
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    cout << "Needs a command-line arg" << endl;
    return 1;
  }

  int len = strlen(argv[1]);
  cout << longestSubstr(argv[1], len) << endl;
  return 0;
}
