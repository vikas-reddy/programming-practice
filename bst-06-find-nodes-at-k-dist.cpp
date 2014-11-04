#include <iostream>
#include <stdlib.h>
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
    void preOrder() {
      if (root == NULL) {
        return;
      }
      _preOrder(root);
      cout << endl;
    }

    void printNodesAtDepth(node *n, int k) {
      if (n == NULL) {
        return;
      }
      if (k <= 1) {
        cout << n->data << endl;
        return;
      }
      printNodesAtDepth(n->left, k - 1);
      printNodesAtDepth(n->right, k - 1);
    }

    bool printAncestors(node *r, node *n) {
      if (r == NULL) {
        return false;
      }
      if (r == n) {
        return true;
      }
      if (printAncestors(r->left, n) || printAncestors(r->right, n)) {
        cout << r->data << endl;
        return true;
      }
      else {
        return false;
      }
    }

    int printNodesAtDistance(node *r, node *n, int k) {
      if (r == NULL || n == NULL || k < 1) {
        return -1;
      }
      if (r == n) {
        printNodesAtDepth(n, k);
        return 0;
      }
      int dl = printNodesAtDistance(r->left, n, k);
      if (dl != -1) {
        if (dl + 1 == k) {
          // r is a k-distance ancestor of n
          cout << r->data << endl;
        }
        else {
          printNodesAtDepth(r->right, k - dl - 2);
        }
        return dl + 1;
      }
      int dr = printNodesAtDistance(r->right, n, k);
      if (dr != -1) {
        if (dl + 1 == k) {
          // r is a k-distance ancestor of n
          cout << r->data << endl;
        }
        else {
          printNodesAtDepth(r->left, k - dl - 2);
        }
        return dr + 1;
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
      if (!n) {
        return;
      }
      cout << n->data << " ";
      _preOrder(n->left);
      _preOrder(n->right);
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
  int arr[50] = {
    100,
    90, 95, 92, 97, 93, 91, 96, 98,
    80, 85, 82, 87, 83, 81, 86,
    70, 75, 72, 77, 73, 71, 76,
    10,
    50,
      20, 15, 25, 12, 14, 13, 29, 26, 27,
      60, 55, 65, 52, 53, 51, 59, 57, 56, 61, 64, 63, 66, 69, 67, 68
  };

  for (int i = 0; i < 50; i++) {
    tree->insert(arr[i]);
  }
  tree->inOrder();
  tree->preOrder();

  node *n = tree->root->left->left->left->left->right;
  /* node *n = tree->root->left->left; */
  int k = 3;
  tree->printNodesAtDistance(tree->root, n, k);
  return 0;
}
