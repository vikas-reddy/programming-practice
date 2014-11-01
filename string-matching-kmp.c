#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArray(int *arr, int len) {
  int i;
  for (i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void generateKmpPrefixes(char *pattern, int prefixes[]) {
  int patternLen = strlen(pattern);
  int i, len;
  prefixes[0] = 0;
  len = 0;
  for (i = 1; i < patternLen; ) {
    if (pattern[i] == pattern[len]) {
      len++;
      prefixes[i] = len;
      i++;
    }
    else {
      if (len != 0) {
        len = prefixes[len - 1];
      }
      else {
        prefixes[i] = 0;
        i++;
      }
    }
  }
}

void printKmpMatches(char *text, char *pattern, int *prefixes) {
  int textLen = strlen(text), patternLen = strlen(pattern);
  int textIdx = 0, patternIdx = 0;
  while (textIdx < textLen) {
    if (text[textIdx] == pattern[patternIdx]) {
      textIdx++;
      patternIdx++;
    }
    else {
      if (patternIdx == 0) {
        textIdx++;
      }
      else {
        patternIdx = prefixes[patternIdx - 1];
      }
    }
    if (patternIdx == patternLen) {
      // full match
      printf("%d\n", textIdx - patternIdx);
      patternIdx = prefixes[patternIdx - 1];
    }
  }
}

int main(int argc, char *argv[])
{
  char *pattern, *text;
  if (argc < 2) {
    printf("requires the pattern as argument\n");
    return 1;
  }
  pattern = argv[1];
  text = argv[2];

  int len = strlen(pattern);
  int prefixes[len];
  generateKmpPrefixes(pattern, prefixes);
  printArray(prefixes, len);
  printKmpMatches(text, pattern, prefixes);
  /* printf("%s:%lu\n", pattern, strlen(pattern)); */
  return 0;
}
