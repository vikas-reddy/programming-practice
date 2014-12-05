#include<iostream>
#include<string>

using namespace std;

class node {
  public:
    int k;
    node *lchild;
    node *rchild;

    node(int elem) {
      k = elem;
      lchild = NULL;
      rchild = NULL;
    }
};

class bstree {
  node* root;

  public:
    bstree() {
      root = NULL;
    }

    void insert(int k) {
      node *elem = new node(k);
      if(!root) {
        root = elem;
        return;
      }
    }

    void inOrder() {
      inOrderUtil(root);
      if (root) {
        cout << endl;
      }
    }
  private
    void inOrderUtil(node *n) {
      if (!n) {
        return;
      }

      inOrderUtil(n->lchild);
      cout << n->k << " ";
      inOrderUtil(n->rchild);
    }
};

int main(int argc, char *argv[]) {
  bstree *t = new bstree();

  for (int i = 0; i < 10; i++) {
    t->insert(rand % 100);
  }

  t->inOrder();
}
