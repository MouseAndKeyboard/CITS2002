
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

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Expected 1 argument, got %i\n", argc - 1);
    exit(EXIT_FAILURE);
  }

  int length = is_safe(argv[1]);
  printf("%i\n", length);
  exit(EXIT_SUCCESS);
}
