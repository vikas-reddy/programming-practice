#include<iostream>
#include<stdlib.h>

using namespace std;

class node {
  public:
  int data;
  node *left, *right;
  int lcount, rcount;

  node (int data) {
    this->data = data;
    left = NULL;
    right = NULL;
    lcount = rcount = 0;
  }
};

class BSTree {
  node *root;

  public:
  BSTree () {
    root = NULL;
  }

  void insert (int data) {
    root = insertUtil(root, data);
  }

  void inOrder () {
    inOrderUtil(root);
    printf("\n");
  }

  void preOrder () {
    preOrderUtil(root);
    printf("\n");
  }

  node *getNth(int n) {
    return getNthUtil(root, n);
  }

  private:

  node* insertUtil (node *r, int data) {
    if (r == NULL)
      return (new node(data));

    if (data < r->data) {
      r->left = insertUtil(r->left, data);
      r->lcount++;
    }
    else {
      r->right = insertUtil(r->right, data);
      r->rcount++;
    }

    return r;
  }

  /* Search for an element in O(log n). Uses the `lcount` attribute to decide
   * where to go */
  node *getNthUtil (node *r, int n) {
    if (r == NULL)
      return NULL;

    if (r->lcount == n-1)
      return r;
    if (r->lcount < n-1)
      return getNthUtil(r->right, n - r->lcount - 1);
    else
      return getNthUtil(r->left, n);
  }

  void inOrderUtil (node *r) {
    if (r == NULL)
      return;
    inOrderUtil(r->left);
    printf("%d (%d,%d)  ", r->data, r->lcount, r->rcount);
    inOrderUtil(r->right);
  }

  void preOrderUtil (node *r) {
    if (r == NULL)
      return;
    printf("%d ", r->data);
    preOrderUtil(r->left);
    preOrderUtil(r->right);
  }
};

/* MAIN */
int main(int argc, const char *argv[])
{
  int arr[] = {27, 2, 86, 12, 72, 50, 28, 51, 22, 95};
  int len = sizeof(arr)/sizeof(arr[0]);

  BSTree *t = new BSTree();

  for (int i = 0; i < len; i++) {
    t->insert(arr[i]);
  }
  t->inOrder();
  t->preOrder();

  for (int i = 0; i <= len; i++) {
    node *n = t->getNth(i);
    printf("%d th element from start: %d \n", i, n ? n->data : -1);
  }

  return 0;
}
