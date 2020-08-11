#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(const char *msg) {
  fprintf(stderr, "[!] Error: %s\n", msg);
  exit(EXIT_FAILURE);
}

bool is_leap(int year) {
  return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    error("Expected 1 argument");
  }

  int result = atoi(argv[1]);
  if (is_leap(result)) {
    printf("leap year\n");
  } else {
    printf("normal year\n");
  }
  return EXIT_SUCCESS;
}
