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

    void inOrderList(list<node*> *l, node *n) {
      if (n == NULL) {
        return;
      }
      inOrderList(l, n->left);
      (*l).push_back(n);
      inOrderList(l, n->right);
    }

    void correct() {
      list<node*> l;

      // generate the inorder list
      inOrderList(&l, root);

      // get the two swapped nodes
      node *a = NULL, *b = NULL;
      list<node*>::iterator it1, it2;
      bool is_first = true;
      for (it1 = l.begin(); it1 != l.end(); it1++) {
        it2 = ++it1;
        it1--;
        // ignore the last invalid pair
        if (it2 != l.end()) {
          if ( (*it1)->data > (*it2)->data ) {
            if (is_first) {
              a = (*it1);
              is_first = false;
            }
            b = (*it2);
          }
        }
      }

      if (a == NULL && b == NULL) {
        // nothing is wrong with the tree
        return;
      }
      cout << a->data << " " << b->data << endl;

      node *p_a = parentOf(a, b), *p_b = parentOf(b, a), *temp;
      if (p_a)
        cout << "parent of a(" << a->data << "): " << p_a->data << endl;
      if (p_b)
        cout << "parent of b(" << b->data << "): " << p_b->data << endl;

      // rearranging so that only p_a can be NULL
      if (p_b == NULL) {
        p_b = p_a;
        p_a = NULL;
      }

      // rearranging children
      temp = b->left;
      b->left = a->left;
      a->left = temp;

      temp = b->right;
      b->right = a->right;
      a->right = temp;

      if (p_b->left == b) {
        p_b->left = a;
      }
      else {
        p_b->right = a;
      }

      if (p_a) {
        if (p_a->left == a) {
          p_a->left = b;
        }
        else {
          p_a->right = b;
        }
      }
      else {
        root = b;
      }

    }

    // Find the parent of a using details of b
    node *parentOf(node *a, node *b) {
      node *p = NULL, *t = root;
      while (t != b) {
        // left subtree
        if (b->data < t->data) {
          p = t;
          if (t->left) {
            if (t->left->data == a->data) {
              break;
            }
            t = t->left;
          }
          else {
            break;
          }
        }
        // right subtree
        else {
          if (t->right) {
            if (t->right->data == a->data) {
              p = t;
              break;
            }
            t = t->right;
          }
          else {
            break;
          }
        }
      }
      return p;
    }


    void find_violating_nodes(node *n, node **first, node **second, node **prev) {
      if (n == NULL)
        return;

      find_violating_nodes(n->left, first, second, prev);

      if ( *prev && (*prev)->data > n->data) {
        if (!*first) {
          *first = *prev;
        }
        *second = n;
      }
      *prev = n;

      find_violating_nodes(n->right, first, second, prev);
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

  /* cout << "size: " << tree->size() << "; depth: " << tree->depth() << endl; */
  /* tree->breadthFirstSearch(); */

  // correct inorder
  tree->inOrder();

  // swapping the node data
  /* tree->root->left->left->right->data = 81; */
  /* tree->root->right->right->left->right->data = 28; */
  tree->root->left->data = 70;
  tree->root->right->data = 32;

  // incorrect inorder
  tree->inOrder();

  // correct the tree
  /* tree->correct(); */

  /* tree->inOrder(); */
  node *first = NULL, *second = NULL, *prev = NULL;
  tree->find_violating_nodes(tree->root, &first, &second, &prev);
  if (first)
    cout << first->data << endl;
  if (second)
    cout << second->data << endl;

  return 0;
}
