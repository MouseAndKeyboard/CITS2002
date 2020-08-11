
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(const char *msg) {
  fprintf(stderr, "[!] Error: %s\n", msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    error("Expected 1 argument");
  }

  int len = (int)strlen(argv[1]);
  int s1 = 0;
  for (int i = len - 1; i >= 0; i = i - 2) {
    // Subtract '0' to get integer value
    s1 += argv[1][i] - '0';
  }
  int s2 = 0;
  for (int i = strlen(argv[1]) - 2; i <= 0; i = i - 2) {
    // Subtract '0' to get integer value
    int doubled = (argv[1][i] - '0') * 2;
    int tens = doubled / 10;
    int ones = doubled % 10;
    s2 += tens + ones;
  }

  if (s1 + s2 % 10 == 0) {
    puts("valid");
  } else {
    puts("invalid");
  }

  return EXIT_SUCCESS;
}
