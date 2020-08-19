
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

#define RAND_ARRY_N 10

void print_array(int *arry, int len) {
  for (int i = 0; i < len; i++) {
    printf("%i\n", arry[i]);
  }
}

int largest_elem(int *arry, int len) {
  if (len < 1) {
    fprintf(stderr, "No largest element of array length %i\n", len);
    exit(EXIT_FAILURE);
  }
  int max = arry[0];
  int max_i = 0;
  for (int i = 1; i < len; i++) {
    if (max < arry[i]) {
      max_i = i;
      max = arry[i];
    }
  }
  return max_i;
}

void move_to_start(int *arry, int len, int src) {
  if (src >= len || src < 0) {
    fprintf(stderr, "Source index of %i not in array of length %i\n", src, len);
    exit(EXIT_FAILURE);
  } else if (len < 1) {
    fprintf(stderr, "Array must have at least 1 element, got %i\n", len);
    exit(EXIT_FAILURE);
  }

  int new = arry[0];
  arry[0] = arry[src];
  for (int i = 1; i < src + 1; i++) {
    int new2 = arry[i];
    arry[i] = new;

    new = new2;
  }
}

void random_array() {
  // will have junk values
  int rand_arry[RAND_ARRY_N];
  srand(time(NULL));

  for (int i = 0; i < RAND_ARRY_N; i++) {
    rand_arry[i] = rand();
  }

  int max = largest_elem(rand_arry, RAND_ARRY_N);
  move_to_start(rand_arry, RAND_ARRY_N, max);
  print_array(rand_arry, RAND_ARRY_N);
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    fprintf(stderr, "Expected 0 arguments, got %i\n", argc - 1);
    exit(EXIT_FAILURE);
  }
  random_array();

  exit(EXIT_SUCCESS);
}
