#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void int_to_numeral(int val) {
  while (val > 0) {
    if (val >= 1000) {
      val -= 1000;
      printf("M");
    } else if (val >= 500) {
      val -= 500;
      printf("D");
    } else if (val >= 100) {
      val -= 100;
      printf("C");
    } else if (val >= 50) {
      val -= 50;
      printf("L");
    } else if (val >= 10) {
      val -= 10;
      printf("X");
    } else if (val >= 5) {
      val -= 5;
      printf("V");
    } else if (val >= 1) {
      val -= 1;
      printf("I");
    }
  }
  return;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    puts("Expected at least 1 arguments");
    exit(EXIT_FAILURE);
  }

  int max_val = atoi(argv[1]);

  for (int i = 1; i < max_val + 1; i++) {
    int_to_numeral(i);
    printf("\n");
  }
}
