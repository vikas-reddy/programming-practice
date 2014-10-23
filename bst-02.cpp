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

    void breadthFirstSearch() {
      if (!root) {
        return;
      }

      queue<node*> q;
      node *n;

      q.push(root);
      while (!q.empty()) {
        n = q.front();
        q.pop();
        cout << n->data << " ";

        if (n->left)
          q.push(n->left);

        if (n->right)
          q.push(n->right);
      }
      cout << endl;
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

  int length = 6;
  /* int values[] = { 60, 95, 28, 49, 7, 5, 54, 38, 46, 74 }; */
  for(int i=0; i < length; i++) {
    /* tree->insert(values[i]); */
    tree->insert(rand() % 100);
    cout << rand() % 100 << " ";
  }
  cout << endl;

  cout << "size: " << tree->size() << "; depth: " << tree->depth() << endl;

  tree->breadthFirstSearch();

  tree->inOrder();
  return 0;
}
