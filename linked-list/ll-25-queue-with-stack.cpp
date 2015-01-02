#include<stdlib.h>
#include<stack>
#include<iostream>

using namespace std;

/* Queue with two stacks
 * push -> O(1)
 * pop/top -> O(n) average and O(n) worst
 */
class queue1 {
  stack<int> s1, s2;

  public:
  int size() {
    return s1.size() + s2.size();
  }
  int empty() {
    return (size() == 0);
  }
  void push (int elem) {
    s1.push(elem);
  }
  int front() {
    if (empty())
      return -1;
    if (s2.empty()) {
      while (!s1.empty()) {
        int e = s1.top();
        s1.pop();
        s2.push(e);
      }
    }
    int res = s2.top();
    return res;
  }
  void pop() {
    if (empty())
      return;
    if (s2.empty()) {
      while (!s1.empty()) {
        int e = s1.top();
        s1.pop();
        s2.push(e);
      }
    }
    s2.pop();
  }
};

/* Queue with two stacks -- one auxiliary and one call stack
 * push -> O(1)
 * pop/top -> O(n) same for best, average and worst
 */
class queue2 {
  stack<int> s;

  public:

  int size() {
    return s.size();
  }

  bool empty() {
    return s.empty();
  }

  void push (int elem) {
    s.push(elem);
  }

  void pop() {
    if (s.size() == 0)
      return;

    if (s.size() == 1) {
      s.pop(); // the actual popping happens here
      return;
    }

    int elem = s.top();
    s.pop();

    // recursion
    pop();

    s.push(elem);
  }

  int front() {
    if (s.size() == 0) return -1;
    if (s.size() == 1) return s.top();

    int elem = s.top();
    s.pop();

    // recursion
    int res = front();

    s.push(elem);
    return res;
  }
};

int main() {
  int arr[] = {96, 7, 64, 50, 53, 89, 54, 6, 60, 99};
  int len = sizeof(arr)/sizeof(arr[0]);

  queue1 q;

  for (int i = 0; i < len; i++) {
    q.push(arr[i]);
  }

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  printf("\n");

  return 0;
}
