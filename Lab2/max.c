#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(const char *msg) {
  fprintf(stderr, "[!] Error: %s\n", msg);
  exit(EXIT_FAILURE);
}

int max(int a, int b) { return (a >= b) * a + (a < b) * b; }

int main(int argc, char *argv[]) {
  if (argc != 4) {
    error("Expected 3 arguments");
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = atoi(argv[3]);

  printf("%i\n", max(max(a, b), c));
  return EXIT_SUCCESS;
}
