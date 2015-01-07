#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<limits.h>
using namespace std;

struct char_node {
  char ch;
  int ct;
};

int compare (const void *a, const void *b) {
  int first = ((char_node*)a)->ct;
  int second = ((char_node*)b)->ct;

  // decreasing order
  return second - first;
}

void printArray (char_node arr[], int len) {
  for (int i = 0; i < len; i++)
    printf("%c:%d ", arr[i].ch, arr[i].ct);
  printf("\n");
}

bool rearrange (char str[], int len, int d) {
  map<char,int> m;

  for (int i = 0; i < len; i++)
    m[str[i]]++;

  /* for (map<char,int>::const_iterator it = m.begin(); it != m.end(); ++it) */
  /*   printf("%c: %d\n", it->first, it->second); */

  int hsize = m.size();
  int i = 0;
  char_node *arr = new char_node[hsize];

  for (map<char,int>::const_iterator it = m.begin(); it != m.end(); ++it) {
    arr[i].ch = it->first;
    arr[i].ct = it->second;
    i++;
  }

  // Sort the array in decreasing order of char counts
  // A maxheap can also be used to "sort" the array. However, the asymptotic
  // complexity remains the same -- O(m*log(m))
  qsort( (void*)arr, hsize, sizeof(arr), compare );

  /* printArray(arr, hsize); */

  memset(str, '\0', len * sizeof(char));

  for (int i = 0; i < hsize; i++) {
    char ch = arr[i].ch;
    int ct = arr[i].ct;

    int j = i, k = 0;

    // Find the first empty slot, and start filling in characters
    while (j < len && str[j])
      j++;

    while (j < len && k < ct) {
      str[j] = ch;
      j = j + d;
      k++;
    }

    // If the above loop was terminated because of not having exhausted with
    // the chars
    if (k != ct)
      return false;
  }

  return true;
}

int main(int argc, char *argv[])
{
  if (argc < 3) {
    cout << "Usage: ./a.out string distance" << endl;
    return 1;
  }

  char *str = argv[1];
  int len = strlen(str);

  int d = atoi(argv[2]);

  if (rearrange(str, len, d)) {
    cout << str << endl;
  }
  else {
    cout << "Cannot be rearranged" << endl;
  }
  return 0;
}
