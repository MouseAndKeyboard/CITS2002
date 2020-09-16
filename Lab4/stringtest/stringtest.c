#include "arrays.h"
#include "pointers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_arr_strcat(void) {
  char dest[32];
  sprintf(dest, "hello");
  puts(arr_strcat(dest, " world"));
  int res = 0 != strcmp(dest, "hello world");
  return res;
}

int test_ptr_strcat(void) {
  char *dest = (char *)malloc(32);
  sprintf(dest, "hello");
  puts(ptr_strcat(dest, " world"));
  int res = 0 != strcmp(dest, "hello world");
  free(dest);
  return res;
}

int main(void) {
  if (test_arr_strcat()) {
    exit(EXIT_FAILURE);
  }
  if (test_ptr_strcat()) {
    exit(EXIT_FAILURE);
  }
}
