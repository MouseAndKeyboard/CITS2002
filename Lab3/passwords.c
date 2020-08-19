
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

bool is_safe(char *passwd) {
  int i = 0;
  int numbers = 0;
  int lowercase = 0;
  int uppercase = 0;
  while (passwd[i] != '\0') {
    char c = passwd[i];
    if (isupper(c)) {
      uppercase++;
    } else if (islower(c)) {
      lowercase++;
    } else if (isdigit(c)) {
      numbers++;
    }
    i++;
  }
  return uppercase >= 2 && lowercase >= 2 && numbers >= 2;
}

int my_strcmp(char *str_a, char *str_b) {
  int i = 0;
  while (true) {
    // this will only happen if they are the same string
    if (str_a[i] == '\0' && str_b[i] == '\0') {
      return 0;
    } else if (str_a[i] < str_b[i]) {
      return -1;
    } else if (str_a[i] > str_b[i]) {
      return 1;
    }

    i++;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Expected 2 arguments, got %i\n", argc - 1);
    exit(EXIT_FAILURE);
  }

  int length = my_strcmp(argv[1], argv[2]);
  printf("%i\n", length);
  exit(EXIT_SUCCESS);
}
