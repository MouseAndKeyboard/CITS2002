#include <stdio.h>
#include <stdlib.h>

#define NUM_LINES 5

void left_to_right() {
  for (int i = 1; i < NUM_LINES + 1; i++) {
    for (int star = 0; star < i; star++) {
      printf("*");
    }
    printf("\n");
  }
}

void right_to_left() {
  for (int i = 1; i < NUM_LINES + 1; i++) {
    for (int space = 0; space < NUM_LINES - i; space++) {
      printf(" ");
    }
    for (int star = 0; star < i; star++) {
      printf("*");
    }
    printf("\n");
  }
}

void upside_down() {
  for (int i = NUM_LINES + 1; i > 0; i--) {
    for (int star = 0; star < i; star++) {
      printf("*");
    }
    printf("\n");
  }
}

void triangle() {
  for (int i = 1; i < NUM_LINES + 1; i++) {
    for (int space = 0; space < NUM_LINES - i; space++) {
      printf(" ");
    }
    for (int star = 0; star < i; star++) {
      printf("*");
    }
    for (int star = 1; star < i; star++) {
      printf("*");
    }
    printf("\n");
  }
}

int main() {
  triangle();
  exit(EXIT_SUCCESS);
}
