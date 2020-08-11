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
  if (argc < 3) {
    error("Expected at least 2 arguments");
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int m = max(a, b);
  for (int i = 3; i < argc; i++) {
    m = max(m, atoi(argv[i]));
  }

  printf("%i\n", m);
  return EXIT_SUCCESS;
}
