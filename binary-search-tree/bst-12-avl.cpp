#include<iostream>
#include<stdlib.h>

using namespace std;

class TNode {
  public:
  int data;
  int height;
  TNode *left, *right;

  TNode (int data) {
    this->data = data;
    this->height = 1;
    left = NULL;
    right = NULL;
  }
};

class AVLTree {
  TNode *root;

  public:
  AVLTree () {
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

  TNode* insertUtil (TNode *r, int data) {
    if (r == NULL)
      return (new TNode(data));

    if (data < r->data)
      r->left = insertUtil(r->left, data);
    else
      r->right = insertUtil(r->right, data);

    if (getBalance(r) < -1) {
      if (data < r->left->data) {
        r = rightRotate(r);
      }
      else {
        r->left = leftRotate(r->left);
        r = rightRotate(r);
      }
    }

    if (getBalance(r) > 1) {
      if (data > r->right->data) {
        r = leftRotate(r);
      }
      else {
        r->right = rightRotate(r->right);
        r = leftRotate(r);
      }
    }

    r->height = computeHeight(r);
    return r;
  }

  TNode *leftRotate (TNode *r) {
    if (r && r->right) {
      TNode *x = r, *y = r->right;
      TNode *T1 = y->left;

      y->left = x;
      x->right = T1;

      x->height = computeHeight(x);
      y->height = computeHeight(y);

      return y;
    }
    return r;
  }

  TNode *rightRotate (TNode *r) {
    if (r && r->left) {
      TNode *x = r, *y = r->left;
      TNode *T1 = y->right;

      y->right = x;
      x->left = T1;

      x->height = computeHeight(x);
      y->height = computeHeight(y);

      return y;
    }
    return r;
  }

  void updateHeights (TNode *r) {
    if (r == NULL)
      return;
    updateHeights(r->left);
    updateHeights(r->right);
    r->height = getHeight(r);
  }

  int getBalance (TNode *r) {
    if (r == NULL)
      return 0;

    return getHeight(r->right) - getHeight(r->left);
  }

  int computeHeight (TNode *r) {
    if (r == NULL)
      return 0;
    return max(getHeight(r->left), getHeight(r->right)) + 1;
  }

  int getHeight (TNode *r) {
    return (r ? r->height : 0);
  }

  void inOrderUtil (TNode *r) {
    if (r == NULL)
      return;
    inOrderUtil(r->left);
    printf("%d (%d)  ", r->data, r->height);
    inOrderUtil(r->right);
  }

  void preOrderUtil (TNode *r) {
    if (r == NULL)
      return;
    printf("%d (%d)  ", r->data, r->height);
    preOrderUtil(r->left);
    preOrderUtil(r->right);
  }
};

/* MAIN */
int main(int argc, const char *argv[])
{
  int arr[] = {27, 2, 86, 12, 72, 50, 28, 51, 22, 95};
  int len = sizeof(arr)/sizeof(arr[0]);

  AVLTree *t = new AVLTree();

  for (int i = 0; i < 20; i++) {
    t->insert(i);
  }
  t->inOrder();
  t->preOrder();

  return 0;
}
