#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

struct node {
  struct node *next;
  char data;
};

void insert(struct node **root, char elem) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = elem;
  n->next = *root;
  (*root) = n;
  return;
}

int sizeLL(struct node *root) {
  int size = 0;
  struct node *n = root;
  for (size = 0; n; n = n->next, size++);
  return size;
}

void printLL(struct node *root) {
  if (root) {
    struct node *n = root;
    for (n = root; n; n = n->next) {
      printf("%c", n->data);
    }
    printf("\n");
  }
}

void printReverseLL(struct node *r) {
  if (r == NULL)
    return;

  printReverseLL(r->next);
  printf("%c", r->data);
}

bool isPalindrome(struct node **first, struct node *second) {
  if (second == NULL)
    return true;

  bool isSubstrPal = isPalindrome(first, second->next);
  if (isSubstrPal == false)
    return false;

  printf("%c vs %c\n", (*first)->data, second->data);
  bool isPal = ((*first)->data == second->data);

  *first = (*first)->next;
  return isPal;
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    cout << "Needs a string as command-line arg" << endl;
    return 1;
  }

  char *str = argv[1];
  int len = strlen(argv[1]);

  // initializing an empty LL
  struct node *root = NULL;

  for (int i = 0; i < len; i++) {
    insert(&root, str[i]);
  }
  printLL(root);
  /* printReverseLL(root); printf("\n"); */

  printf("isPalindrome: %d\n", isPalindrome(&root, root));
}
