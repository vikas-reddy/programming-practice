#include<iostream>
using namespace std;

bool eval(bool a, char op, bool b) {
  printf("%d %c %d\n", a, op, b);
  switch (op) {
    case '&': return a & b;
    case '|': return a | b;
    case '^': return a ^ b;
  }
}

bool numWays(bool syms[], char ops[], int nSyms, int nOps, int *ways) {
  /* printf("syms: %d, ops: %d\n", nSyms, nOps); */
  // base cases
  if (nSyms < 1) return false;
  if (nSyms == 1) return syms[0];

  // only two symbols to evaluate
  if (nSyms == 2) {
    if (eval(syms[0], syms[1], ops[0])) {
      (*ways)++;
      return true;
    }
    else {
      return false;
    }
  }

  int a_ways = 0, b_ways = 0;
  bool a = numWays(syms, ops, nSyms-1, nOps-1, &a_ways);
  bool b = numWays(syms, ops, nSyms-2, nOps-2, &b_ways);
  if (eval(a, ops[nOps-1], syms[nSyms-1])) {
    (*ways)++;
  }
  if (eval(b, ops[nOps-2], eval(syms[nSyms-2], syms[nSyms-1], ops[nOps-1]))) {
    (*ways)++;
  }
}

int main(int argc, const char *argv[])
{
  /* bool symbols[] = {true, false, true}; */
  /* char ops[] = {'^', '&'}; */
  /* bool symbols[] = {true, false, false}; */
  /* char ops[] = {'^', '|'}; */
  bool symbols[] = {true, true, false, false};
  char ops[] = {'|', '&', '^'};
  int nSyms = sizeof(symbols)/sizeof(symbols[0]);
  int nOps = sizeof(ops)/sizeof(ops[0]);

  int ways = 0;
  numWays(symbols, ops, nSyms, nOps, &ways);
  cout << ways << endl;
  return 0;
}
