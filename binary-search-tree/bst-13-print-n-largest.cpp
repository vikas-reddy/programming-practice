#include<iostream>
#include<stdlib.h>
#include<stack>

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

  void printLargestRec (int n) {
    int curr = 0;
    printLargestUtil(root, n, &curr);
    printf("\n");
  }

  void printLargest (int n) {
    if (root == NULL || n <= 0)
      return;

    stack<node*> s;
    node *temp, *nd;
    int ct = 0;

    // Insertion
    for (temp = root; temp; temp = temp->right)
      s.push(temp);

    while (!s.empty()) {
      nd = s.top();
      s.pop();

      printf("%d ", nd->data);
      ct++;

      if (ct == n) {
        // s.clear();
        break;
      }

      for (temp = nd->left; temp; temp = temp->right)
        s.push(temp);
    }
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

  // Does a reverse in-order traversal. Stops recursing after we print the
  // largest n elements.
  void printLargestUtil (node *r, int n, int *curr) {
    if (r == NULL || *curr >= n)
      return;

    printLargestUtil(r->right, n, curr);

    if (*curr < n) {
      printf("%d ", r->data);
      (*curr)++;
    }
    if (*curr < n)
      printLargestUtil(r->left, n, curr);
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

  for (int n = 0; n <= len + 2; n++) {
    printf("%d largest: ", n);
    t->printLargest(n);
  }
  return 0;
}
