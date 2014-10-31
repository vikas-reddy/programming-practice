#include<stdio.h>

int length(char *str) {
  int i = 0;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}

int palindromes_count(char *str) {
  int len = length(str);
  int i, j, count = 1;
  for (i = 0, j = len - 1; i < j; i++, j--) {
    printf("%c %c\n", str[i], str[j]);
    if (str[i] == '?') {
      if (str[j] == '?') {
        count *= 26;
      }
    }
    else {
      if (str[j] != '?') {
        if (str[i] != str[j]) {
          return 0;
        }
      }
    }
  }

  // uneven number of chars
  if (i == j) {
    if (str[i] == '?') {
      count *= 26;
    }
  }
  return count;
}

int main() {
  char *str;
  scanf("%s", str);

  printf("%d\n", palindromes_count(str));
  /* printf("%s; len(%d)\n", str, length(str)); */
  return 0;
}
