#include<iostream>
#define MAX_SIZE 100
using namespace std;

template <class T>
class heap {
  T arr[MAX_SIZE];
  int size;

  public:
    heap() { size = 0; }

    int getSize() { return size; }

    // Insertion of an element at the end
    bool insert(T elem) {
      if (size == MAX_SIZE)
        return false;
      arr[size++] = elem;
      heapifyBottomUp();
      return true;
    }

    // Extracts the min element (at 0)
    T extractMin() {
      T elem = arr[0];
      arr[0] = arr[--size];
      heapifyTopDown();
      return elem;
    }

    void print() {
      for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");
    }

  private:
    int parent(int idx) { return (idx - 1)/2; }
    int left(int idx)   { return idx*2 + 1;   }
    int right(int idx)  { return idx*2 + 2;   }

    void heapifyBottomUp() {
      int idx = size - 1;
      while (idx >= 0 && arr[idx] < arr[parent(idx)]) {
        swap(&arr[idx], &arr[parent(idx)]);
        idx = parent(idx);
      }
    }

    void heapifyTopDown() {
      int idx = 0;
      while (idx < size) {
        // leaf nodes
        if (left(idx) >= size && right(idx) >= size) {
          break;
        }

        // correct node
        if (arr[idx] < arr[left(idx)] && arr[idx] < arr[right(idx)]) {
          break;
        }

        // node goes left
        if (arr[left(idx)] < arr[right(idx)]) {
          swap(&arr[idx], &arr[left(idx)]);
          idx = left(idx);
        }
        // node goes right
        else {
          swap(&arr[idx], &arr[right(idx)]);
          idx = right(idx);
        }
      }
    }

    void swap(T *a, T *b) {
      T temp = *a;
      *a = *b;
      *b = temp;
    }
};

int main(int argc, const char *argv[])
{
  int arr[] = {69, 85, 34, 32, 32, 97, 24, 57, 93, 44};
  int len = sizeof(arr)/sizeof(arr[0]);

  heap<int> h;

  for (int i = 0; i < len; i++) {
    h.insert(arr[i]);
  }
  h.print();


  for (int i = 0; i < len; i++) {
    cout << h.extractMin() << " ";
  }
  cout << endl;
  return 0;
}
