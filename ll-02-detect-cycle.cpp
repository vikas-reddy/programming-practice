#include<iostream>
#include<stdlib.h>
#include<string>
#include "mylib.h"

using namespace std;

class node {
  public:
    int data;
    node* next;

    node(int elem) {
      next = NULL;
      data = elem;
    }
};

void removeCycleBasic(node *root) {
  if (!root) {
    return;
  }
  int i = 1, j;
  node *n = root->next, *p;
  while (n) {
    p = root;
    j = 0;
    while (p != n->next) {
      p = p->next;
      j++;
    }
    if (j < i) {
      n->next = NULL;
      return;
    }
    n = n->next;
    i++;
  }
}

bool hasCycleBasic(node *root) {
  if (!root) {
    return false;
  }
  int i = 1, j;
  node *n = root->next, *p;
  while (n) {
    p = root;
    j = 0;
    while (p != n) {
      p = p->next;
      j++;
    }
    if (j < i) {
      cout << "cycle at " << n->data << endl;
      return true;
    }
    /* cout << n->data << " " << i << " " << j << endl; */
    n = n->next;
    i++;
  }
  return false;
}

void printList(node *root) {
  if (root) {
    for (node *n = root; n; n = n->next) {
      cout << n->data << " ";
    }
    cout << endl;
  }
}

void removeCycleFloyd(node *root, node *loopNode) {
  node *ptr1, *ptr2;

  ptr1 = root;
  while (1) {
    ptr2 = loopNode;
    while (ptr2->next != loopNode && ptr2->next != ptr1) {
      ptr2 = ptr2->next;
    }
    if (ptr2->next == ptr1) {
      cout << "junction at " << ptr2->next->data << endl;
      ptr2->next = NULL;
      return;
    }
    ptr1 = ptr1->next;
  }
}

void cycleDetectionFloyd(node *root) {
  node *slow_p = root, *fast_p = root;

  while (slow_p && fast_p && fast_p->next) {
    slow_p = slow_p->next;
    fast_p = fast_p->next->next;

    if (slow_p == fast_p) {
      cout << "Cycle found" << endl;
      removeCycleFloyd(root, slow_p);
      return;
    }
  }
  cout << "No cycles!" << endl;
}

int main(int argc, const char *argv[]) {
  node *root;
  // 96, 7, 64, 50, 53, 89, 54, 6 -> 50, 53, 89, 54, 6 -> 50, ...
  root = new node(96);
  root->next = new node(7);
  root->next->next = new node(64);
  root->next->next->next = new node(50);
  root->next->next->next->next = new node(53);
  root->next->next->next->next->next = new node(89);
  root->next->next->next->next->next->next = new node(54);
  root->next->next->next->next->next->next->next = new node(6);
  root->next->next->next->next->next->next->next->next = root->next->next->next; // 50

  /* for (node *n = root; n; n = n->next) { */
  /*   cout << n->data << endl; */
  /* } */
  /* cout << hasCycleBasic(root) << endl; */
  /* removeCycleBasic(root); */
  cycleDetectionFloyd(root);
  printList(root);
  return 0;
}
