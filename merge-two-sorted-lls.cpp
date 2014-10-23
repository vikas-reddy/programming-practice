#include <iostream>
#include <stdlib.h>

using namespace std;

class node {
  public:
    int data;
    node* next;

  node(int d) {
    data = d;
    next = NULL;
  }
};

class llist {
  public:
    node* start;

    llist() {
      start = NULL;
    }

    llist(node *n) {
      start = n;
    }

    void push(int data) {
      node *n = new node(data);
      n->next = start;
      start = n;
    }

    void print() {
      if (start == NULL) {
        return; }

      for (node *p = start; p; p = p->next) {
        cout << p->data << " ";
      }
      cout << endl;
    }
};

node *mergeSortedLists(node *n1, node *n2) {
  if (n1 && n2) {
    if (n1->data < n2->data) {
      n1->next = mergeSortedLists(n1->next, n2);
      return n1;
    }
    else {
      n2->next = mergeSortedLists(n1, n2->next);
      return n2;
    }
  }
  return (n1 ? n1 : n2);
}

int main(int argc, char *argv[]) {
  llist *l1 = new llist(),
        *l2 = new llist();

  int arr1[10] = {95, 87, 39, 34, 34, 32, 27, 19, 17, 14},
      arr2[7] = {49, 41, 33, 32, 15, 12, 4};

  for (int i = 0; i < 10; i++)  l1->push(arr1[i]);
  for (int i = 0; i < 7;  i++)  l2->push(arr2[i]);

  l1->print();
  l2->print();

  node *res = mergeSortedLists(l1->start, l2->start);
  llist *l3 = new llist(res);
  l3->print();
  return 0;
}
