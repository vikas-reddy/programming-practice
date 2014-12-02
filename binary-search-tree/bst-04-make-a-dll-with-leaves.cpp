#include <iostream>
#include <stdlib.h>
#include <iterator>
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

    void dllOfLeaves(node *n, node **dll) {
      if (n == NULL) {
        return;
      }
      dllOfLeaves(n->right, dll);

      // do not recurse into children of leaf nodes. Instead, insert them into
      // the doubly-linked list
      if (n->left == NULL && n->right == NULL) {
        n->right = *dll;
        if (*dll) {
          (*dll)->left = n;
        }
        *dll = n;
      }
      dllOfLeaves(n->left, dll);
    }

    bool isDllLeaf(node *n) {
      return ( (!n->left || (n->left && n->left->right == n)) &&
               (!n->right || (n->right && n->right->left == n)) );
    }

    void breakDll(node *n) {
      node *dll = NULL;

      // get the dll first, and then set the pointers of the leaves right
      getDll(n, &dll);

      node *a = dll, *b = NULL;
      while (a->right) {
        b = a->right;
        a->left = NULL;
        a->right = NULL;
        a = b;
      }
      if (b) {
        b->left = NULL;
        b->right = NULL;
      }
    }

    void getDll(node *n, node **dll) {
      if (n == NULL) {
        return;
      }
      if (*dll == NULL) {
        getDll(n->left, dll);
        if (isDllLeaf(n)) {
          *dll = n;
          return;
        }
        getDll(n->right, dll);
      }
    }

    void printDll(node *n) {
      if (n == NULL) {
        return;
      }
      while (n) {
        cout << n->data << " ";
        n = n->right;
      }
      cout << endl;
    }

    int depthWithDll(node *n) {
      if (n == NULL) {
        return 0;
      }
      if (isDllLeaf(n)) {
        return 1;
      }
      int dleft = depthWithDll(n->left), dright = depthWithDll(n->right);
      return ( ((dleft > dright) ? dleft : dright) + 1 );
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

  node *dll = NULL;
  tree->dllOfLeaves(tree->root, &dll);
  tree->printDll(dll);

  cout << "depth with dll: " << tree->depthWithDll(tree->root) << endl;
  tree->breakDll(tree->root);
  tree->inOrder();

  return 0;
}
