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

  private:

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
  int arr[] = {27, 2, 86, 12, 72, 50, 28, 51, 22, 95};
  int len = sizeof(arr)/sizeof(arr[0]);

  BSTree *t = new BSTree();

  for (int i = 0; i < len; i++) {
    t->insert(arr[i]);
  }
  t->inOrder();
  t->preOrder();

  return 0;
}
