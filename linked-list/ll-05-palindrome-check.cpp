#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <iterator>

using namespace std;

struct node {
  char data;
  struct node *next;
};

struct node* newNode(char data) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->next = NULL;
  return n;
}

int elemsToCheck(float num) {
  num = num/2.0;
  if ((int)num == num) {
    return num - 1;
  }
  else {
    return (int)num;
  }
}

void insert(struct node **root, char data) {
  struct node *n = newNode(data);
  n->next = *root;
  *root = n;
}

void print(struct node *root) {
  while (root) {
    printf("%c ", root->data);
    root = root->next;
  }
  printf("\n");
}

int length(struct node *root) {
  int l = 0;
  while (root) {
    l++;
    root = root->next;
  }
  return l;
}

// palindrome without extra space O(n2)
int isPalindrome1(struct node *root) {
  int len = length(root), i, j, dist;
  struct node *n;
  for (i = 0; i < len/2; i++) {
    
    // compute the distance to travel to check its counterpart
    dist = len - 2*i - 1;

    // traversing 'dist' nodes
    for (n = root, j = 0; j < dist; j++, n = n->next);

    // check
    if (root->data != n->data) {
      return 0;
    }

    root = root->next;
  }
  // if the control gets here, this is a palindrome
  return 1;
}

int isPalindrome2(struct node *root) {
  int len = length(root), i, j, k = elemsToCheck(len);
  struct node *n = root;
  stack<struct node*> s;
  printf("%d\n", k);
  for (i = 0; i <= k; i++) {
    /* printf("%c ", n->data); */
    s.push(n);
    n = n->next;
  }
  printf("%c:%c\n", s.top()->data, n->data);
  /* printf("\n"); */
  return 1;
}

int main(int argc, const char *argv[])
{
  if (argc > 1) {
    const char *str = argv[1];
    int len = strlen(str), i;
    struct node *root = NULL;

    printf("%s:%d\n", str, len);

    for (i = 0; i < len; i++) {
      insert(&root, str[i]);
    }

    print(root);
    printf("%d\n", isPalindrome2(root));
    return 0;
  }
}
