#include<iostream>
#include<stdlib.h>

using namespace std;

class node {
  public:
  int data;
  node *left, *right;

  node (int data) {
    this->data = data;
    left = NULL;
    right = NULL;
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

  node *search (int k) {
    return searchUtil(root, k);
  }

  void printPairs (int k) {
    printPairsUtil(root, k);
  }

  private:

  void printPairsUtil (node *r, int k) {
    if (r == NULL)
      return;

    printPairsUtil(r->left, k);

    // Print pairs (x,y) only if x < y
    if (r->data < k - r->data) {
      node *n = search(k - r->data);
      if (n)
        printf("%d %d\n", r->data, n->data);
    }
    else {
      return;
    }

    printPairsUtil(r->right, k);
  }

  node *searchUtil (node *r, int k) {
    if (r == NULL)
      return NULL;

    if (r->data == k)
      return r;
    node *lsearch = searchUtil(r->left, k);
    if (lsearch)
      return lsearch;
    return searchUtil(r->right, k);
  }

  node* insertUtil (node *r, int data) {
    if (r == NULL)
      return (new node(data));

    if (data < r->data)
      r->left = insertUtil(r->left, data);
    else
      r->right = insertUtil(r->right, data);

    return r;
  }

  void inOrderUtil (node *r) {
    if (r == NULL)
      return;
    inOrderUtil(r->left);
    printf("%d ", r->data);
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
  int arr[] = {5, 9, 2, 8, 6, 3, 1, 4, 10, 7};
  int len = sizeof(arr)/sizeof(arr[0]);

  BSTree *t = new BSTree();

  for (int i = 0; i < len; i++) {
    t->insert(arr[i]);
  }
  t->inOrder();
  t->preOrder();

  t->printPairs(12);
  return 0;
}
