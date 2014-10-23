void printArray(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void insertionSort(int *arr, int len) {
  int i, j, elem;

  for (i = 1; i < len; i++) {
    elem = arr[i];
    for (j = i - 1; j >= 0 && arr[j] > elem; j--) {
      arr[j+1] = arr[j];
    }
    arr[j+1] = elem;
  }
}

/*
class stack {
  private:
    class node {
      int data;
      node *next;
      public:
        node() {
          next = NULL;
        }
    }
  public:
    node *ptr;
    stack() {
      ptr = NULL;
    }
}
*/
