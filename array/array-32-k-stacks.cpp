#include<iostream>
#include<stdlib.h>

using namespace std;

class stacks {
  int capacity;
  int k, ptr;
  int *arr, *topIdx, *nextIdx;

  public:
  stacks(int, int);
  ~stacks();
  bool full();
  bool empty();
  bool empty(int);
  bool push(int, int);
  bool pop(int);
  int top(int);
  void print();
};

stacks::stacks (int capacity, int k) {
  this->capacity = capacity;
  this->k = k;
  this->ptr = 0;

  arr = new int[capacity];
  nextIdx = new int[capacity];
  topIdx = new int[k];

  for (int i = 0; i < k; i++)
    topIdx[i] = -1;

  for (int i = 0; i < capacity; i++) {
    arr[i] = 0;
    nextIdx[i] = -1;
  }
}

stacks::~stacks () {
  delete arr;
  delete nextIdx;
  delete topIdx;
}

bool stacks::full() {
  return (ptr == capacity);
}

bool stacks::empty() {
  return (ptr == 0);
}

bool stacks::empty (int sn) {
  return (topIdx[sn] == -1);
}

bool stacks::push (int sn, int elem) {
  if (full())
    return false;

  arr[ptr] = elem;
  nextIdx[ptr] = topIdx[sn];
  topIdx[sn] = ptr;

  ptr++;

  return true;
}

bool stacks::pop (int sn) {
  if (empty(sn))
    return false;

  int temp = topIdx[sn];
  topIdx[sn] = nextIdx[temp];
  nextIdx[temp] = -1;

  ptr--;
  return true;
}

int stacks::top (int sn) {
  if (empty(sn))
    return -1;

  return arr[topIdx[sn]];
}

void stacks::print() {
  printf("arr:\n  ");
  for (int i = 0; i < capacity; i++)
    printf("%2d ", arr[i]);
  printf("\n");

  printf("nextIdx:\n  ");
  for (int i = 0; i < capacity; i++)
    printf("%2d ", nextIdx[i]);
  printf("\n");

  printf("topIdx:\n  ");
  for (int i = 0; i < k; i++)
    printf("%2d ", topIdx[i]);
  printf("\n");
}
/*************** End of stacks ***************/

int main(int argc, const char *argv[])
{
  // Random seed
  srand( time(NULL) );

  int capacity = 20;
  int k = 4;
  stacks s(capacity, k);

  // Insertion
  for (int i = 0; i < capacity; i++) {
    int elem = rand() % 100;
    int sn = rand() % k;

    printf("Inserting %d into %d...\n", elem, sn);

    s.push(sn, elem);
  }

  // Print the arrays
  s.print();

  // Emptying the contents of the stack
  for (int sn = 0; sn < k; sn++) {
    printf("sn: %2d\n  ", sn);
    while (!s.empty(sn)) {
      printf("%2d ", s.top(sn));
      s.pop(sn);
    }
    printf("\n");
  }

  return 0;
}
