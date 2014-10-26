#include <iostream>
#include <stdlib.h>
#include <queue>
#include "mylib.h"
using namespace std;

class node {
  public:
    node *left;
    node *right;
    int data;

    node(int k) {
      left = NULL;
      right = NULL;
      data = k;
    }
};

class BST {
  public:
    node *root;

    BST() {
      root = NULL;
    }

    void insert(int data) {
      node *elem = new node(data),
           *n = root;

      if(!root) {
        root = elem;
      }
      else {
        while(n) {
          if(data < n->data) {
            if(n->left) {
              n = n->left;
            }
            else {
              n->left = elem;
              return;
            }
          }
          else {
            if(n->right) {
              n = n->right;
            }
            else {
              n->right = elem;
              return;
            }
          }
        }
      }
    }

    void inOrder() {
      _inOrder(root);
      if (root) {
        cout << endl;
      }
    }

    void preOrder() {
      _preOrder(root);
      if (root) {
        cout << endl;
      }
    }

    void recursiveLeveWiseSum(node *n, int level, int currLevel, int *sum) {
      if (n == NULL || currLevel > level) {
        return;
      }
      recursiveLeveWiseSum(n->left, level, currLevel+1, sum);
      recursiveLeveWiseSum(n->right, level, currLevel+1, sum);
      if (currLevel == level) {
        *sum = *sum + n->data;
      }
    }

  private:
    void _inOrder(node *n) {
      if(!n)
        return;
      _inOrder(n->left);
      cout << n->data << " ";
      _inOrder(n->right);
    }

    void _preOrder(node *n) {
      if(!n)
        return;
      cout << n->data << " ";
      _preOrder(n->left);
      _preOrder(n->right);
    }
};

int main() {
  BST *tree = new BST();

  int length = 7;
  int values[] = {20, 8, 22, 4, 12, 10, 14};
  for(int i=0; i < length; i++) {
    tree->insert(values[i]);
  }

  tree->inOrder();
  tree->preOrder();

  for (int i=0; i < 6; i++) {
    int sum = 0;
    tree->recursiveLeveWiseSum(tree->root, i, 1, &sum);
    cout << i << " " << sum << endl;
  }
  return 0;
}
