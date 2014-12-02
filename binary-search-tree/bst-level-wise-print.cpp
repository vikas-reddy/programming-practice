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

    void recursiveLevelOrder(int low, int high) {
      _levelOrderTraversal(root, low, high);
      cout << endl;
    }

    void levelOrder(int low, int high) {
      if (!root) {
        return;
      }
      queue<node*> q;
      int level = 1;
      bool endOfLevel = false;
      node *marker = new node(123), *n;

      q.push(root);
      q.push(marker);
      while (!q.empty()) {
        n = q.front();
        q.pop();

        if (n == marker)
          break;
        if (level > high)
          break;

        if (level >= low) {
          cout << n->data << " ";
        }

        if (q.front() == marker) {
          q.pop();
          level++;
          endOfLevel = true;
          if (level > low) {
            cout << " - " << level - 1 << endl;
          }
        }
        if (n->left)
          q.push(n->left);
        if (n->right)
          q.push(n->right);

        if (endOfLevel) {
          q.push(marker);
          endOfLevel = false;
        }
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

    void _levelOrderTraversal(node *n, int low, int high) {
      if (!n) {
        return;
      }
      if (low <= 1 && high >= 1) {
        cout << n->data << " ";
      }
      _levelOrderTraversal(n->left, low-1, high-1);
      _levelOrderTraversal(n->right, low-1, high-1);
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

  /* tree->recursiveLevelOrder(0, 5); */
  tree->levelOrder(1, 3);
  return 0;
}
