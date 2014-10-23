#include <iostream>
#include <stdlib.h>

class Author {
  public:
    char *name;
}

class Publisher {
  public:
    char *publisher;
}

class Year {
  public:
    int data;
}

class Category {
  public:
    char *name;
}

class BooksCatalog {
  public:
    char *name;
    Author author;
    Publisher publisher;
    Year publishedIn;
    Category category;
    int price;
    int soldcount;
}

int main(int argc, char *argv[]) {
  return 0;
}
