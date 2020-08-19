
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Expected 1 argument, got %i\n", argc - 1);
    exit(EXIT_FAILURE);
  }

  int length = my_strlen(argv[1]);
  printf("%i\n", length);
  exit(EXIT_SUCCESS);
}
