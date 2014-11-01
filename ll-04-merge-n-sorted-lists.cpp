#include <iostream>
#include <stdlib.h>

using namespace std;

class node {
  public:
    int data;
    node *next;
    node(int d) {
      data = d;
      next = NULL;
    }
};

class llist {
  public:
    node *start;
    llist() {
      start = NULL;
    }
    llist(node *n) {
      start = n;
    }
    void insert(int data) {
      node *n = new node(data);
      n->next = start;
      start = n;
    }
    void print() {
      if (start == NULL) {
        cout << "empty" << endl;
        return;
      }
      node *n = start;
      while (n) {
        cout << n->data << " ";
        n = n->next;
      }
      cout << endl;
    }
    int size() {
      node *n = start;
      int i = 0;
      for (n = start; n; n = n->next, i++);
      return i;
    }
};

bool areAllEmpty(node **lists, int n) {
  for (int i = 0; i < n; i++) {
    if (lists[i]) {
      return false;
    }
  }
  return true;
}

node *extractOneNonEmpty(node **lists, int n) {
  int nonEmptyCount = 0;
  node *nonEmptyList = NULL;
  for (int i = 0; i < n; i++) {
    if (lists[i]) {
      if (nonEmptyCount >= 1) {
        return NULL;
      }
      nonEmptyList = lists[i];
      nonEmptyCount++;
    }
  }
  return nonEmptyList;
}

int extractMinIdx(node **lists, int n) {
  node *min = NULL;
  int minIdx;
  for (int i = 0; i < n; i++) {
    if (lists[i]) {
      if (!min) {
        min = lists[i];
        minIdx = i;
      }
      else {
        if (min->data > lists[i]->data) {
          min = lists[i];
          minIdx = i;
        }
      }
    }
  }
  return minIdx;
}

node *mergeLists(node **lists, int n) {
  bool allEmpty = areAllEmpty(lists, n);
  if (allEmpty) {
    cout << "allEmpty" << endl;
    return NULL;
  }

  node *nonEmpty = extractOneNonEmpty(lists, n);
  if (nonEmpty) {
    return nonEmpty;
  }

  int minIdx = extractMinIdx(lists, n);
  node *min = lists[minIdx];
  lists[minIdx] = lists[minIdx]->next;
  min->next = mergeLists(lists, n);
  return min;
}

int main(int argc, const char *argv[])
{
  int n = 5;
  node *starts[n];
  llist *lls[n];
  int arr1[] = {86, 83, 82, 73, 38, 16, 12, 7, 2, 0}, len1 = 10;
  int arr2[] = {99, 94, 94, 77, 59, 56, 47, 29, 24, 16}, len2 = 10;
  int arr3[] = {79, 77, 69, 66, 58, 43, 23, 5, 3, 1}, len3 = 10;
  int arr4[] = {83, 70, 69, 61, 28, 28, 27, 17, 11, 3}, len4 = 10;
  int arr5[] = {97, 80, 79, 75, 69, 60, 58, 43, 21, 5}, len5 = 10;

  lls[0] = new llist();
  for (int i = 0; i < len1; i++) {
    lls[0]->insert(arr1[i]);
  }
  starts[0]  = lls[0]->start;

  lls[1] = new llist();
  for (int i = 0; i < len2; i++) {
    lls[1]->insert(arr2[i]);
  }
  starts[1]  = lls[1]->start;

  lls[2] = new llist();
  for (int i = 0; i < len3; i++) {
    lls[2]->insert(arr3[i]);
  }
  starts[2]  = lls[2]->start;

  lls[3] = new llist();
  for (int i = 0; i < len4; i++) {
    lls[3]->insert(arr4[i]);
  }
  starts[3]  = lls[3]->start;

  lls[4] = new llist();
  for (int i = 0; i < len5; i++) {
    lls[4]->insert(arr5[i]);
  }
  starts[4]  = lls[4]->start;

  lls[0]->print();
  lls[1]->print();
  lls[2]->print();
  lls[3]->print();
  lls[4]->print();

  /* cout << extractMinIdx(starts, n) << endl; */
  /* cout << (extractOneNonEmpty(starts, n) == NULL) << endl; */
  llist *res = new llist(mergeLists(starts, n));
  res->print();
  cout << "size: " << res->size() << endl;
  return 0;
}
