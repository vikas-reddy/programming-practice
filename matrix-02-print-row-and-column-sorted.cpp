#include<iostream>

#define ROW 4
#define COL 4
#define MAX_SIZE 100

using namespace std;

/*
 *
 * Print the elements from a row-wise and column-wise sorted matrix in the
 * sorted order
 *
 * O(n2 logn)
 *
 */

class heap_node {
  public:
    int data;
    int idx;
    heap_node() {}
    heap_node(int d, int i) {
      data = d;
      idx = i;
    }
};

class heap {
  heap_node *arr[MAX_SIZE];
  int size;

  public:
    heap() { size = 0; }

    int getSize() { return size; }
    int empty() { return (size == 0); }

    // Insertion of an element at the end
    bool insert(int d, int i) {
      if (size == MAX_SIZE)
        return false;

      heap_node *elem = new heap_node(d, i);
      arr[size++] = elem;
      heapifyBottomUp();
      return true;
    }

    // Extracts the min element (at 0)
    heap_node *extractMin() {
      heap_node *elem = arr[0];
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
      while (idx >= 0 && arr[idx]->data < arr[parent(idx)]->data) {
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
        if (arr[idx]->data < arr[left(idx)]->data && arr[idx]->data < arr[right(idx)]->data) {
          break;
        }

        // node goes left
        if (arr[left(idx)]->data < arr[right(idx)]->data) {
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

    void swap(heap_node **a, heap_node **b) {
      heap_node *temp = *a;
      *a = *b;
      *b = temp;
    }
};


void printSortedOrder(int mat[][COL]) {
  heap h;

  // insert the first column into the heap
  for (int i = 0; i < ROW; i++) {
    h.insert(mat[i][0], i);
  }

  // storing the next pointers for all columns
  int next[ROW];
  for (int i = 0; i < ROW; i++) {
    next[i] = 1;
  }

  heap_node *t;
  while (!h.empty()) {
    // extract the min element from the heap and print it
    t = h.extractMin();
    printf("%d ", t->data);

    // insert the next element from the row of the removed element
    if (next[t->idx] < COL) {
      h.insert(mat[t->idx][next[t->idx]], next[t->idx] + 1);
      next[t->idx]++;
    }
  }
  printf("\n");
}

int main(int argc, const char *argv[])
{
  int mat[ROW][COL] = {
    {10, 20, 30, 40},
    {15, 25, 35, 45},
    {27, 29, 37, 48},
    {32, 33, 39, 50}
  };

  printSortedOrder(mat);
  return 0;
}
