#include<iostream>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Binary search in a rotated array
int binarySearch(int arr[], int len, int rot, int num, int low, int high) {
  /* printf("low: %d; high: %d\n", low, high); */
  if (low <= high) {
    int mid = (low + high)/2;
    if (num == arr[(rot + mid) % len]) {
      return mid;
    }
    if (num > arr[(rot + mid) % len]) {
      return binarySearch(arr, len, rot, num, mid + 1, high);
    }
    return binarySearch(arr, len, rot, num, low, mid - 1);
  }
  return -1;
}

int rotateArray1(int arr[], int len, int rot) {
  int temp[rot];

  // storing 'rot' elements in a temp array
  for (int i = 0; i < rot; i++) {
    temp[i] = arr[i];
  }

  // copying the len-rot elements to correct places
  for (int i = rot; i < len; i++) {
    arr[i - rot] = arr[i];
  }

  // finally, 'rot' elements will be appended at the back
  for (int i = 0; i < rot; i++) {
    arr[len - rot + i] = temp[i];
  }
}

int rotateArray2(int arr[], int len, int rot) {
  for (int i = 0; i < rot; i++) {
    int temp = arr[0];
    for (int j = 1; j < len; j++) {
      /* printf("i: %d; (i + len - rot) mod len: %d\n", i, (i + len - rot) % len); */
      arr[j - 1] = arr[j];
    }
    arr[len - 1] = temp;
  }
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {72, 73, 73, 75, 80, 85, 89, 1, 5, 7, 11, 20, 20, 21, 39, 43, 43, 44, 48, 53}; */
  /* int len = 20, rot = 7; */
  /* int arr[] = {1, 5, 7, 11, 20, 20, 21, 39, 43, 43, 44, 48, 53, 72, 73, 73, 75, 80, 85, 89}; */
  /* int len = 20, rot = 0; */
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int len = 7, rot = 2;

  printArray(arr, len);

  for (int i = 0; i < 5; i++) {
    rotateArray1(arr, len, rot);
    printArray(arr, len);
  }
  /* for (int i = rot; i < len + rot; i++) { */
  /*   cout << arr[i % 20] << " "; */
  /* } */
  /* cout << endl; */

/*   cout << binarySearch(arr, len, rot, 11, 0, len - 1) << endl; */
/*   cout << binarySearch(arr, len, rot, 20, 0, len - 1) << endl; */
/*   cout << binarySearch(arr, len, rot, 21, 0, len - 1) << endl; */
/*   cout << binarySearch(arr, len, rot, 80, 0, len - 1) << endl; */
/*   cout << binarySearch(arr, len, rot, 89, 0, len - 1) << endl; */
/*   cout << binarySearch(arr, len, rot, 43, 0, len - 1) << endl; */
/*   cout << binarySearch(arr, len, rot, 42, 0, len - 1) << endl; */
  return 0;
}
