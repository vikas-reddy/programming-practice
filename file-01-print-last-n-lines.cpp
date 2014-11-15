#include<iostream>
#include<string>

using namespace std;

int main(int argc, const char *argv[])
{
  if (argc < 3) {
    cout << "Insufficient arguments given. Exiting!" << endl;
    return 1;
  }

  const char *filename = argv[1];
  int num = stoi(argv[2]);

  FILE *fp;

  fp = fopen(filename, "r");

  if (fp == NULL) {
    cout << "Error while opening '" << filename << "'. Exiting!" << endl;
    return 2;
  }
  
  char ch;
  int i = 0, status;

  // start from the last character
  fseek(fp, -2, SEEK_END);

  // And go backwards until we reach the 'num'th line from the bottom. This
  // loop will break with ch pointing to the last character, '\n', of (n + 1)th
  // line
  while ( (ch = fgetc(fp)) && (ch != EOF) && (i < num) ) {
    if (ch == '\n') {
      i++;
    }
    status = fseek(fp, -2, SEEK_CUR); 
    if (status) {
      break;
    }
  }

  // we will have a non-zero 'status' when we reach the beginning of the file
  // i.e., when the number of lines in the file is less than 'num'
  if (status) {
    fseek(fp, 0, SEEK_SET);
  }
  // Seek to the first character of the 'num'th line from bottom
  else {
    fseek(fp, 1, SEEK_CUR);
  }

  while ( (ch = fgetc(fp)) && (ch != EOF) ) {
    printf("%c", ch);
  }

  fclose(fp);
  return 0;
}
