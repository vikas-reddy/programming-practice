#include <iostream>
#include <stdlib.h>
#include <queue>
#include <list>
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

    int size() {
      _size(root);
    }

    int depth() {
      _depth(root);
    }

    void inOrder() {
      _inOrder(root);
      if (root) {
        cout << endl;
      }
    }

    node *getLcaRecursive(node *n, int a, int b) {
      if (n == NULL) {
        return NULL;
      }

      if (a < n->data && b < n->data) {
        return getLcaRecursive(n->left, a, b);
      }
      else if (a > n->data && b > n->data) {
        return getLcaRecursive(n->right, a, b);
      }
      return n;
    }

    node *getLca(int a, int b) {
      node *n = root;
      while (n) {
        if (a < n->data && n->data < b) {
          return n;
        }
        if (a == n->data || n->data == b) {
          return n;
        }
        if (a < n->data && b < n->data) {
          n = n->left;
        }
        else if (a > n->data && b > n->data) {
          n = n->right;
        }
      }
      return n;
    }
  private:

    void _inOrder(node *n) {
      if(!n)
        return;
      _inOrder(n->left);
      cout << n->data << " ";
      _inOrder(n->right);
    }

    int _size(node *n) {
      if (n == NULL) {
        return 0;
      }
      return (1 + _size(n->left) + _size(n->right));
    }

    int _depth(node *n) {
      if (n == NULL) {
        return 0;
      }
      int dleft = _depth(n->left),
          dright = _depth(n->right);
      if (dleft > dright) {
        return (1 + dleft);
      }
      else {
        return (1 + dright);
      }
    }
};

int main() {
  BST *tree = new BST();

  int length = 10;
  int values[10] = {60, 70, 83, 32, 94, 15, 56, 75, 28, 81};
  for(int i=0; i < length; i++) {
    tree->insert(values[i]);
  }

  cout << "size: " << tree->size() << "; depth: " << tree->depth() << endl;

  tree->inOrder();

  node *lca = tree->getLcaRecursive(tree->root, 56, 81);
  if (lca) {
    cout << lca->data << endl;
  }
  else {
    cout << "no lca" << endl;
  }

  return 0;
}
