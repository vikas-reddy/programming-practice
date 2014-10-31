#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;

class node {
  public:
    int data;
    node *left;
    node *right;

    node (int d) {
      data = d;
      left = NULL;
      right = NULL;
    }
};

class tree {
  public:
    node *root;

    tree () {
      root = NULL;
    }

    void levelOrder() {
      if (!root) {
        return;
      }
      node *n, *marker = new node(100);
      queue<node*> q;
      bool markerFound = false;
      int level = 0;
      q.push(root);
      q.push(marker);

      while (!q.empty()) {
        n = q.front();
        q.pop();
        cout << n->data << " ";

        if (q.front() == marker) {
          markerFound = true;
          cout << "(" << ++level << ") ";
          q.pop();
        }

        if (n->left) {
          q.push(n->left);
        }
        if (n->right) {
          q.push(n->right);
        }

        if (markerFound) {
          q.push(marker);
          if (q.size() == 1) {
            break; // end of tree
          }
          markerFound = false;
        }
      }

      cout << endl;
    }

    void spiralOrder(node *n) {
    }

    void printAtLevel(node *n, int level, int ltr) {
      if (n == NULL || level < 1) {
        return;
      }
      if (level == 1) {
        cout << n->data << " ";
      }
      else {
        if (ltr) {
          printAtLevel(n->left, level - 1, ltr);
          printAtLevel(n->right, level - 1, ltr);
        }
        else {
          printAtLevel(n->right, level - 1, ltr);
          printAtLevel(n->left, level - 1, ltr);
        }
      }
    }

    void preOrder(node *n) {
      if (!n) {
        return;
      }
      cout << n->data << " ";
      preOrder(n->left);
      preOrder(n->right);
    }
};

int main(int argc, const char *argv[])
{
  tree *t = new tree();
  t->root = new node(12);
  t->root->left = new node(6);
  t->root->left->left = new node(4);
  t->root->left->right = new node(7);
  t->root->left->right->left = new node(13);
  t->root->left->right->right = new node(1);
  t->root->right = new node(10);
  t->root->right->left = new node(9);
  t->root->right->left->right = new node(5);
  t->root->right->right = new node(3);
  t->root->right->right->right = new node(2);

  t->preOrder(t->root);
  cout << endl;

  t->levelOrder();

  for (int i = 1; i < 6; i++) {
    cout << "(" << i << ")" << endl;
    t->printAtLevel(t->root, i, i % 2 == 0);
    cout << endl;
  }
  return 0;
}
