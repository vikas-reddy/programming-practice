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

class llist {
  public:
    node* root;

    llist() {
      root = NULL;
    }

    void insert(int data) {
      node *elem = new node(data);
      if(!root) {
        root = elem;
        return;
      }

      node *ptr = root;
      while(ptr->next) {
        ptr = ptr->next;
      }
      ptr->next = elem;
    }

    void print() {
      node *ptr = root;
      while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
      }
      cout << endl;
    }

    void reverse() {
      if (!root) {
        return;
      }

      node *a = root, *b = root->next, *rev = NULL;

      while (b) {
        a->next = rev;
        rev = a;

        a = b;
        b = b->next;
      }
      a->next = rev;
      root = a;
    }

    void partialReverse(int k) {
      if (!root || !k) {
        return;
      }

      node *a = root, *b = root->next, *rev = NULL;
      int i = 0;

      for(i = 0; i < k && b; i++) {
        a->next = rev;
        rev = a;

        a = b;
        b = b->next;
      }

      if (i == k) {
        root->next = a;
        root = rev;
      }
      else {
        a->next = rev;
        root = a;
      }

    }

    // Reverse each k nodes
    void reverseEach(int k) {
      if (k < 2 || !root || !root->next) {
        return;
      }

      partialReverse(k);

      node *start = root,
           *first = NULL,
           *last = NULL;
      int cnt = 0;

      for (cnt = 0; cnt < k-1 && start->next; cnt++, start = start->next);

      // start is just before the next strip
      while (1) {
        // start;
        first = start->next;
        last = first;
        for (cnt = 0; cnt < k; cnt++, last = last->next);
        if (cnt == k) {
        }
      }
    }

    void isPalindrome() {
    }

    static node *intersection(llist *l1, llist *l2) {
      node *ptr1 = l1->root,
           *ptr2 = l2->root;
      llist *l3 = new llist();
      int data;

      while (ptr1) {
        data = ptr1->data;
        ptr2 = l2->root;
        while (ptr2 && ptr2->data < data) {
          ptr2 = ptr2->next;
        }
        if (ptr2 && ptr2->data == data) {
          l3->insert(data);
        }
        ptr1 = ptr1->next;
      }

      l3->print();
    }

    static node *recursiveIntersection(node *n1, node *n2) {
      if (n1 == NULL || n2 == NULL) {
        return NULL;
      }
      if (n1->data < n2->data) {
        return recursiveIntersection(n1->next, n2);
      }
      if (n1->data > n2->data) {
        return recursiveIntersection(n1, n2->next);
      }

      // n1->data == n2->data
      node *n = new node(n1->data);
      n->next = recursiveIntersection(n1->next, n2->next);
      return n;
    }
};

int main(int argc, char *argv[]) {
  int len = 10,
      arr1[len],
      arr2[len];

  llist *l1 = new llist(),
        *l2 = new llist();

  // fill in random numbers inside arrays
  for(int i = 0; i < len; i++) {
    arr1[i] = rand() % 25;
    arr2[i] = rand() % 25;
  }

  insertionSort(arr1, len);
  insertionSort(arr2, len);

  for (int i = 0; i < len; i++) {
    l1->insert(arr1[i]);
    l2->insert(arr2[i]);
  }

  l1->print();
  l2->print();

  llist *l3 = new llist();
  l3->root = llist::recursiveIntersection(l1->root, l2->root);
  l3->print();
}
