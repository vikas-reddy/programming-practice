#include<iostream>
#include<stdlib.h>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

class MinHeap {
  public:
    int *arr;
    int size;
    MinHeap(int s, int *a) {
      size = s;
      arr = (int *)malloc(size * sizeof(int));
      for (int i = 0; i < size; i++) {
        arr[i] = a[i];
      }
    }
    void print() {
      for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
    void heapify() {
      int i = 1;
      while (i < size) {
        while (parent(i) >= 0 && arr[i] < arr[parent(i)]) {
          swap(&arr[i], &arr[parent(i)]);
          i = parent(i);
        }
        i++;
      }
    }
    void extractMin() {
    }
    int lchild(int n) { return 2*n + 1; }
    int rchild(int n) { return 2*n + 2; }
    int parent(int n) { return (n-1)/2; }
};

int main(int argc, const char *argv[])
{
  int len = 10;
  int arr[10] = {61, 51, 7, 71, 95, 74, 73, 43, 32, 84};
  MinHeap *h = new MinHeap(len, arr);
  h->heapify();
  h->print();
  return 0;
}
